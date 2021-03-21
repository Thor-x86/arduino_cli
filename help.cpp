#include "arduino_cli.h"

/**
 * Display general or command-specific help
 */
void help(String *cmdPtr) {
  if(cmdPtr == NULL) {
    // CONDITION: Command name isn't specified
    Serial.println("Available Commands:");
    Serial.println("get ----- Get input from a digital/analog pin");
    Serial.println("set ----- Set output to a digital/analog pin");
    Serial.println("tail ---- Keep reading input from digital/analog pin");
    #ifdef HAVE_HWSERIAL1
      // Only for boards with multiple Serial HW
      Serial.println("send ---- Send data to another Serial Port");
      Serial.println("listen -- Listen for another Serial Port");
    #endif
    Serial.println("help ---- Show information about available commands");
    Serial.println("");
    Serial.println("Run this command for details: help <command_name>");
    Serial.println("");
  } else {
    // CONDITION: Command name specified
    // Get only command name
    String cmd = "";
    for(int i = 0; i < cmdPtr->length(); i++) {
      char eachChar = cmdPtr->charAt(i);
      if(eachChar == ' ') break;
      cmd += eachChar;
    }

    // Parse command name
    if(cmd == "get") {
      Serial.println("USAGE: get <pin_ID>");
      Serial.println("");
    } else if(cmd == "set") {
      Serial.println("USAGE: set <pin_ID> <on|off|number_values>");
      Serial.println("");
    } else if(cmd == "tail") {
      Serial.println("USAGE: tail <pin_ID> [interval_ms]");
      Serial.println("");
      Serial.println("Default:");
      Serial.println("    interval_ms = 500");
      Serial.println("");
      Serial.println("NOTE: Hit enter to stop listening");
      Serial.println("");
    }
    #ifdef HAVE_HWSERIAL1
      // Only for boards with multiple Serial HW
      else if(cmd == "send") {
        Serial.println("USAGE: send <message> [baudrate]");
        Serial.println("");
        Serial.println("Default:");
        Serial.println("    baudrate = 115200");
        Serial.println("");
        Serial.println("Examples:");
        Serial.println("    send hello");
        Serial.println("    send \"hello, world!\"");
        Serial.println("    send \"first line\\nsecond line\"");
        Serial.println("    send 132");
        Serial.println("    send 0b10011011");
        Serial.println("    send 0x7f");
        Serial.println("    send hello 9600");
        Serial.println("    send \"hello, world!\" 9600");
        Serial.println("");
      } else if(cmd == "listen") {
        Serial.println("USAGE: listen [baudrate]");
        Serial.println("");
        Serial.println("Default:");
        Serial.println("    baudrate = 115200");
        Serial.println("");
        Serial.println("NOTE: Hit enter to stop listening");
        Serial.println("");
      }
    #endif
    else if(cmd == "help") {
      help();
    } else {
      Serial.println("Command \"" + cmd + "\" not found");
      Serial.println("");
      help();
    }
  }
}
