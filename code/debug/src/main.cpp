#include <Arduino.h>
#include <Servo.h>
#include <OneButton.h>
#include <GTimer.h>

#define buttonPin1 2 //plus button
#define buttonPin2 3 //minus button

int servoAngle = 0;

void singleClick() {
servoAngle = servoAngle + 1;

}

void longPress() {
  servoAngle = servoAngle + 10;

}

void singleClickM() {
  servoAngle = servoAngle - 1;
  
  }
  
  void longPressM() {
    servoAngle = servoAngle - 10;
  
  }

OneButton button1(buttonPin1, true);
OneButton button2(buttonPin2, true);

void setup() {
 Serial.begin(9600);
 Serial.println("Debug started");
  button1.attachClick(singleClick);
  button1.attachLongPressStart(longPress);
  button2.attachClick(singleClickM);
  button2.attachLongPressStart(longPressM);
}

void loop() {
  EVERY_MS(50) Serial.println("servoAngle");

}

