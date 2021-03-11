#include "arduino_cli.h"

byte parsePin(String *pinStr) {
  if(pinStr == NULL) {
    Serial.println("ERROR: cannot parse NULL pin");
    return PIN_INVALID;
  }
  
  byte pin = pinStr->toInt();
  if(pin == 0 && *pinStr != "0") {
    // CONDITION: Non-numeric PIN ID
    if(*pinStr == "A0") {
      return A0;
    } else if(*pinStr == "A1") {
      return A1;
    } else if(*pinStr == "A2") {
      return A2;
    } else if(*pinStr == "A3") {
      return A3;
    } else if(*pinStr == "A4") {
      return A4;
    } else if(*pinStr == "A5") {
      return A5;
    } else if(*pinStr == "A6") {
      return A6;
    } else if(*pinStr == "A7") {
      return A7;
    } else if(*pinStr == "A8") {
      return A8;
    } else if(*pinStr == "A9") {
      return A9;
    } 
    #ifdef A10
    else if(*pinStr == "A10") {
      return A10;
    } else if(*pinStr == "A11") {
      return A11;
    } else if(*pinStr == "A12") {
      return A12;
    } else if(*pinStr == "A13") {
      return A13;
    } else if(*pinStr == "A14") {
      return A14;
    } else if(*pinStr == "A15") {
      return A15;
    } else if(*pinStr == "A16") {
      return A16;
    } else if(*pinStr == "A17") {
      return A17;
    } else if(*pinStr == "A18") {
      return A18;
    } else if(*pinStr == "A19") {
      return A19;
    } else if(*pinStr == "A20") {
      return A20;
    } else if(*pinStr == "A21") {
      return A21;
    } else if(*pinStr == "A22") {
      return A22;
    } else if(*pinStr == "A23") {
      return A23;
    }
    #endif
    else if(*pinStr == "PA1") {
      return PA_1;
    } else if(*pinStr == "PA2") {
      return PA_2;
    } else if(*pinStr == "PA3") {
      return PA_3;
    } else if(*pinStr == "PA4") {
      return PA_4;
    } else if(*pinStr == "PA5") {
      return PA_5;
    } else if(*pinStr == "PA6") {
      return PA_6;
    } else if(*pinStr == "PA7") {
      return PA_7;
    } else if(*pinStr == "PA8") {
      return PA_8;
    } else if(*pinStr == "PA9") {
      return PA_9;
    } else if(*pinStr == "PA10") {
      return PA_10;
    } else if(*pinStr == "PA11") {
      return PA_11;
    } else if(*pinStr == "PA12") {
      return PA_12;
    } else if(*pinStr == "PA13") {
      return PA_13;
    } else if(*pinStr == "PA14") {
      return PA_14;
    } else if(*pinStr == "PA15") {
      return PA_15;
    } else if(*pinStr == "PB1") {
      return PB_1;
    } else if(*pinStr == "PB2") {
      return PB_2;
    } else if(*pinStr == "PB3") {
      return PB_3;
    } else if(*pinStr == "PB4") {
      return PB_4;
    } else if(*pinStr == "PB5") {
      return PB_5;
    } else if(*pinStr == "PB6") {
      return PB_6;
    } else if(*pinStr == "PB7") {
      return PB_7;
    } else if(*pinStr == "PB8") {
      return PB_8;
    } else if(*pinStr == "PB9") {
      return PB_9;
    } else if(*pinStr == "PB10") {
      return PB_10;
    } else if(*pinStr == "PB11") {
      return PB_11;
    } else if(*pinStr == "PB12") {
      return PB_12;
    } else if(*pinStr == "PB13") {
      return PB_13;
    } else if(*pinStr == "PB14") {
      return PB_14;
    } else if(*pinStr == "PB15") {
      return PB_15;
    } else if(*pinStr == "PC1") {
      return PC_1;
    } else if(*pinStr == "PC2") {
      return PC_2;
    } else if(*pinStr == "PC3") {
      return PC_3;
    } else if(*pinStr == "PC4") {
      return PC_4;
    } else if(*pinStr == "PC5") {
      return PC_5;
    } else if(*pinStr == "PC6") {
      return PC_6;
    } else if(*pinStr == "PC7") {
      return PC_7;
    } else if(*pinStr == "PC8") {
      return PC_8;
    } else if(*pinStr == "PC9") {
      return PC_9;
    } else if(*pinStr == "PC10") {
      return PC_10;
    } else if(*pinStr == "PC11") {
      return PC_11;
    } else if(*pinStr == "PC12") {
      return PC_12;
    } else if(*pinStr == "PC13") {
      return PC_13;
    } else if(*pinStr == "PC14") {
      return PC_14;
    } else if(*pinStr == "PC15") {
      return PC_15;
    } else if(*pinStr == "PD1") {
      return PD_1;
    } else if(*pinStr == "PD2") {
      return PD_2;
    } else if(*pinStr == "PD3") {
      return PD_3;
    } else if(*pinStr == "PD4") {
      return PD_4;
    } else if(*pinStr == "PD5") {
      return PD_5;
    } else if(*pinStr == "PD6") {
      return PD_6;
    } else if(*pinStr == "PD7") {
      return PD_7;
    } else if(*pinStr == "PD8") {
      return PD_8;
    } else if(*pinStr == "PD9") {
      return PD_9;
    } else if(*pinStr == "PD10") {
      return PD_10;
    } else if(*pinStr == "PD11") {
      return PD_11;
    } else if(*pinStr == "PD12") {
      return PD_12;
    } else if(*pinStr == "PD13") {
      return PD_13;
    } else if(*pinStr == "PD14") {
      return PD_14;
    } else if(*pinStr == "PD15") {
      return PD_15;
    } else {
      return PIN_INVALID;
    }
  } else {
    // CONDITION: Numeric PIN ID
    return pin;
  }
}
