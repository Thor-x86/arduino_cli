#include "arduino_cli.h"

#ifdef HAVE_HWSERIAL1
/**
 * Send data to another Serial Port
 */
void cmd_send(String *cmd, String *args) {
  // Make sure cmd parameter isn't null
  if(cmd == NULL) {
    Serial.println("ERROR: 1st param of cmd_tail must not NULL");
    return;
  }
  
  // Show usage if there is no argument
  if(args == NULL) {
    help(cmd);
    return;
  }

  // Prepare variables
  String messageStr = "";
  String baudrateStr = "";

  // Tokenize arguments
  byte argIndex = 0;
  bool isInQuote = false;
  bool isEscaping = false;
  for(byte i = 0; i < args->length(); i++) {
    char each = args->charAt(i);
    if(each == '"' && !isEscaping) {
      isInQuote = !isInQuote;
    } else if(each == '\\' && isInQuote && !isEscaping) {
      isEscaping = true;
      continue;
    } else if(each == ' ' && !isInQuote) {
      if(argIndex >= 1) {
        Serial.println("Excessive arguments");
        Serial.println("");
        help(cmd);
        return;
      } else {
        argIndex++;
      }
    } else {
      if(isEscaping) {
        if(each == 'n') {
          each = '\n';
        } else if(each == 'r') {
          each = '\r';
        } else if(each == 't') {
          each = '\t';
        }
      }
      switch(argIndex) {
        case 0:
          messageStr += each;
        break;
        case 1:
          baudrateStr += each;
        break;
      }
    }
    isEscaping = false;
  }

  // Abort if not enough argument
  if(args->length() <= 0) {
    help(cmd);
    return;
  }

  // Show error on unclosed quote
  if(isInQuote) {
    Serial.println("ERROR: Unclosed quote (\")");
    Serial.println("");
    return;
  }

  // Parse baudrate
  int baudrate = baudrateStr.toInt();
  if(baudrate <= 0) {
    if(baudrateStr.length() > 0) {
      // CONDITION: Baudrate is invalid
      Serial.println("Baudrate must number and more than 0");
      Serial.println("");
      help(cmd);
      return;
    } else {
      // CONDITION: Baudrate is not specified, fallback to default
      baudrate = 115200;
    }
  }

  // Initialize second serial port
  Serial1.begin(baudrate);
  byte countdown = 10;
  while(!Serial1) {
    delay(1000);

    // Cleanup first serial, just in case accidental input
    int n = Serial.available();
    for(int i = 0; i < n; i++) {
      Serial.read();
    }
    
    if(countdown > 0) {
      countdown--;
    } else {
      Serial.println("Cannot connect to 2nd Serial Port");
      Serial.println("");
      return;
    }
  }

  // Send message based on data type
  if(args->charAt(0) == '"') {
    // CONDITION: Message enforced as string
    Serial1.print(messageStr);
  } else if(messageStr.length() > 1 && messageStr.charAt(0) == '0') {
    // CONDITION: Message is raw bytes
    String prefix = messageStr.substring(0,2);
    byte radix = 0;
    if(prefix == "0b") {
      radix = 2;
    } else if(prefix == "0o") {
      radix = 8;
    } else if(prefix == "0d") {
      radix = 10;
    } else if(prefix == "0x") {
      radix = 16;
    }
    
    long long messageBytes;
    if(radix > 0) {
      messageBytes = strtol(&messageStr[2], NULL, radix);
    } else {
      messageBytes = strtol(&messageStr[0], NULL, 0);
    }
    
    Serial1.write((byte)(messageBytes & 0xff));
    if(messageBytes < 0 || messageBytes > 0xff) {
      Serial1.write((byte)((messageBytes >> 8) & 0xff));
    }
    if(messageBytes < 0 || messageBytes > 0xffff) {
      Serial1.write((byte)((messageBytes >> 16) & 0xff));
    }
    if(messageBytes < 0 || messageBytes > 0xffffff) {
      Serial1.write((byte)((messageBytes >> 24) & 0xff));
    }
    if(messageBytes < 0 || messageBytes > 0xffffffff) {
      Serial1.write((byte)((messageBytes >> 32) & 0xff));
    }
    if(messageBytes < 0 || messageBytes > 0xffffffffff) {
      Serial1.write((byte)((messageBytes >> 40) & 0xff));
    }
    if(messageBytes < 0 || messageBytes > 0xffffffffffff) {
      Serial1.write((byte)((messageBytes >> 48) & 0xff));
    }
    if(messageBytes < 0 || messageBytes > 0xffffffffffffff) {
      Serial1.write((byte)((messageBytes >> 56) & 0xff));
    }
    if(messageBytes < 0 || messageBytes > 0xffffffffffffffff) {
      Serial1.write((byte)((messageBytes >> 64) & 0xff));
    }
    Serial1.flush();
  } else {
    // CONDITION: Message is either number or plain string
    Serial1.print(messageStr);
  }

  // Disconnect second serial port
  Serial1.end();
  
  // Print response
  Serial.println("ok");
  Serial.println("");
}
#endif