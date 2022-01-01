//const int led1=6, led2=7, led3=8;
int delayValue=1000;

void setup() {
  pinMode(5, 1);
  pinMode(6, 1); //OUTPUT = 1 and INPUT = 0
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
}

void loop() {
      
      for (int i = 5; i <= 8; i++) {
      digitalWrite(i, 1);
      delay(delayValue); 
    }
      for (int i = 6; i <= 8; i++) {
      digitalWrite(i, 0);
    }
    delayValue -= 150;
    
    if (delayValue <= 0) delayValue = 1000;
}
