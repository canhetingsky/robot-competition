#include <AFMotor.h>

AF_DCMotor motor1(1);
AF_DCMotor motor2(2);
AF_DCMotor motor3(3);
AF_DCMotor motor4(4);

void setup() {
  // put your setup code here, to run once:

}

void loop() {
  // put your main code here, to run repeatedly:
  motor1.run(FORWARD);
  motor1.setSpeed(120); 
  delay(2000);
  motor1.run(BACKWARD);
  motor1.setSpeed(120); 
  delay(2000);
  motor1.run(RELEASE);
  delay(2000);
}
