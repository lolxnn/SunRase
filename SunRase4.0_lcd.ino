/*
 * SunRase 4.0 by: Reolfi Riccardo, Incolto Davide, Murialdo Andrea, Pastorino Simone.
 * Code by: Reolfi Riccardo & Incolto Davide.
*/
#include <LiquidCrystal.h>
#include <Servo.h>
Servo motor_1;
const int tempPin = A0;
const int batPin = A1;
LiquidCrystal lcd(4, 6, 10, 11, 12, 13);
void setup() {
  motor_1.attach(9);
  pinMode(A0, INPUT);
  pinMode(A1, INPUT);
  pinMode(A3, INPUT);
  lcd.begin(16, 2);
  lcd.print("Avvio Motori");
  int velocitaBrushless = map(analogRead(A3), 0, 1023, 100, 150);
  delay(1000);
  for(int i = 80; i < velocitaBrushless; i++){
    lcd.setCursor(0, 1);
    lcd.print("Stato:", velocitaBrushless, 0, 100),"%")
    motor_1.write(i);
    delay(10);
    lcd.clear();
  }
  lcd.clear();
  
}

void loop() {
 lcd.setCursor(0, 0);
 lcd.print("Temp. Driver:");
 lcd.print(temp());
 lcd.setCursor(0, 1);
 lcd.print("Batteria:");
 lcd.print(batteria());
 lcd.print("%");
 lcd.clear();
}
float temp(){
  int tempVal = analogRead(tempPin);
  float millivolts = (tempVal / 1024.0) * 5000;
  float celsius = millivolts / 10;
  return celsius;
}
int batteria(){
  int batVal = analogRead(batPin);
  int batX100 = (batVal * 100) / 1024;
  return batX100;
}
