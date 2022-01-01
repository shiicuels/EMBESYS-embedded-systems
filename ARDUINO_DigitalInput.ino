void setup() {
 pinMode(6, OUTPUT);
 pinMode(7, OUTPUT);
 pinMode(8, OUTPUT);
 pinMode(9, OUTPUT);
 pinMode(3, INPUT);
 pinMode(2, INPUT);
}

void loop() {
  if(digitalRead(3)==LOW && digitalRead(2)== HIGH){
      LED_Blink();
    }

   else if(digitalRead(3)==HIGH && digitalRead(2)== LOW){
      LED_Alternate();
    }
    else{
      LED_off();
    }
}
void LED_Blink(){
    digitalWrite(6, HIGH);
    digitalWrite(7, HIGH);
    digitalWrite(8, HIGH);
    digitalWrite(9, HIGH);    
    delay(100);
    digitalWrite(6, LOW);
    digitalWrite(7, LOW);
    digitalWrite(8, LOW);
    digitalWrite(9, LOW);    
    delay(100);
  }
void LED_Alternate() {
    digitalWrite(6, HIGH);
    digitalWrite(7, LOW);
    digitalWrite(8, HIGH);
    digitalWrite(9, LOW);    
    delay(100);
    digitalWrite(6, LOW);
    digitalWrite(7, HIGH);
    digitalWrite(8, LOW);
    digitalWrite(9, HIGH);    
    delay(100);
  }
void LED_off() {
    digitalWrite(6, LOW);
    digitalWrite(7, LOW);
    digitalWrite(8, LOW);
    digitalWrite(9, LOW);   
 }
