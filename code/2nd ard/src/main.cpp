#include <Arduino.h>
#include <GTimer.h> // библиотека таймера

#define numberOfPositiveSensors 4

#define pinIn A1
#define pinOut A2

#define IRsensorPin1 2
#define IRsensorPin2 3
#define IRsensorPin3 4
#define IRsensorPin4 5

GTimer<millis> tmr1;

void CheckFull() {
  int sensor1 = digitalRead(IRsensorPin1);
  int sensor2 = digitalRead(IRsensorPin2);
  int sensor3 = digitalRead(IRsensorPin3);
  int sensor4 = digitalRead(IRsensorPin4);

  if (sensor1+sensor2+sensor3+sensor4 == numberOfPositiveSensors) {
    digitalWrite(pinOut, HIGH); // Включаем выходной пин, если все датчики сработали
  } 
tmr1.start();
}

void setup() {
pinMode(IRsensorPin1, INPUT);
pinMode(IRsensorPin2, INPUT);
pinMode(IRsensorPin3, INPUT);
pinMode(IRsensorPin4, INPUT);
pinMode(pinIn, INPUT);
pinMode(pinOut, OUTPUT);

tmr1.setMode(GTMode::Timeout);
tmr1.setTime(1000);

}

void loop() {

EVERY_MS(600) {
  if (pinOut) CheckFull(); // Проверяем состояние датчиков 
}

if (tmr1) digitalWrite(pinOut, LOW);

}


