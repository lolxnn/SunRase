/*
 * SunRase 4.0 by: Reolfi Riccardo, Incolto Davide, Murialdo Andrea, Pastorino Simone.
 * Code by: Reolfi Riccardo & Incolto Davide.
*/
#include <LiquidCrystal.h>
const int batPin = A1;
int val_Adc = 0;
unsigned int oldSpeed;
unsigned int newSpeed;
int startSetSpeed;
LiquidCrystal lcd(4, 6, 10, 11, 12, 13);
void setup() {
  motor_1.attach(9);
  pinMode(A0, INPUT);
  pinMode(A1, INPUT);
  pinMode(A3, INPUT);
  lcd.begin(16, 2);
  lcd.print("Benvenuto su");
  lcd.setCursor(0, 1);
  lcd.print("SunRase 4.0");
  int velocitaBrushless = 150;
  delay(1000);
  for(int i = 80; i < velocitaBrushless; i++){
    lcd.setCursor(0, 0);
    lcd.print("Avvio Motori");
    lcd.setCursor(0, 1);
    lcd.print("Stato:");
    lcd.print(map(i, 80, 150, 0, 100));
    lcd.print("%");
    motor_1.write(i);
    delay(110);
    lcd.clear();
  }
  lcd.clear();
  startSetSpeed = map(analogRead(A0), 0, 1023, 0, 150);
}

void loop() {
 lcd.setCursor(0, 0);
 lcd.print("Temp. Driver:");
 lcd.print(readTemperature());
 lcd.setCursor(0, 1);
 lcd.print("Batteria:");
 lcd.print(" ");
 lcd.print("%");
 delay(20);
 if (startSetSpeed =! map(analogRead(A0), 0, 1023, 0, 150)) changeSpeed();
 lcd.clear();
}
float readTemperature(){
  val_Adc = analogRead(0);
  float tempe = ((val_Adc * 0.00488) - 0.5) / 0.01;
  return tempe;
}
void changeSpeed(){
  int a = 0; 
  while (a =! 30 && a < 30){
    oldSpeed = newSpeed;
    newSpeed = map(analogRead(A0), 0, 1023, 0, 150);
    if(newSpeed > oldSpeed) oldSpeed++;
    else if(newSpeed < oldSpeed) oldSpeed--;
    else if(newSpeed = oldSpeed) a++;
    motor_1.write(oldSpeed);
    delay(1);
  }
}
