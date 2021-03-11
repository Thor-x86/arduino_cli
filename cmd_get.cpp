#include "arduino_cli.h"

/**
 * Get input from a digital/analog pin
 */
void cmd_get(String *cmd, String *args) {
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
  String pinStr = "";
  bool hasPinStr = false;
  for(int i = 0; i < args->length(); i++) {
    char each = args->charAt(i);
    if(each == ' ') {
      if(hasPinStr) {
        Serial.println("Excessive arguments");
        Serial.println("");
        help(cmd);
        return;
      } else {
        hasPinStr = true;
      }
    } else if(!hasPinStr) {
      pinStr += each;
    }
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

  // Set pin role
  pinMode(pin, INPUT);

  // Read and print the data
  if(pinStr.charAt(0) == 'A') {
    // CONDITION: Analog pin
    Serial.println(analogRead(pin));
  } else {
    // CONDITION: Digital pin
    Serial.println(digitalRead(pin));
  }
  Serial.println("");
}
