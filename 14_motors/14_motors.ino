/* Circuit 14 (5A) - Motor Basics

We turn a motor on and can control its speed and direction.

*/

//pin variables for motor driver
const int AIN1 = 13; //directional control pin 1
const int AIN2 = 12; //directional control pin 2
const int PWMA = 11; // speed control pin using pulse width modulation

int switchPin = 7; //switch pin to turn motor off and on

//variable for motor speed. It starts in the stopped position.
int motorSpeed = 0;

void setup(){

    //set the switch as input using pull up resistor
    pinMode(switchPin, INPUT_PULLUP);

    //setting motor driver pins as outputs
    pinMode(AIN1, OUTPUT);
    pinMode(AIN2, OUTPUT);
    pinMode(PWMA, OUTPUT);

    //setup connection with serial monitor
    Serial.begin(9600);

    //prompt user for speed between -255 and 255
    Serial.println("Enter a speed between -255(clockwise) and 255(CCW)");

}

void loop(){

    //check if input entered into serial
    if (Serial.available() > 0){

        motorSpeed = Serial.parseInt();     //reads value entered
        
        //print motor speed in serial monitor
        Serial.println("Motor speed: ");
        Serial.println(motorSpeed);
}

//Check switch is in "on" position
if (digitalRead(switchPin) == LOW){
    // run the motor at entered speed
    spinMotor(motorSpeed);

}else {

    //if swtich is off, stop motor
    spinMotor(0);
    }
}

//method to control motor direction and speed
void spinMotor(int motorSpeed){
//if speed is above 0, turn counter clockwise
if (motorSpeed > 0){

    digitalWrite(AIN1, HIGH);   //set direction pin 1 HIGH
    digitalWrite(AIN2, LOW);    //set direction pin 2 LOW
}
//if speed is below 0, turn clockwise
else if (motorSpeed < 0){

    digitalWrite(AIN1, LOW);    //set direction pin 1 to LOW
    digitalWrite(AIN2, HIGH);   //set directional pin 2 to HIGH
    }
    //set motor to off if value entered isn't within range
    else {
        digitalWrite(AIN1, LOW);
        digitalWrite(AIN2, LOW);
    }

    analogWrite(PWMA, abs(motorSpeed));



}