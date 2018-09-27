#include "PS2X_lib.h"  //for v1.6

/******************************************************************
   set pins connected to PS2 controller:
     - 1e column: original
     - 2e colmun: Stef?
   replace pin numbers by the ones you use
 ******************************************************************/
#define PS2_DAT      8
#define PS2_CMD      9
#define PS2_CS       10
#define PS2_CLK      11

/******************************************************************
   select modes of PS2 controller:
     - pressures = analog reading of push-butttons
     - rumble    = motor rumbling
   uncomment 1 of the lines for each mode selection
 ******************************************************************/
#define pressures   true
#define rumble      true

PS2X ps2x; // create PS2 Controller Class

void setup() {
  Serial.begin(57600);

  /*right now, the library does NOT support hot pluggable controllers, meaning
    you must always either restart your Arduino after you connect the controller,
    or call config_gamepad(pins) again after connecting the controller.*/
  //setup pins and settings: GamePad(clock, command, attention, data, Pressures?, Rumble?) check for error
  int error = 0;
  do {
    error = ps2x.config_gamepad(PS2_CLK, PS2_CMD, PS2_CS, PS2_DAT, pressures, rumble);
    if (error == 0) {
      break;
    } else {
      delay(100);
    }
  } while (1);
}

void loop() {
  ps2x.read_gamepad(false, 0); //read controller and set large motor to spin at 'vibrate' speed

  if (ps2x.Button(PSB_START))        //will be TRUE as long as button is pressed
    Serial.println("Start is being held");
  if (ps2x.Button(PSB_SELECT))
    Serial.println("Select is being held");

  if (ps2x.Button(PSB_PAD_UP)) {     //will be TRUE as long as button is pressed
    Serial.println("Up held this hard: ");
  } else if (ps2x.ButtonReleased(PSB_PAD_UP))  {
    Serial.println("Up Button Released!");
  }
  if (ps2x.Button(PSB_PAD_DOWN)) {
    Serial.println("DOWN held this hard: ");
  }
  if (ps2x.Button(PSB_PAD_RIGHT)) {
    Serial.println("Right held this hard: ");
  }
  if (ps2x.Button(PSB_PAD_LEFT)) {
    Serial.println("LEFT held this hard: ");
  }


  if (ps2x.Button(PSB_L2))
    Serial.println("L2 pressed");
  if (ps2x.Button(PSB_R2))
    Serial.println("R2 pressed");
    
  if (ps2x.Button(PSB_TRIANGLE))
    Serial.println("Triangle pressed");
  if (ps2x.ButtonPressed(PSB_CIRCLE))              //will be TRUE if button was JUST pressed
    Serial.println("Circle just pressed");
  if (ps2x.ButtonPressed(PSB_CROSS)) {             //will be TRUE if button was JUST pressed OR released
    Serial.println("X just pressed");
  }
  if (ps2x.ButtonReleased(PSB_SQUARE))             //will be TRUE if button was JUST released
    Serial.println("Square just released");

  if (ps2x.Button(PSB_L1) || ps2x.Button(PSB_R1)) { //print stick values if either is TRUE
    Serial.print("Stick Values:");
    Serial.print(ps2x.Analog(PSS_LY), DEC); //Left stick, Y axis. Other options: LX, RY, RX
    Serial.print(",");
    Serial.print(ps2x.Analog(PSS_LX), DEC);
    Serial.print(",");
    Serial.print(ps2x.Analog(PSS_RY), DEC);
    Serial.print(",");
    Serial.println(ps2x.Analog(PSS_RX), DEC);
  }
  delay(30);
}
