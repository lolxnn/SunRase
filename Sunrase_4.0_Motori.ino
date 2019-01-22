/*
 * SunRase 4.0 by: Reolfi Riccardo, Incolto Davide, Murialdo Andrea, Pastorino Simone.
 * Code by: Incolto Davide.
*/
#define motDestraA  2
#define motDestraI 3
#define motSinistraA 4
#define motSinistraI 5
#define magnetic 6
#define echoS 8
#define trigS 7
#define echoUp 9
#define trigUp 10
#define echoD 11
#define trigD 12
int tempo_rotazione = 2000;
long durata;
long distanza;
int val;
int randNumber;
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
  randNumber = random(300);
  if(randNumber < 150) giraD();
  else if(randNumber > 149) giraS();
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
