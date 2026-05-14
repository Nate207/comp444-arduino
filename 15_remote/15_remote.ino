/* Circuit 15 (5B) - Remote Control Robot

Robot takes input from serial monitor and robot executes input

f 50 - move forward
b 50 move backward
r 90 = turn right
l 90 = turn left

*/

//pins for right motor 
const int AIN1 = 13;
const int AIN2 = 12;
const int PWMA = 11;

//pins for left motor
const int PWMB = 10;
const int BIN2 = 9;
const int BIN1 = 8;

//on/off switch pin
int switchPin = 7;

//timing values
//driveTime controls forward/back distance
//turnTime controls turning distance
const int driveTime = 20;
const int turnTime = 8;

//variables to store input
String botDirection;
String distance;

void setup(){

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

    //user instructions
    Serial.println("Enter a direction and distance");
    Serial.println("f = forward");
    Serial.println("b = backward");
    Serial.println("r = right turn");
    Serial.println("l = left turn");
    Serial.println("Example : f 50");

}

void loop(){

    //run only if switch is on
    if (digitalRead(7) == LOW)
    {    
        //check if user entered command
     
       if (Serial.available() > 0)
        {
            //read direciton until space
            botDirection = Serial.readStringUntil(' ');

            //read distance after space
            distance = Serial.readStringUntil(' ');

            //print command back to serial monitor
            Serial.print(botDirection);
            Serial.print(" ");
            Serial.println(distance.toInt());

            //move forward
            if (botDirection == "f")
            {
                //both wheels move forward
                rightMotor(200);
                leftMotor(200);

                //move entered disatance
                delay(driveTime * distanceToInt());
                
                //stop motors
                rightMotor(0);
                leftMotor(0);
            }
            else if (botDirection == "b")
            {
                //both wheels move backward

                rightMotor(-200);
                leftMotor(-200);

                //move entered distance
                delay(driveTime * distanceToInt());

                //stop motors
                rightMotor(0);
                leftMotor(0);
            }
            else if (botDirection == "r")
            {

                //right wheel forwrd, left wheel back
                rightMotor(255);
                leftMotor(-200);

                //turn entered distance
                delay(turnTime * distanceToInt());

                //stop motors
                rightMotor(0);
                leftMotor(0);
            }
            else if (botDirection == "l")
            {

                //left forward, right back
                rightMotor(-200);
                leftMotor(255);

                //move entered distance
                delay(turnTime * distanceToInt());

                //stop motors
                rightMotor(0);
                leftMotor(0);
            }
            
        }
    }

    //stop motors if switch is off
    else
    {
        rightMotor(0);
        leftMotor(0);
    }
}


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
