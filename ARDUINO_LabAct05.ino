int valueSpeed;
int valuePower;
bool state = HIGH;

void setup() {
  pinMode (10, OUTPUT);
  pinMode (11, OUTPUT);
  pinMode (12, OUTPUT);
  pinMode (13, OUTPUT);
}

void loop() {
  valueSpeed = analogRead(A0);
  valuePower = analogRead(A1);

  if (valuePower < 300){
      LED_Sequence();
  }else{
     LED_off();
   }
}

void LED_Sequence(){
    for(int i=10; i<=13; i++){
         digitalWrite(i, state);
         delay(valueSpeed);
    }
    state = !state;
  }

void LED_off(){
    for(int i=10; i<=13; i++){
         digitalWrite(i, !state);
    }
  }
