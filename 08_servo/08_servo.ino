/* Circuit 8 (3A) - Servo

  Move the servo arm 
*/

#include <Servo.h>          //includes the servo library

int potPosition;           //stores the position of the potentiometer
int servoPosition;         //servo moves to this position

Servo myservo;              //creates a servo object to control

void setup() {

  myservo.attach(9);        //assign servo object to pin 9

}

void loop() {



  potPosition = analogRead(A0);                     //use analog read to measure the position of the potentiometer (0-1023)

  servoPosition = map(potPosition, 0, 1023, 20, 160); //convert the potentiometer number to a proportionate servo angle
                                                      //make sure servo is not pushed to it's limits as it can damage it

  myservo.write(servoPosition);                      //move the servo to the 10 degree position
}
