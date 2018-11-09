/*
 * SunRase 4.0 by: Reolfi Riccardo, Incolto Davide, Murialdo Andrea, Pastorino Simone.
 * Code by: Incolto Davide.
*/
int motDestraA = 2;
int motDestraI = 3;
int motSinistraA = 4;
int motSinistraI = 5;
int magnetic = 6;
int echoS = 8;
int trigS = 7;
int echoUp = 9;
int trigUp = 10;
int echoD = 11;
int trigD = 12;
int tempo_rotazione = 2000;
long durata;
long distanza;
int val;
void setup() {
  pinMode(motDestraI, OUTPUT);
  pinMode(motDestraA, OUTPUT);
  pinMode(motSinistraI, OUTPUT);
  pinMode(motSinistraA, OUTPUT);
  pinMode(magnetic, INPUT);
  pinMode(trigD, OUTPUT);
  pinMode(echoD, INPUT);
  pinMode(trigS, OUTPUT);
  pinMode(echoS, INPUT);
  pinMode(trigUp, OUTPUT);
  pinMode(echoUp, INPUT);
  Serial.begin(9600);
  randomSeed(analogRead(0));
  delay(5000);
}
void loop() {
 AvantiTutta();
 if(digitalRead(magnetic) == 1) giraCasuale();
 delay(3);
 checkUltra();
 delay(5);
}
bool destraCheck(){
  digitalWrite(trigD, LOW);
  digitalWrite(trigD, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigD, LOW);
  durata = pulseIn(echoD, HIGH);
  distanza = 0.034 * durata / 2;
  if(distanza < 15) return true;  
  else return false;
}
bool sinistraCheck(){
  digitalWrite(trigS, LOW);
  digitalWrite(trigS, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigS, LOW);
  durata = pulseIn(echoS, HIGH);
  distanza = 0.034 * durata / 2;
  if(distanza < 15) return true;  
  else return false;
 }
bool upCheck(){
  digitalWrite(trigUp, LOW);
  digitalWrite(trigUp, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigUp, LOW);
  durata = pulseIn(echoUp, HIGH);
  distanza = 0.034 * durata / 2;
  if(distanza < 15) return true;  
  else return false;
}

void giraCasuale(){
  int randNumber = random(300);
  int y;
  if(randNumber < 150) y = 1;
  else if(randNumber > 149) y = 2;
  if(y == 1) giraD();
  else if(y ==2) giraS();
}

void giraD(){
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
}

void checkUltra(){
  bool SomeD = destraCheck();
  bool SomeS = sinistraCheck();
  bool SomeUp = upCheck();
  if(SomeD == true) giraD();
  else if(SomeS == true) giraS();
  else if(SomeUp == true) giraCasuale();
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
}
