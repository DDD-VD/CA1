
/*
   Просыпаться каждую секунду, опрашивать расстояние
   Если заметили руку, включить серво, повернуть, запомнить время, снова спать каждую секунду
   Если руки нет и прошло > времени удержания, подключить серво и закрыть крышку
*/
//--------------------НАСТРОЙКИ----------------------
         // высота срабатывания
         #define cap_time 2      // время открытой крышки в секундах
         #define open_angle 10   // угол открытия
         #define close_angle 55 // угол закрытия
         #define name "bin_test" // имя устройства
         //--------------------НАСТРОЙКИ----------------------
         
         // ---ПОДКЛЮЧЕНИЕ---
         #define button 3 // кнопка

         #define displayVCC 0

         #define binFullPin 2 // принимает 1 либо 0 от заполнености

         #define IRsensor 4

         #define servoVCC 0
         #define servoPin 7
         #define servoPin2 6
         #define binStatusPin 8
         // ---ПОДКЛЮЧЕНИЕ---
         
         #include <GTimer.h> // библиотека таймера
         #include <OneButton.h> // библиотека кнопки
         //#include "LowPower.h" // библиотека сна
         #include <Servo.h> // используем библиотеку для работы с сервоприводом
         #include <Arduino.h>
         #include  <rgb_lcd.h>
         #include <Bridge.h>
          #include <HttpClient.h>
          //#include <Ethernet.h>
          String ServerDomain = "172.16.76.56";
          
         Servo servo;          // объявляем переменную servo типа Servo
         Servo servo2;          // объявляем переменную servo типа Servo
         rgb_lcd lcd;          // объявляем переменную lcd типа rgb_lcd
         OneButton oneButton(button, true); // объявляем переменную button1 типа OneButton
         long duration;
         
         unsigned long open_timer;
         bool button_flag;
         bool open_flag;
         bool IRsensor_flag;
         bool check_Full_Flag;
         int counter = 0;
         //////////////////////
         void turn_on_VCC(){
            digitalWrite(displayVCC, HIGH);
            digitalWrite(servoVCC, HIGH);
         }
          void turn_off_VCC(){
              digitalWrite(displayVCC, LOW);
              digitalWrite(servoVCC, LOW);
          }

         void open_cap() {
          turn_on_VCC();
          lcd.begin(16, 2);
           lcd.display();
           servo.write(open_angle);        // открыть крышку
           servo2.write(180-open_angle);
           oneButton.tick();
           delay(500);                    // ждать серво
           oneButton.tick();
           lcd.print("Open");
           lcd.setCursor(0, 1);
           lcd.print("Opened:" +String(counter));
           open_flag = 1; 
           digitalWrite(binStatusPin, HIGH);           // включить датчик
               counter++;             // флаг что крышка открыта
         }
         void close_cap() {
           servo.write(close_angle);       // закрыть крышку
           servo2.write(180-close_angle);
           delay(500);                    // ждать серво
           
           open_flag = 0;           // флаг что крышка закрыта
           digitalWrite(binStatusPin,LOW);                  
           
           lcd.clear();
           lcd.noDisplay();
         
         }
         void singleClick() {
           if (button_flag == 1) {
             button_flag = 0;
           }
           button_flag = 1;
         }
         void longPress() {
           counter = 0;
           lcd.clear();
           lcd.print("Opens reseted");
         }
         void binFull() {
          HttpClient client;
         client.get("http://"+ServerDomain+"/update.php?level=" + String(1)+"&name="+name);    //отправляет информацию о заполнении муора на сервер
         }
         void binEmpty() {
          HttpClient client;
          client.get("http://"+ServerDomain+"/update.php?level=0"+"&name="+name);        //отправляет информацию о заполнении муора на сервер
         }
         void checkFull(){
         if (check_Full_Flag==0 && digitalRead(binFullPin)==1) { // если не было заполненности и пришел сигнал о заполненности
           check_Full_Flag = 1; // запомнить что был сигнал о заполненности
           binFull(); // отправить на сервер информацию о заполненности
         }
          if (check_Full_Flag==1 && digitalRead(binFullPin)==0) { // если был сигнал о заполненности и пришел сигнал о пустом мусорном ведре
            check_Full_Flag = 0; // запомнить что не было заполненности
            binEmpty(); // отправить на сервер информацию о пустом мусорном ведре
          }
         }
         ////////////////////////////
         void setup() {
           Bridge.begin();  // Запуск взаимодействия с Linux
           servo.attach(servoPin);         // серво на  порту
           servo2.attach(servoPin2);
           oneButton.attachClick(singleClick);
           oneButton.attachLongPressStart(longPress);
           pinMode(IRsensor, INPUT);       // ик датчик на  порту
           pinMode(servoVCC, OUTPUT);            // пин питания как выход 
          pinMode(displayVCC, OUTPUT);
          pinMode(binStatusPin, OUTPUT);
          pinMode(binFullPin, INPUT);       // пин заполненности как вход
           open_cap();                     // открытие крышки при запуске
         }
         
         
         
         void loop() {
          oneButton.tick();
           lcd.display();
             
           
           //LowPower.powerDown(SLEEP_1S, ADC_OFF, BOD_OFF);  // спать 1 секунду
         

            IRsensor_flag = !digitalRead(IRsensor);              // получить расстояние

             
         
           if (IRsensor_flag){ // если расстояние попадает в диапазон
             open_timer = 0;                     // сбросить таймер
             if (!open_flag) {                   // если крышка закрыта
               open_cap();                       // открыть крышку
             }
              
           } 
           else {
             if (open_flag) {                    // если крышка открыта
               open_timer++;                     // прибавить таймер
               if (open_timer > cap_time) {      // если с момента открытия прошло больше 5сек
                 close_cap();                    // закрыть крышку
               }
             }
             
           }
           lcd.noDisplay();
         }
         
         
         