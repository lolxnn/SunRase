int S1 = 3;
int S2 = 4;
int S3 = 5;
int S4 = 6;
int S5 = 7;
int pompa1 = 8;
int spazz = 9;
int pompa2 = 10;
int asciuga = 11;
int nastro = 12;
int i;
int isON;
int tempopassaggi = 20000;
void setup(){
  // put your setup code here, to run once:
  for(i = 3; i < 8;i++);{
    pinMode(i, INPUT); 
    }
  for(i = 8; i < 13; i++){
    pinMode(i, OUTPUT);  
    }
}

void toNext(int x){
  do{
      digitalWrite(nastro, HIGH);
      isON = digitalRead(x+1);
    }while(isON = 0);
  digitalWrite(nastro, LOW);
  return 0;   
}

void activate(int x){
  if(x == 12) return 0;
  else{
    digitalWrite(x, HIGH);
    delay(tempopassaggi);
    digitalWrite(x, LOW);
    return 0;
    }  
  
}

void loop() {
  // put your main code here, to run repeatedly:
  if(digitalRead(S1)){
    for(i = 3; i < 8; i++);
      toNext(i);
      activate(i+5);
    }
    digitalWrite(nastro, HIGH);
    delay(5000);
    digitalWrite(nastro, LOW);
}
