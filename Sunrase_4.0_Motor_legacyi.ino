/*
 * SunRase 4.0 by: Reolfi Riccardo, Incolto Davide, Murialdo Andrea, Pastorino Simone.
 * Code by: Incolto Davide.
*/
int motDestraA = 2;
int motDestraI = 3;
int motSinistraA = 4;
int motSinistraI = 5;
int magnetic = 6;
int triggerUp = 7;
int echoUp = 8;
int triggerDestra = 9;
int echoDestra = 10;
int triggerSinistra = 11;
int echoSinistra = 12;
int tempo_rotazione = 1500;
long durata;
long distanza;
int val;
void setup() {
  pinMode(motDestraI, OUTPUT);
  pinMode(motDestraA, OUTPUT);
  pinMode(motSinistraI, OUTPUT);
  pinMode(motSinistraA, OUTPUT);
  pinMode(magnetic, INPUT);
  pinMode(triggerUp, OUTPUT);
  pinMode(echoUp, INPUT);
  pinMode(triggerDestra, OUTPUT);
  pinMode(echoDestra, INPUT);
  pinMode(triggerSinistra, OUTPUT);
  pinMode(echoSinistra, INPUT);
  Serial.begin(9600);
  randomSeed(analogRead(0));
}
void loop() {
  inizio:;
  AvantiTutta();
  if(checkMag() == true){
    gira();
    }
  if(checkUltra() == true){
    gira();
    }
 delay(5);
}
bool checkMag(){
  if(digitalRead(magnetic) == 1) return true;  
  else return false; 
}
bool checkUltra(){
  digitalWrite( triggerUp, LOW );
  digitalWrite( triggerUp, HIGH );
  delayMicroseconds( 10 );
  digitalWrite( triggerUp, LOW );
  long durata = pulseIn( echoUp, HIGH );
  long distanza = 0.034 * durata / 2;
  Serial.println(distanza);
  if(distanza < 10) return true;
  else return false;
}
void AvantiTutta(){
  digitalWrite(motDestraI, LOW);
  digitalWrite(motSinistraI, LOW);
  delay(10);
  digitalWrite(motDestraA, HIGH);
  digitalWrite(motSinistraA, HIGH);
}
void gira(){
  val = lateralCheck();
  if(val == 1){
   for(int i = 0; i < 500; i++){
      digitalWrite(motDestraA, LOW);
      digitalWrite(motSinistraA, LOW);
      delay(1);
    }
   for(int i = 0; i < 1000; i++){
      digitalWrite(motDestraI, HIGH);
      digitalWrite(motSinistraI, HIGH);
      delay(1);
   }
   for(int i = 0; i < 10; i++){
      digitalWrite(motDestraI, LOW);
      digitalWrite(motSinistraI, LOW);
      delay(1);
   }
   for(int i = 0; i < tempo_rotazione; i++){
       digitalWrite(motDestraA, LOW);
       digitalWrite(motSinistraA, HIGH);
       if(DScontrol() == true){
       giraSpecialeDestra();
       break;
       }
       delay(1);
   }
   for(int i = 0; i < 10; i++){
       digitalWrite(motDestraA, LOW);
       digitalWrite(motSinistraA, LOW);
       delay(1);
   }
   loop();
 }
 else if(val == 2){
   for(int i = 0; i < 500; i++){
      digitalWrite(motDestraA, LOW);
      digitalWrite(motSinistraA, LOW);
      delay(1);
    }
   for(int i = 0; i < 1000; i++){
      digitalWrite(motDestraI, HIGH);
      digitalWrite(motSinistraI, HIGH);
      delay(1);
   }
   for(int i = 0; i < 10; i++){
      digitalWrite(motDestraI, LOW);
      digitalWrite(motSinistraI, LOW);
      delay(1);
   }
   for(int i = 0; i < tempo_rotazione; i++){
       digitalWrite(motDestraA, LOW);
       digitalWrite(motSinistraA, HIGH);
       if(DScontrol() == true){
        giraSpecialeSinistra();
        break;
       }
       delay(1);
   }
   for(int i = 0; i < 10; i++){
       digitalWrite(motDestraA, LOW);
       digitalWrite(motSinistraA, LOW);
       delay(1);
   }
   loop();
  }
}
int lateralCheck(){
  int x;
  if(destraCheck()== true){
   x = 1;
   return x;
 }
 else if(sinistraCheck() == true){
   x = 2;
   return x;
 }
 delay(10);
 int randNumber = random(300);
 if(randNumber < 150){
  x = 1;
  return x;
  }
 else if(randNumber > 149){
  x = 2;
  return x;
  }
 
}
bool destraCheck(){
  digitalWrite(triggerDestra, LOW);
  digitalWrite(triggerDestra, HIGH);
  delayMicroseconds(10);
  digitalWrite(triggerDestra, LOW);
  durata = pulseIn(echoDestra, HIGH);
  distanza = 0.034 * durata / 2;
  if(distanza < 40) return true;  
  else return false;
 }
 bool sinistraCheck(){
  digitalWrite(triggerSinistra, LOW);
  digitalWrite(triggerSinistra, HIGH);
  delayMicroseconds(10);
  digitalWrite(triggerSinistra, LOW);
  durata = pulseIn(echoSinistra, HIGH);
  distanza = 0.034 * durata / 2;
  if(distanza < 40) return true;  
  else return false;  
 }
bool DScontrol(){
  if(digitalRead(magnetic) == 1) return true;
}
void giraSpecialeDestra(){
  digitalWrite(motDestraA, LOW);
  digitalWrite(motSinistraA, LOW);
  delay(500);
  digitalWrite(motDestraI, HIGH);
  digitalWrite(motSinistraI, HIGH);
  delay(1000);
  digitalWrite(motDestraI, LOW);
  digitalWrite(motSinistraI, LOW);
  delay(10);
  digitalWrite(motDestraA, LOW);
  digitalWrite(motSinistraA, HIGH);
  delay(tempo_rotazione); 
  digitalWrite(motDestraA, LOW);
  digitalWrite(motSinistraA, LOW);
  delay(10);
  digitalWrite(motDestraA, HIGH);
  digitalWrite(motSinistraA, HIGH);
}
void giraSpecialeSinistra(){
  digitalWrite(motDestraA, LOW);
  digitalWrite(motSinistraA, LOW);
  delay(500);
  digitalWrite(motDestraI, HIGH);
  digitalWrite(motSinistraI, HIGH);
  delay(1000);
  digitalWrite(motDestraI, LOW);
  digitalWrite(motSinistraI, LOW);
  delay(10);
  digitalWrite(motDestraA, HIGH);
  digitalWrite(motSinistraA, LOW);
  delay(tempo_rotazione); 
  digitalWrite(motDestraA, LOW);
  digitalWrite(motSinistraA, LOW);
  delay(10);
  digitalWrite(motDestraA, HIGH);
  digitalWrite(motSinistraA, HIGH);
}
