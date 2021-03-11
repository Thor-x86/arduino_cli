#include "arduino_cli.h"

/**
 * Listen for another Serial Port
 */
void cmd_listen(String *cmd, String *args) {
  // Make sure cmd parameter isn't null
  if(cmd == NULL) {
    Serial.println("ERROR: 1st param of cmd_get must not NULL");
    return;
  }
  
  // Show usage if there is no argument
  if(args == NULL) {
    help(cmd);
    return;
  }

  // Prepare variables
  String baudrateStr = "";
  bool hasBaudrateStr = false;
  for(int i = 0; i < args->length(); i++) {
    char each = args->charAt(i);
    if(each == ' ') {
      if(hasBaudrateStr) {
        Serial.println("Excessive arguments");
        Serial.println("");
        help(cmd);
        return;
      } else {
        hasBaudrateStr = true;
      }
    } else if(!hasBaudrateStr) {
      baudrateStr += each;
    }
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

  // Listen from second serial port
  while(true) {
    int n = Serial1.available();
    for(int i = 0; i < n; i++) {
      Serial.write(Serial1.read());
    }
    if(n > 0) {
      Serial.flush();
    }

    // Stop loop on hit enter
    if(Serial.available() > 0) break;
  }

  // Disconnect second serial port
  Serial1.end();

  // Print "stopped"
  Serial.println("");
  Serial.println("[Stopped]");
  Serial.println("");

  // Serial buffer cleanup
  int n = Serial.available();
  for(int i = 0; i < n; i++) {
    Serial.read();
  }
}
