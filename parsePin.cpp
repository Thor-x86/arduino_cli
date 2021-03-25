#include "arduino_cli.h"

byte parsePin(String *pinStr)
{
  if (pinStr == NULL)
  {
    Serial.println("ERROR: cannot parse NULL pin");
    return PIN_INVALID;
  }

  byte pin = pinStr->toInt();
  if (pin == 0 && *pinStr != "0")
  {
    // CONDITION: Non-numeric PIN ID

    if (*pinStr == "")
    {
      // Just in case A0 isn't available for targeted board
      return PIN_INVALID;
    }

#ifdef PIN_A0
    else if (*pinStr == "A0")
    {
      return PIN_A0;
    }
#endif

#ifdef PIN_A1
    else if (*pinStr == "A1")
    {
      return PIN_A1;
    }
#endif

#ifdef PIN_A2
    else if (*pinStr == "A2")
    {
      return PIN_A2;
    }
#endif

#ifdef PIN_A3
    else if (*pinStr == "A3")
    {
      return PIN_A3;
    }
#endif

#ifdef PIN_A4
    else if (*pinStr == "A4")
    {
      return PIN_A4;
    }
#endif

#ifdef PIN_A5
    else if (*pinStr == "A5")
    {
      return PIN_A5;
    }
#endif

#ifdef PIN_A6
    else if (*pinStr == "A6")
    {
      return PIN_A6;
    }
#endif

#ifdef PIN_A7
    else if (*pinStr == "A7")
    {
      return PIN_A7;
    }
#endif

#ifdef PIN_A8
    else if (*pinStr == "A8")
    {
      return PIN_A8;
    }
#endif

#ifdef PIN_A9
    else if (*pinStr == "A9")
    {
      return PIN_A9;
    }
#endif

#ifdef PIN_A10
    else if (*pinStr == "A10")
    {
      return PIN_A10;
    }
#endif

#ifdef PIN_A11
    else if (*pinStr == "A11")
    {
      return PIN_A11;
    }
#endif

#ifdef PIN_A12
    else if (*pinStr == "A12")
    {
      return PIN_A12;
    }
#endif

#ifdef PIN_A13
    else if (*pinStr == "A13")
    {
      return PIN_A13;
    }
#endif

#ifdef PIN_A14
    else if (*pinStr == "A14")
    {
      return PIN_A14;
    }
#endif

#ifdef PIN_A15
    else if (*pinStr == "A15")
    {
      return PIN_A15;
    }
#endif

#ifdef PIN_A16
    else if (*pinStr == "A16")
    {
      return PIN_A16;
    }
#endif

#ifdef PIN_A17
    else if (*pinStr == "A17")
    {
      return PIN_A17;
    }
#endif

#ifdef PIN_A18
    else if (*pinStr == "A18")
    {
      return PIN_A18;
    }
#endif

#ifdef PIN_A19
    else if (*pinStr == "A19")
    {
      return PIN_A19;
    }
#endif

#ifdef PIN_A20
    else if (*pinStr == "A20")
    {
      return PIN_A20;
    }
#endif

#ifdef PIN_A21
    else if (*pinStr == "A21")
    {
      return PIN_A21;
    }
#endif

#ifdef PIN_A22
    else if (*pinStr == "A22")
    {
      return PIN_A22;
    }
#endif

#ifdef PIN_A23
    else if (*pinStr == "A23")
    {
      return PIN_A23;
    }
#endif

#ifdef PA1
    else if (*pinStr == "PA1")
    {
      return PA1;
    }
#endif

#ifdef PA2
    else if (*pinStr == "PA2")
    {
      return PA2;
    }
#endif

#ifdef PA3
    else if (*pinStr == "PA3")
    {
      return PA3;
    }
#endif

#ifdef PA4
    else if (*pinStr == "PA4")
    {
      return PA4;
    }
#endif

#ifdef PA5
    else if (*pinStr == "PA5")
    {
      return PA5;
    }
#endif

#ifdef PA6
    else if (*pinStr == "PA6")
    {
      return PA6;
    }
#endif

#ifdef PA7
    else if (*pinStr == "PA7")
    {
      return PA7;
    }
#endif

#ifdef PA8
    else if (*pinStr == "PA8")
    {
      return PA8;
    }
#endif

#ifdef PA9
    else if (*pinStr == "PA9")
    {
      return PA9;
    }
#endif

#ifdef PA10
    else if (*pinStr == "PA10")
    {
      return PA10;
    }
#endif

#ifdef PA11
    else if (*pinStr == "PA11")
    {
      return PA11;
    }
#endif

#ifdef PA12
    else if (*pinStr == "PA12")
    {
      return PA12;
    }
#endif

#ifdef PA13
    else if (*pinStr == "PA13")
    {
      return PA13;
    }
#endif

#ifdef PA14
    else if (*pinStr == "PA14")
    {
      return PA14;
    }
#endif

#ifdef PA15
    else if (*pinStr == "PA15")
    {
      return PA15;
    }
#endif

#ifdef PB1
    else if (*pinStr == "PB1")
    {
      return PB1;
    }
#endif

#ifdef PB2
    else if (*pinStr == "PB2")
    {
      return PB2;
    }
#endif

#ifdef PB3
    else if (*pinStr == "PB3")
    {
      return PB3;
    }
#endif

#ifdef PB4
    else if (*pinStr == "PB4")
    {
      return PB4;
    }
#endif

#ifdef PB5
    else if (*pinStr == "PB5")
    {
      return PB5;
    }
#endif

#ifdef PB6
    else if (*pinStr == "PB6")
    {
      return PB6;
    }
#endif

#ifdef PB7
    else if (*pinStr == "PB7")
    {
      return PB7;
    }
#endif

#ifdef PB8
    else if (*pinStr == "PB8")
    {
      return PB8;
    }
#endif

#ifdef PB9
    else if (*pinStr == "PB9")
    {
      return PB9;
    }
#endif

#ifdef PB10
    else if (*pinStr == "PB10")
    {
      return PB10;
    }
#endif

#ifdef PB11
    else if (*pinStr == "PB11")
    {
      return PB11;
    }
#endif

#ifdef PB12
    else if (*pinStr == "PB12")
    {
      return PB12;
    }
#endif

#ifdef PB13
    else if (*pinStr == "PB13")
    {
      return PB13;
    }
#endif

#ifdef PB14
    else if (*pinStr == "PB14")
    {
      return PB14;
    }
#endif

#ifdef PB15
    else if (*pinStr == "PB15")
    {
      return PB15;
    }
#endif

#ifdef PC1
    else if (*pinStr == "PC1")
    {
      return PC1;
    }
#endif

#ifdef PC2
    else if (*pinStr == "PC2")
    {
      return PC2;
    }
#endif

#ifdef PC3
    else if (*pinStr == "PC3")
    {
      return PC3;
    }
#endif

#ifdef PC4
    else if (*pinStr == "PC4")
    {
      return PC4;
    }
#endif

#ifdef PC5
    else if (*pinStr == "PC5")
    {
      return PC5;
    }
#endif

#ifdef PC6
    else if (*pinStr == "PC6")
    {
      return PC6;
    }
#endif

#ifdef PC7
    else if (*pinStr == "PC7")
    {
      return PC7;
    }
#endif

#ifdef PC8
    else if (*pinStr == "PC8")
    {
      return PC8;
    }
#endif

#ifdef PC9
    else if (*pinStr == "PC9")
    {
      return PC9;
    }
#endif

#ifdef PC10
    else if (*pinStr == "PC10")
    {
      return PC10;
    }
#endif

#ifdef PC11
    else if (*pinStr == "PC11")
    {
      return PC11;
    }
#endif

#ifdef PC12
    else if (*pinStr == "PC12")
    {
      return PC12;
    }
#endif

#ifdef PC13
    else if (*pinStr == "PC13")
    {
      return PC13;
    }
#endif

#ifdef PC14
    else if (*pinStr == "PC14")
    {
      return PC14;
    }
#endif

#ifdef PC15
    else if (*pinStr == "PC15")
    {
      return PC15;
    }
#endif

#ifdef PD1
    else if (*pinStr == "PD1")
    {
      return PD1;
    }
#endif

#ifdef PD2
    else if (*pinStr == "PD2")
    {
      return PD2;
    }
#endif

#ifdef PD3
    else if (*pinStr == "PD3")
    {
      return PD3;
    }
#endif

#ifdef PD4
    else if (*pinStr == "PD4")
    {
      return PD4;
    }
#endif

#ifdef PD5
    else if (*pinStr == "PD5")
    {
      return PD5;
    }
#endif

#ifdef PD6
    else if (*pinStr == "PD6")
    {
      return PD6;
    }
#endif

#ifdef PD7
    else if (*pinStr == "PD7")
    {
      return PD7;
    }
#endif

#ifdef PD8
    else if (*pinStr == "PD8")
    {
      return PD8;
    }
#endif

#ifdef PD9
    else if (*pinStr == "PD9")
    {
      return PD9;
    }
#endif

#ifdef PD10
    else if (*pinStr == "PD10")
    {
      return PD10;
    }
#endif

#ifdef PD11
    else if (*pinStr == "PD11")
    {
      return PD11;
    }
#endif

#ifdef PD12
    else if (*pinStr == "PD12")
    {
      return PD12;
    }
#endif

#ifdef PD13
    else if (*pinStr == "PD13")
    {
      return PD13;
    }
#endif

#ifdef PD14
    else if (*pinStr == "PD14")
    {
      return PD14;
    }
#endif

#ifdef PD15
    else if (*pinStr == "PD15")
    {
      return PD15;
    }
#endif

    // CONDITION: Non-numeric PIN ID but not supported
    return PIN_INVALID;
  }
  else
  {
    // CONDITION: Numeric PIN ID
    return pin;
  }
}
