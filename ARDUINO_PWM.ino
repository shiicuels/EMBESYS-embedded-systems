int ldr, led_value;
unsigned int frequencies[] = {660, 660, 660, 510, 660, 770};
unsigned long durations[] = {150, 300, 300, 100, 300, 550};

void setup() {
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);

  Serial.begin(9600);
}

void loop() {

 for(int i=0; i<sizeof(frequencies)/sizeof(int); i++){
    tone(5, frequencies[i], 100);
    analogWrite(6, 255); analogWrite(9,255); analogWrite(10,255);
    delay(100);
    analogWrite(6, 0); analogWrite(9,0); analogWrite(10,0);    
    delay(durations[i]-100);
  }

  
/*
 READING THE VALUE OF LDR
  ldr = analogRead(A0);
  led_value = map(ldr, 0, 1023, 0, 255);

  Serial.print("LDR reading: ");
  Serial.print(ldr);
  Serial.print("     MAP led_value: ");
  Serial.println(led_value);
  
  analogWrite(5, led_value);
  analogWrite(6, led_value); 
  analogWrite(9, led_value);
  analogWrite(10, led_value); 
*/
  
/*  
 FADING NO LDR
  for (int i=0; i<=255; i++){
      analogWrite(5, i);
      analogWrite(6, i);
      analogWrite(9, i);
      analogWrite(10, i);
      delay(5);
    }
  for (int i=255; i>=0; i--){
      analogWrite(5, i);
      analogWrite(6, i);
      analogWrite(9, i);
      analogWrite(10, i);
      delay(5);
    }
*/



}
