/*
 * SunRase 4.0 by: Reolfi Riccardo, Incolto Davide, Murialdo Andrea, Pastorino Simone.
 * Code by: Incolto Davide.
*/
int motDestraA = 2;
int motDestraI = 3;
int motSinistraA = 4;
int motSinistraI = 5;
int magnetic = 6;
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
  pinMode(triggerDestra, OUTPUT);
  pinMode(echoDestra, INPUT);
  pinMode(triggerSinistra, OUTPUT);
  pinMode(echoSinistra, INPUT);
  Serial.begin(9600);
  randomSeed(analogRead(0));
}
void loop() {
 AvantiTutta();
 checkMag();
 delay(3);
 checkUltra();
 delay(5);
}
void checkMag(){
  if(digitalRead(magnetic) == 1) giraCasuale();
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

int randNum(){
 int randNumber = random(300);
 int x;
 if(randNumber < 150){
  x = 1;
  return x;
  }
 else if(randNumber > 149){
  x = 2;
  return x;
 }
}

void giraCasuale(){
  int y = randNum();
  if(y == 1) giraD();
  else if(y ==2) giraS();
}

void giraD(){
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
       delay(1);
   }
   for(int i = 0; i < 10; i++){
       digitalWrite(motDestraA, LOW);
       digitalWrite(motSinistraA, LOW);
       delay(1);
   }
}

void checkUltra(){
  bool SomeD = destraCheck();
  bool SomeS = sinistraCheck();
  if(SomeD == true) giraS();
  else if(SomeS == true) giraD();
  else if(SomeD == true && SomeS == true) giraCasuale();
}
void AvantiTutta(){
  digitalWrite(motDestraI, LOW);
  digitalWrite(motSinistraI, LOW);
  delay(10);
  digitalWrite(motDestraA, HIGH);
  digitalWrite(motSinistraA, HIGH);
}
void giraS(){
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
       digitalWrite(motDestraA, HIGH);
       digitalWrite(motSinistraA, LOW);
       delay(1);
   }
   for(int i = 0; i < 10; i++){
       digitalWrite(motDestraA, LOW);
       digitalWrite(motSinistraA, LOW);
       delay(1);
   }
}
