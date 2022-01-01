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
          analogWrite(red1, 255);
          analogWrite(red2, 255);
          analogWrite(red3, 255);
          analogWrite(red4, 255);
          analogWrite(red5, 255);
  
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
