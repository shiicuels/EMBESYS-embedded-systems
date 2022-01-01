void setup() {
  for(int i = 13; i>=7; i--)
    pinMode(i, OUTPUT);

}

void loop() {
  digitalWrite(13, LOW); //segment a
  digitalWrite(12, HIGH); //segment b
  digitalWrite(11, HIGH); //segment c
  digitalWrite(10, LOW);//segment d
  digitalWrite(9, LOW); //segment e
  digitalWrite(8, HIGH); //segment f
  digitalWrite(7, HIGH); //segment g
}
