#include <Arduino.h>
#include <Servo.h>
#include <OneButton.h>
#include <GTimer.h>

#define buttonPin1 3 // плюс кнопка
#define buttonPin2 4 // минус кнопка
#define servoPin 8   // пин сервопривода

int servoAngle = 10; // начальный угол
const int servoMin = -0;   // минимальный угол
const int servoMax = 180; // максимальный угол

OneButton button1(buttonPin1, true);
OneButton button2(buttonPin2, true);
Servo servo;

void singleClick() {
  if (servoAngle < servoMax) {
    servoAngle += 1;
  }
}

// Функция для плавного увеличения угла при удерживании
void duringLongPress() {
  if (servoAngle < servoMax) {
    servoAngle += 1; 
    delay(40);  // задержка для управления скоростью изменения
  }
}

void singleClickM() {
  if (servoAngle > servoMin) {
    servoAngle -= 1;
  }
}


// Функция для плавного уменьшения угла при удерживании
void duringLongPressM() {
  if (servoAngle > servoMin) {
    servoAngle -= 1; 
    delay(40);  // задержка для управления скоростью изменения
  }
}

void setup() {
  Serial.begin(9600);
  servo.attach(servoPin);
  Serial.println("Debug started");

  button1.attachClick(singleClick);
  button1.attachDuringLongPress(duringLongPress);  

  button2.attachClick(singleClickM);
  button2.attachDuringLongPress(duringLongPressM);
}

void loop() {
  servo.write(servoAngle);
  EVERY_MS(500) Serial.println("servoAngle: " + String(servoAngle));
  button1.tick();
  button2.tick();
}
