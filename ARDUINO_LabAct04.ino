void setup() {
  pinMode(9, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(6, OUTPUT);

  pinMode(4, INPUT);
  pinMode(2, INPUT);
}

int switch1=4, switch2=2;

void loop() {
  if (digitalRead(switch1)== LOW && digitalRead(switch2)== HIGH){
      LED_Blink();
    }
  else if (digitalRead(switch1)== HIGH && digitalRead(switch2)== LOW){
      LED_Alternate();
    }
  else if (digitalRead(switch1) == LOW && digitalRead(switch2) == LOW){
      LED_off();
    }
  else{
      LED_RunningLight();  
    }
}
void LED_RunningLight(){
    for(int i=6; i<=9; i++){
         digitalWrite(i, HIGH);
         delay(700);
         digitalWrite(i-1, LOW);
         digitalWrite(i, LOW);
    }
  }
void LED_Blink(){
    digitalWrite(9, HIGH);
    digitalWrite(8, HIGH);
    digitalWrite(7, HIGH);
    digitalWrite(6, HIGH);
    delay(100);
    digitalWrite(9, LOW);
    digitalWrite(8, LOW);
    digitalWrite(7, LOW);
    digitalWrite(6, LOW);
    delay(100);
  }
void LED_Alternate(){
    digitalWrite(9, LOW);
    digitalWrite(8, HIGH);
    digitalWrite(7, LOW);
    digitalWrite(6, HIGH);
    delay(100);
    digitalWrite(9, HIGH);
    digitalWrite(8, LOW);
    digitalWrite(7, HIGH);
    digitalWrite(6, LOW);
    delay(100);
  }
void LED_off(){
    digitalWrite(9, LOW);
    digitalWrite(8, LOW);
    digitalWrite(7, LOW);
    digitalWrite(6, LOW);
  }
