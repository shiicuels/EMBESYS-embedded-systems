#include<Servo.h>
Servo servo1; //(2)

int digits[10] [7] = {  {1,1,1,1,0,1,1}, //digit9
                        {1,1,1,1,1,1,1}, //digit8
                        {1,1,1,0,0,0,0}, //digit7
                        {1,0,1,1,1,1,1}, //digit6
                        {1,0,1,1,0,1,1}, //digit5
                        {0,1,1,0,0,1,1}, //digit4
                        {1,1,1,1,0,0,1}, //digit3
                        {1,1,0,1,1,0,1}, //digit2
                        {0,1,1,0,0,0,0}, //digit1
                        {1,1,1,1,1,1,0}, //digit0
                      };
int d;
int servo_angle = 0;

unsigned long startTime_display = 0;
unsigned long interval_display = 1000;

unsigned long startTime_servo = 0;
unsigned long interval_servo = 10;

unsigned long startTime_blink = 0;
unsigned long interval_blink = 500;

unsigned long startTime_green = 0;
unsigned long interval_green = 500;

int greenState = LOW;

void setup() {
  for(int i = 13; i >= 7; i--){  
      pinMode(i, OUTPUT);  
    }
  pinMode(2, INPUT);           
  Serial.begin(9600);      
  
  servo1.attach(6);

  pinMode(5, OUTPUT);
  pinMode(4, OUTPUT);
}

void loop() {
  unsigned currentTime = millis();  
  Serial.println(currentTime); 

    if(d == 0 && digitalRead(2) == HIGH) {                                                                                     
        digitalWrite(5, HIGH);
    }

    if(currentTime - startTime_display >= interval_display ){                                                       
       startTime_display = currentTime; 
       for(int i = 13; i >= 7; i--){ 
        digitalWrite(i, digits[d] [13-i]);
      }
       d++;
    }
              
    if (digitalRead(2) == LOW || d == 10) {                                                                  
      d = 0; 
      digitalWrite(5, LOW);
    }

    if(currentTime - startTime_blink >= interval_blink){
      startTime_blink = currentTime;
            digitalWrite(5, LOW);
    }

    if(currentTime - startTime_green >= interval_green){
      startTime_green = currentTime;
      if(greenState == LOW && d > 0){
        greenState = HIGH;
       }else{
        greenState = LOW;
      }

      if(digitalRead(2) == LOW || digitalRead(5) == HIGH) {
         greenState = LOW;
      }
      digitalWrite(4, greenState);
    }

   if(currentTime - startTime_servo >= interval_servo){
      startTime_servo = currentTime;    
      servo1.write(servo_angle);
      servo_angle++;
      if(servo_angle == 180 || d == 0) servo_angle = 0;
    }
  
}
