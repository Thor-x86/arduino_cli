#include "arduino_cli.h"

/**
 * Run a command
 */
void execute(String *cmdName, String *cmdValues) {
  if(cmdName == NULL) {
    help();
  } else if(*cmdName == "get") {
    cmd_get(cmdName, cmdValues);
  } else if(*cmdName == "set") {
    cmd_set(cmdName, cmdValues);
  } else if(*cmdName == "tail") {
    cmd_tail(cmdName, cmdValues);
  }
  
  // Only for boards with multiple Serial HW
  #ifdef HAVE_HWSERIAL1
    else if(*cmdName == "send") {
      cmd_send(cmdName, cmdValues);
    } else if(*cmdName == "listen") {
      cmd_listen(cmdName, cmdValues);
    }
  #endif
  
  else if(*cmdName == "help") {
    if(cmdValues->length() > 0) {
      help(cmdValues);
    } else {
      help();
    }
  } else if(*cmdName == "") {
    // Do nothing
  } else {
    help(cmdName);
  }
}
