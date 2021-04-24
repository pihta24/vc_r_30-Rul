//Подключение библиотеки для работы с дисплеем
#include <LiquidCrystal.h>
//Объявление макросов для пинов кнопки и дальномера
#define DIST_TRIG 12
#define DIST_ECHO 13
#define BUTTON 2

//Подключение дисплея
LiquidCrystal lcd(11, 10, 9, 8, 7, 6);


void setup()
{
  //Настройка пинов контроллера
  pinMode(DIST_TRIG, OUTPUT);
  pinMode(BUTTON, INPUT);
  pinMode(DIST_ECHO, INPUT);
  
  //Настройка дисплея
  lcd.begin(16, 2);
  lcd.setCursor(0, 0);
  lcd.print("Roulette");
}

void loop()
{
  //Проверка нажатия на кнопку
  if (digitalRead(BUTTON)){
    lcd.clear();
    
    //Считывание дистанции
    float duration, cm; 
    digitalWrite(DIST_TRIG, LOW); 
    delayMicroseconds(2); 
    digitalWrite(DIST_TRIG, HIGH); 
    delayMicroseconds(10); 
    digitalWrite(DIST_TRIG, LOW); 
    duration = pulseIn(DIST_ECHO, HIGH); 
    cm = duration / 58;
    
    //Проверка на выход за пределы измерений датчика и вывод на дисплей
    if (cm <= 335){
      lcd.print(cm);
      lcd.print(" cm");
    } else {
      lcd.print("Out of range");
    }
  }
}
