#include "arduino_cli.h"

/**
 * Set output to a digital/analog pin
 */
void cmd_set(String *cmd, String *args) {
  // Make sure cmd parameter isn't null
  if(cmd == NULL) {
    Serial.println("ERROR: 1st param of cmd_set must not NULL");
    return;
  }
  
  // Show usage if there is no argument
  if(args == NULL) {
    help(cmd);
    return;
  }

  // Prepare variables
  String pinStr = "";
  String valueStr = "";

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
          valueStr += each;
        break;
      }
    }
  }

  // Abort if not enough argument
  if(argIndex < 1) {
    Serial.println("Missing required argument");
    Serial.println("");
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

  // Read and print the data
  if(pinStr.charAt(0) == 'A') {
    // CONDITION: Analog pin
    // Parse value string
    float value = valueStr.toFloat();
    if(value == 0 && valueStr != "0") {
      // CONDITION: Invalid value
      Serial.println("Pin ID \"" + pinStr + "\" is analog, so the value must number");
      Serial.println("");
      help(cmd);
      return;
    }
    
    // Write value
    pinMode(pin, OUTPUT);
    analogWrite(pin, value);
  } else {
    // CONDITION: Digital pin
    if(valueStr == "on") {
      pinMode(pin, OUTPUT);
      digitalWrite(pin, HIGH);
    } else if(valueStr == "off") {
      pinMode(pin, OUTPUT);
      digitalWrite(pin, LOW);
    } else {
      // CONDITION: Invalid value
      Serial.println("Pin ID \"" + pinStr + "\" is digital, so the value must either on or off");
      Serial.println("");
      help(cmd);
      return;
    }
  }

  // Print response
  Serial.println("ok");
  Serial.println("");
}
