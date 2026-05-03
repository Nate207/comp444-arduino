/* Circuit 10 (3C) - Motion Alarm

*/

#include <servo.h>    //import servo library

const int trigPin = 11;   //trigger pin
const int trigPin = 12;   // echo pin

const int redPin = 3;    //red LED 
const int greenPin = 5;   //green LED
const int bluePin = 6;    //blue LED

const int buzzerPin = 10;   //buzzer pin

float distance = 0; //distance value in decimals

Servo myservo;    // creates servo object

void setup(){

  Serial.begin (9600);  //starts serial monitor

  pinMode(trigPin, OUTPUT); //sets trig as output
  pinMode(echoPin, INPUT); //sets echo as input

  pinMode(redPin, OUTPUT); //output red LED
  pinMode(greenPin, OUTPUT); //output green LED
  pinMode(bluePin, OUTPUT); //output blue LED

  pinMode(buzzerPin, OUTPUT;) //buzzer to output

  myservo.attach(9);  //connect servo to pin 9
}

void loop(){

  distance = getDistance(); //function to measure distance

  Serial.println(distance); //prints distance
  Serial.println(" in");    // for display

  if (distance <= 10){    //distance 10 inches or less from sensor

    analogWrite(redPin, 255); //red LED full brightness
    analogWrite(greenPin, 0);
    analogWrite(bluePin, 0);

    tone(buzzerPin, 272); //tone for buzzer
    myservo.write(10);    // move servo
    delay(100);         
    
    noTone(buzzerPin);    // turns buzzer off
    myservo.write(150);   //move serva back to position
    delay(100);


  } else if (distance > 10 && distance < 20){ //distance between 10 & 20 inches

    analogWrite(redPin, 255); //gives off yellow colour
    analogWrite(greenPin, 55);
    analogWrite(bluePin, 0);

  } else { // distances beyond 20 inches

    analogWrite(redPin, 0);   //gives off green light only
    analogWrite(greenpin, 255);
    analogWrite(bluePin, 0);


  }

  delay(50); // short delay for readings

  }


  // ----------- FUNCTIONS  ---------------------------

  float getDistance(){      //gets distance from measurement

    float echoTime;             //time value
    float calculatedDistance;   //distance value

    digitalWrite(trigPin, HIGH);  //sends pulse
    delayMicroseconds(10);
    digitalWrite(trigPin, LOW);

    echoTime = pulseIn(echoPin, HIGH);    // reads pulse time

    calculatedDistance = echoTime / 148;    //converts time to inches

    return calculatedDistance;      // returns calculatedDistance to loop
  }

