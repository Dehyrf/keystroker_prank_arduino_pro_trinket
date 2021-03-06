//Presses backspace then space every 30 seconds, by Dehyrf for your amusement under GNU GPL v3
//To turn on, connect a wire between gnd and digital 4. To turn off/reprogram, disconnect wire.


int setTime = 30; //Change to change delay (seconds)
const int buttonPin = 4;          // input pin for pushbutton
int counter = 0;                  // button push counter
#include <ProTrinketKeyboard.h>

void setup() {
  // make the pushButton pin an input:
  pinMode(buttonPin, INPUT_PULLUP);
  // initialize control over the keyboard:
  TrinketKeyboard.begin();
}

void loop() {
  // read the pushbutton:
  int buttonState = digitalRead(buttonPin);
  TrinketKeyboard.poll();
  
  if (buttonState == LOW) {
    TrinketKeyboard.poll();
    TrinketKeyboard.pressKey(0, KEYCODE_BACKSPACE);
    TrinketKeyboard.pressKey(0, 0);
    TrinketKeyboard.pressKey(0, KEYCODE_SPACE);
    TrinketKeyboard.pressKey(0, 0);
    TrinketKeyboard.poll();
    wait(setTime);
  }
}
void wait(int seconds) {
  int count = 0;
  int total = seconds * 100;
while(count < total) {
  TrinketKeyboard.poll();
  delay(10);
  TrinketKeyboard.poll();
  count++;
}
}

