#include<Servo.h>                               
Servo servo;
int servo_angle = 0;

int coveredPR;                                       
bool boxState = LOW;

const int blue1 = 13;
const int white1 = 12;
const int yellow = 8;
const int white2 = 7;
const int blue2 = 4;

int yellowState = LOW;
unsigned long startTime_yellow = 0;
unsigned long interval_yellow = 50;

int blueState = LOW;
unsigned long startTime_blue = 0;
unsigned long interval_blue = 500;

int whiteState = LOW;
unsigned long startTime_white = 0;
unsigned long interval_white = 1000;

const int red1 = 11;
const int red2 = 10;
const int red3 = 9;
const int red4 = 6;
const int red5 = 5;

unsigned int frequencies[] = {659, 659, 659, 659, 659, 659, 659, 784, 523, 587, 659, 698, 698, 698, 698, 698, 659, 659, 659, 659, 659, 587, 587, 659, 587, 784};
unsigned long durations[] = {150, 150, 250, 150, 150, 250, 150, 150, 150, 150, 450, 150, 150, 150, 150, 150, 150, 150, 100, 100, 150, 150, 150, 150, 250, 250};

const int buzzer = 3;

void setup() {
  Serial.begin(9600);
  servo.attach(2);                         

  pinMode(blue1, OUTPUT);
  pinMode(white1, OUTPUT);
  pinMode(yellow, OUTPUT);
  pinMode(blue2, OUTPUT);
  pinMode(white2, OUTPUT);  
  pinMode(red1, OUTPUT);
  pinMode(red2, OUTPUT);
  pinMode(red3, OUTPUT);
  pinMode(red4, OUTPUT);
  pinMode(red5, OUTPUT);  

  pinMode(buzzer, OUTPUT);                              
}

void loop() {
  Serial.print("Value: ");
  Serial.println(coveredPR);
  
  coveredPR = analogRead(A0); 
  unsigned currentTime = millis();

  if(coveredPR <= 20){      
      servo_90();
      boxState = HIGH;
    }else if(coveredPR > 20){
      servo.write(0);
      boxState = LOW;      
      }

  if(boxState == LOW){
       if(currentTime - startTime_yellow >= interval_yellow){
         startTime_yellow = currentTime;
           if(yellowState == LOW){
            yellowState = HIGH;
           }else{
           yellowState = LOW;
           }
       }
      
       if(currentTime - startTime_blue >= interval_blue){
         startTime_blue = currentTime;
           if(blueState == LOW){
            blueState = HIGH;
           }else{
           blueState = LOW;
           }
       }
      
       if(currentTime - startTime_white >= interval_white){
         startTime_white = currentTime;
           if(whiteState == LOW){
            whiteState = HIGH;
           }else{
           whiteState = LOW;
           }
       }
      
       Outside_LightsON();
    }else{
       Outside_LightsOFF();
      }   

  if(boxState == HIGH){
    for(int i=0; i<sizeof(frequencies)/sizeof(int); i++){
    tone(buzzer, frequencies[i], 100);
      for (int i=0; i<=255; i++){
          analogWrite(red1, i);
          analogWrite(red2, i);
          analogWrite(red3, i);
          analogWrite(red4, i);
          analogWrite(red5, i);
          delay(1); 
        }
      for (int i=255; i>=0; i--){
          analogWrite(red1, i);
          analogWrite(red2, i);
          analogWrite(red3, i);
          analogWrite(red4, i);
          analogWrite(red5, i);
        }
         delay(durations[i]-1);
      }
  }else{
      Inside_LightsOFF();
    }

}

void servo_90() {
  servo.write(90);
}

void Outside_LightsON(){
    digitalWrite(yellow, yellowState);
    digitalWrite(blue1, blueState);
    digitalWrite(blue2, blueState);
    digitalWrite(white1, whiteState);
    digitalWrite(white2, whiteState);
  }

void Outside_LightsOFF(){
    digitalWrite(yellow, LOW);
    digitalWrite(blue1, LOW);
    digitalWrite(blue2, LOW);
    digitalWrite(white1, LOW);
    digitalWrite(white2, LOW);
  }

void Inside_LightsOFF(){
    analogWrite(red1, 0);
    analogWrite(red2, 0);
    analogWrite(red3, 0);
    analogWrite(red4, 0);
    analogWrite(red5, 0);
  }
