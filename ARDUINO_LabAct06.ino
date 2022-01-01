int ldr, led_value;
unsigned int frequencies[] = {659, 659, 659, 659, 659, 659, 659, 784, 523, 587, 659, 698, 698, 698, 698, 698, 659, 659, 659, 659, 659, 587, 587, 659, 587, 784};
unsigned long durations[] = {150, 150, 250, 150, 150, 250, 150, 150, 150, 150, 450, 150, 150, 150, 150, 150, 150, 150, 100, 100, 150, 150, 150, 150, 250, 250};

void setup() {
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
}

void loop() {
  ldr = analogRead(A0);
  led_value = map(ldr, 0, 1023, 0, 255);
  
 for(int i=0; i<sizeof(frequencies)/sizeof(int); i++){
    tone(5, frequencies[i], 100);
    for (int i=0; i<=255; i++){
        analogWrite(6, i);
        analogWrite(9, i);
        analogWrite(10, i);
        delay(led_value / 50); 
      }
    for (int i=255; i>=0; i--){
        analogWrite(6, i);
        analogWrite(9, i);
        analogWrite(10, i);
      }
       delay(durations[i]-100);
  }
}
