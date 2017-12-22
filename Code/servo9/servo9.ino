#include <Servo.h>
Servo servo_9;
void setup() {
  // put your setup code here, to run once:
  servo_9.attach(9);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  servo_9.write(90);
  delay(5000); // Wait for 5000 millisecond(s)  
  servo_9.write(0);
  delay(5000); // Wait for 5000 millisecond(s)
}
