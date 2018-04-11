/*
  Fideget Spinner Counter By Davide Incolto & Berge
*/
#include <LiquidCrystal.h>
int ledAOut = 5;
int ledBOut = 4;
int ledAIn = 2;
int ledBIn = 3;
int BuzzerPin = 9;
int pulsante = 7;
int start = 0;
int Tmax = 4000;
bool Pstart;
volatile int contaA = 0;
volatile int contaB = 0;
int i = 0;
LiquidCrystal lcd(6, 8, 10, 11, 12, 13);
void setup() {
    pinMode(ledAOut, OUTPUT);
    pinMode(ledBOut, OUTPUT);
    pinMode(ledAIn, INPUT);
    pinMode(ledBIn, INPUT);
    pinMode(BuzzerPin, OUTPUT);
    pinMode(pulsante, INPUT);
    Serial.begin(9600);
    lcd.print("Avvio In corso attendere");
    delay(1000);
    for(int i = 80; i < 150; i++){
      lcd.setCursor(0, 0);
      lcd.print("Avvio Software");
      lcd.setCursor(0, 1);
      lcd.print("Stato:");
      lcd.print(map(i, 80, 150, 0, 100));
      lcd.print("%");
      delay(110);
      lcd.clear();
  }
  lcd.clear();
  attachInterrupt(0, contaA, FALLING);
  attachInterrupt(0, contaB, FALLING);
}

void loop() {
   lcd.setCursor(0, 0);
   lcd.clear(); 
    do{
      start = digitalRead(pinStart);
    } while(start);
   int Tstart = millis();
   while(millis() - Tstart <= Tmax){

   }
   delay(500);
   int Pstart = 1;
   lcd.setCursor(0, 0);
   lcd.print("Velocita' A = ")
   lcd.print(contaA * 5);
   lcd.setCursor(0, 1);
   lcd.print("giri al minuto");
   delay(3000);
   lcd.clear();
   lcd.setCursor(0, 0);
   lcd.print("Velocita' B = ")
   lcd.print(contaB * 5);
   lcd.setCursor(0, 1);
   lcd.print("giri al minuto");
   delay(3000);
   lcd.setCursor(0, 0);
   lcd.clear();
   if(contaA > contaB){
      lcd.print("Il vincitore e'");
      lcd.setCursor(0, 1);
      lcd.print("Il giocatore : A");
      PlayVictoryTheme();
   }
   else if(contaB > contaA){
      lcd.print("Il vincitore e'");
      lcd.setCursor(0, 1);
      lcd.print("Il giocatore : B");
      PlayVictoryTheme();
   }
   contaA = 0;
   contaB = 0;   
}
void contaA(){
  if(Pstart == 0){
    contaA++;
  }
}

void contaB(){
    if(Pstart == 0){
    contaB++;
  }
}
}

void PlayVictoryTheme() {
    tone(BuzzerPin, 523.25, 133);
    delay(133);
    tone(BuzzerPin, 523.25, 133);
    delay(133);
    tone(BuzzerPin, 523.25, 133);
    delay(133);
    tone(BuzzerPin, 523.25, 400);
    delay(400);
    tone(BuzzerPin, 415.30, 400);
    delay(400);
    tone(BuzzerPin, 466.16, 400);
    delay(400);
    tone(BuzzerPin, 523.25, 133);
    delay(133);
    delay(133);
    tone(BuzzerPin, 466.16, 133);
    delay(133);
    tone(BuzzerPin, 523.25, 1200);
    delay(1200);
    noTone(BuzzerPin);
}