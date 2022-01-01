#include<Stepper.h>
int stepsPerRevolution = 2048; //360 degrees / 1.8 degrees per step - Total steps to make 1 full rotation 360 deg
Stepper stepper1 = Stepper(stepsPerRevolution, 2, 3, 4, 5);

String data[3]; //[0] Direction (Clockwise / Counter clockwise),[1] Angle (Steps per revolution), [2]Speed (RPM)
int index = 0; // Navigate the array of String
float steps = 0; // Hold the converted value on how many steps are required to achieve the desired angle or degree position of the motor


void setup() {
  stepper1.setSpeed(10); //RPM (Revolution per Minute); - It will take 1 minute to make 360 rotation (10) = 10 revolution per minute
  Serial.begin(9600);
}

void loop() {
  if(Serial.available()){
      data[index] = Serial.readStringUntil(','); //Read the entire string
      Serial.print("data read: "); Serial.println(data[index]);
      index++;
      
      if(index == 3){
        index = 0;
        steps = stepsPerRevolution / 360.0 * data[1].toInt();
        stepper1.setSpeed(data[2].toInt());
        if(data[0] == "C") stepper1.step(steps);
        else if(data[0] == "W") stepper1.step(-steps); 
        }
    }
}
