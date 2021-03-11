/**
 * Arduino CLI for I/O Testing
 * or PC program <=> Arduino communication
 * 
 * By: Athaariq Ardhiansyah
**/

#include "arduino_cli.h"

void setup() {
  // Initialize Serial
  Serial.begin(115200);

  // Blink LED if serial not connected
  bool isLit = false;
  pinMode(LED_BUILTIN, OUTPUT);
  while (!Serial) {
    if(isLit) {
      digitalWrite(LED_BUILTIN, LOW);
    } else {
      digitalWrite(LED_BUILTIN, HIGH);
    }
    isLit = !isLit;
    delay(500);
  }
  digitalWrite(LED_BUILTIN, HIGH);

  // Welcome screen
  Serial.println("Welcome to Arduino CLI!");
  Serial.println("Enter \"help\" for information");
  Serial.println("");
  Serial.println("Another projects: https://github.com/Thor-x86");
  Serial.println("");
}

void loop() {
  // Get char length
  int n = Serial.available();
  
  // Parse command if available
  if (n > 0) {
    // Lit the LED to indicate working
    digitalWrite(LED_BUILTIN, LOW);

    // Prepare variables
    bool isReadCommand = true;
    String commandName = "";
    String commandValue = "";
    
    // Print and resolve name+value
    Serial.print("> ");
    for(int i = 0; i < n; i++) {
      char currentChar = (char)Serial.read();
      Serial.print(currentChar);
      if(currentChar == '\n' || currentChar == '\r') {
        continue;
      } else if(currentChar == ' ' && isReadCommand) {
        isReadCommand = false;
      } else if(isReadCommand) {
        commandName += currentChar;
      } else {
        commandValue += currentChar;
      }
    }

    // Execute the command
    execute(&commandName, &commandValue);

    // Unlit the LED to indicate job done
    digitalWrite(LED_BUILTIN, HIGH);
  }
}
