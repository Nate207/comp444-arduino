/* Circuit 16 (5C) - Autonomous Robot

This program is modified to reduce the speed of the robot for 
battery consumption */


// right motor pins
const int AIN1 = 13;
const int AIN2 = 12;
const int PWMA = 11;

//left motor pins
const int PWMB = 10;
const int BIN2 = 9;
const int BIN1 = 8;

//distance sensor pins
const int trigPin = 6;
const int echoPin = 5;

//on/off switch pin
const int switchPin = 7;

//stores distance value from sensor
float distance = 0;

//movement timing
int backUpTime = 300;
int turnTime = 250;

//reduced motor speed
int motorSpeed = 180;

void setup(){
    //setup distance sensor
    pinMode(trigPin, OUTPUT);
    pinMode(echoPin, INPUT);


    //setup switch pin
    pinMode(switchPin, INPUT_PULLUP);

    //setup right motor pins
    pinMode(AIN1, OUTPUT);
    pinMode(AIN2, OUTPUT);
    pinMode(PWMA, OUTPUT);

    //setup left motor pins
    pinMode(BIN1, OUTPUT);
    pinMode(BIN2, OUTPUT);
    pinMode(PWMB, OUTPUT);

    //start serial comms
    Serial.begin(9600);
    Serial.println("To infinity and beyond!");
}

void loop(){

    //read distance from sensor
    distance = getDistance();

    //print distance reading
    Serial.print("Distance: ");
    Serial.print(distance);
    Serial.println(" in");

    //run when switch is on
    if (digitalRead(switchPin) == LOW){

        //if obstacle closer than 10in
        if (distance < 10){
            Serial.println("BACK!");

            //stop for a moment
            rightMotor(0);
            leftMotor(0);
            delay(200);

            //backup
            rightMotor(-motorSpeed);
            leftMotor(-motorSpeed);
            delay(backUpTime);

            //turn away from obstacle
            rightMotor(motorSpeed);
            leftMotor(-motorSpeed);
            delay(turnTime);
        }
        else{
            Serial.println("Moving ...");

            rightMotor(motorSpeed);
            leftMotor(motorSpeed);

        }
    }

    //stop if switch off
    else{
        rightMotor(0);
        leftMotor(0);
    }

    //delay between readings
    delay(50);

}

//function to control right motor

void rightMotor(int motorSpeed){

    //move forward
    if (motorSpeed > 0){
        digitalWrite(AIN1, HIGH);
        digitalWrite(AIN2, LOW);
    }

    else if (motorSpeed < 0){

        digitalWrite(AIN1, LOW);
        digitalWrite(AIN2, HIGH);
    }

    else{

        digitalWrite(AIN1, LOW);
        digitalWrite(AIN2, LOW);
        }

        //set motor speed using PWM
        analogWrite(PWMA, abs(motorSpeed));
}

void leftMotor(int motorSpeed){

    //move forward
    if (motorSpeed > 0){

        digitalWrite(BIN1, HIGH);
        digitalWrite(BIN2, LOW);
    }
    //move backward
    else if (motorSpeed < 0){
        digitalWrite(BIN1, LOW);
        digitalWrite(BIN2, HIGH);
    }

    //stop motor
    else{
        digitalWrite(BIN1, LOW);
        digitalWrite(BIN2, LOW);

    }

    //set motor speed using PWM
    analogWrite(PWMB, abs(motorSpeed));
}

float getDistance(){

    float echoTime;
    float calculatedDistance;

    //send ultrasonic pulse
    digitalWrite(trigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin, LOW);

    //measure return pulse
    echoTime = pulseIn(echoPin, HIGH);

    //convert time to distance in inches
    calculatedDistance = echoTime / 148.0;

    return calculatedDistance;
}