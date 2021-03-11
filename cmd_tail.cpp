#include "arduino_cli.h"

/**
 * Keep reading input from digital/analog pin
 */
void cmd_tail(String *cmd, String *args) {
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
  String pinStr = "";
  String intervalStr = "";

  // Tokenize arguments
  byte argIndex = 0;
  for(byte i = 0; i < args->length(); i++) {
    char each = args->charAt(i);
    if(each == ' ') {
      if(argIndex >= 1) {
        Serial.println("Excessive arguments");
        Serial.println("");
        help(cmd);
        return;
      } else {
        argIndex++;
      }
    } else {
      switch(argIndex) {
        case 0:
          pinStr += each;
        break;
        case 1:
          intervalStr += each;
        break;
      }
    }
  }

  // Abort if not enough argument
  if(args->length() <= 0) {
    help(cmd);
    return;
  }

  // Parse pin string
  byte pin = parsePin(&pinStr);
  if(pin == PIN_INVALID) {
    // CONDITION: Invalid Pin ID
    Serial.println("Pin ID \"" + pinStr + "\" is not valid");
    Serial.println("");
    help(cmd);
    return;
  }

  // Parse interval
  unsigned int interval = intervalStr.toInt();
  if(interval == 0) {
    if(intervalStr.length() > 0) {
      // CONDITION: interval_ms is invalid
      Serial.println("interval_ms must number, not \"" + intervalStr + "\"");
      Serial.println("");
      help(cmd);
      return;
    } else {
      // CONDITION: interval_ms is not specified, fallback to default
      interval = 500;
    }
  }

  // Set pin role
  pinMode(pin, INPUT);

  // Read and print the data
  if(pinStr.charAt(0) == 'A') {
    // CONDITION: Analog pin
    while(true) {
      Serial.println(analogRead(pin));
      delay(interval);
      if(Serial.available() > 0) break;
    }
  } else {
    // CONDITION: Digital pin
    while(true) {
      Serial.println(digitalRead(pin));
      delay(interval);
      if(Serial.available() > 0) break;
    }
  }
  Serial.println("");
  Serial.println("[Stopped]");
  Serial.println("");

  // Serial buffer cleanup
  int n = Serial.available();
  for(int i = 0; i < n; i++) {
    Serial.read();
  }
}
