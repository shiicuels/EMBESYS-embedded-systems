int value;
float voltage;
bool state = HIGH;

void setup() {
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT); 
  pinMode(12, OUTPUT);
  pinMode(13, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  value = analogRead(A0);

  Serial.print("Value: ");
  Serial.print(value);
  Serial.print("  ");
  voltage = 5.0*value/1023;
  Serial.print(voltage);
  Serial.println(" volt(s)");
  LED_Blink();
  
}

void LED_Blink(){
  for(int i=10; i<=13; i++) 
  digitalWrite(i, state);
  
  delay(value);
  state = !state;

}
