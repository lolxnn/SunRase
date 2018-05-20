/*
 * SunRase 4.0 by: Reolfi Riccardo, Incolto Davide, Murialdo Andrea, Pastorino Simone, Santo Alessandro.
 * Code by: Reolfi Riccardo & Incolto Davide.
*/
#include <LiquidCrystal.h>
#include <Servo.h>
Servo motor_1;
const int batPin = A1;
int val_Adc = 0;
unsigned int oldSpeed;
unsigned int newSpeed;
int startSetSpeed;
LiquidCrystal lcd(7, 6, 5, 4, 3, 2);
void setup() {
  motor_1.attach(8);
  pinMode(A0, INPUT);
  pinMode(A1, INPUT);
  pinMode(A3, INPUT);
  lcd.begin(16, 2);
  lcd.print("Benvenuto su");
  lcd.setCursor(0, 1);
  lcd.print("SunRase 4.0");
  int velocitaBrushless = 150;
  delay(1000);
  for(int i = 70; i < velocitaBrushless; i++){
    lcd.setCursor(0, 0);
    lcd.print("Avvio Motori");
    lcd.setCursor(0, 1);
    lcd.print("Stato:");
    lcd.print(map(i, 70, 150, 0, 100));
    lcd.print("%");
    motor_1.write(i);
    delay(40);
    lcd.clear();
  }
  lcd.clear();
  startSetSpeed = map(analogRead(A0), 0, 1023, 0, 150);
}

void loop() {
 lcd.setCursor(0, 0);
 lcd.print("Progetto SunRase");
 lcd.setCursor(0, 1);
 lcd.print("By ISS Cairo M.");
 delay(4000);
 lcd.clear();
 lcd.setCursor(0, 0);
 lcd.print("Gestito da");
 lcd.setCursor(0, 1);
 lcd.print("Arduino");
 delay(4000);
 lcd.clear();
 lcd.setCursor(0, 0);
 lcd.print("Interamente");
 lcd.setCursor(0, 1);
 lcd.print("Autonomo");
 delay(4000);
 lcd.clear();
}
//Parte di codice non usata ma funzionante
/*float readTemperature(){
  val_Adc = analogRead(0);
  float tempe = ((val_Adc * 0.00488) - 0.5) / 0.01;
  return tempe;
}
void changeSpeed(){
  int a = 0; 
  do{
    oldSpeed = newSpeed;
    newSpeed = map(analogRead(A0), 0, 1023, 0, 150);
    if(newSpeed > oldSpeed) oldSpeed++;
    else if(newSpeed < oldSpeed) oldSpeed--;
    else if(newSpeed = oldSpeed) a++;
    motor_1.write(oldSpeed);
    delay(5);
  }while (a =! 30 && a < 30);
}
*/
