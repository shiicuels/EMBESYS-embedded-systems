/*
//int digit4[] = {0,1,1,0,0,1,1};
//int digit5[] = {1,0,1,1,0,1,1};
*/


#include<Servo.h> //Used to control the SERVO MOTOR (1)
Servo servo1; //(2)

                      //a,b,c,d,e,f,g
int digits[10] [7] = { {1,1,1,1,1,1,0}, //digit0
                       {0,1,1,0,0,0,0}, //digit1
                       {1,1,0,1,1,0,1}, //digit2
                       {1,1,1,1,0,0,1}, //digit3
                       {0,1,1,0,0,1,1}, //digit4
                       {1,0,1,1,0,1,1}, //digit5
                       {1,0,1,1,1,1,1}, //digit6
                       {1,1,1,0,0,0,0}, //digit7
                       {1,1,1,1,1,1,1}, //digit8
                       {1,1,1,1,0,1,1}, //digit9
                      };
int d;
int servo_angle = 0; //SERVO Step 2

unsigned long startTime_display = 0;
unsigned long interval_display = 1000; // Remember delay(1000)? this is her now

unsigned long startTime_servo = 0; //SERVO Step 1
unsigned long interval_servo = 10;

void setup() {
  for(int i = 13; i >= 7; i--){  // FOR 7 Segment Display
      pinMode(i, OUTPUT);  
    }
  pinMode(2, INPUT);            //FOR Tactile Switch
  Serial.begin(9600);           // Just for u to try using serial monitor 
  
  servo1.attach(6); //Tell which pin is servo1 variable (3)
}

void loop() {
  unsigned currentTime = millis();  //whenever you call the millis() function - it returns the time in milliseconds (TIME KEEPING - the moment program start running)
  Serial.println(currentTime); // Question is HOW DO YOU MAKE USE OF THIS TIME?? 

  if(currentTime - startTime_display >= interval_display){ //Check startTime if it is greater that 0 or equal to time interval ELAPSE TIME = Delay()!!
       startTime_display = currentTime;  //BIT TRICKY HERE 1-1000
       
       for(int i = 13; i >= 7; i--){ 
        digitalWrite(i, digits[d] [13-i]); //Will only happen every after 1000 counts especified in "d"
      }
       d++; // Increment manually (global variable) so it can access the digit after every loop
    }
    
  if (digitalRead(2) == LOW || d == 10) d = 0; // Check if digtal PIN 2 is pushed to the ground THEN reset d to 0 ZERO (Tactile Switch) + check "d" to reset also

  //SERVO MOTOR
  /*servo1.write(0); //pass 180 degrees (4)
  delay(1000);*/

  
  /*//This is for smooth sweeping effect of servo motor
  for(int i=0; i <= 180; i++){
      servo1.write(i);
      delay(10);
    }
  for(int i=180; i >= 0; i--){
      servo1.write(i);
      delay(10);
    }
   */

    //SERVO Step 3
   if(currentTime - startTime_servo >= interval_servo){
          //SERVO Step 4
          startTime_servo = currentTime;
    
      servo1.write(servo_angle);
      servo_angle++;
      if(servo_angle == 180) servo_angle = 0;
    }
  
}
