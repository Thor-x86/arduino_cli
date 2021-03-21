#include <Arduino.h>

#define PIN_INVALID 0xff

extern void help(String *cmdPtr = NULL);
extern byte parsePin(String *pinStr);
extern void cmd_get(String *cmd, String *args);
extern void cmd_set(String *cmd, String *args);
extern void cmd_tail(String *cmd, String *args);
#ifdef HAVE_HWSERIAL1
  // Only for boards with multiple Serial HW
  extern void cmd_send(String *cmd, String *args);
  extern void cmd_listen(String *cmd, String *args);
#endif
extern void execute(String *cmdName, String *cmdValues);
