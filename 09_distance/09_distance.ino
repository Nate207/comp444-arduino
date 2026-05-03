/* Circuit 9 (3B) -Distance Sensor

  Change colour of LED as sensor detects objects at certain ranges.

  This code fades the colour as the objects nears or backs away.

*/

const int trigPin = 11;         //sets trigger of sensor to pin 11
const int echoPin = 12;         //sets the echo pin to pin 12

const int redPin = 3;           // sets red LED to pin 3
const int greenPin = 5;         //sets green LED to pin 5
const int bluePin = 6;          //sets blue LED to pin 6 even though we don't use it  

float distance = 0;             // stores distance variable as decimal 


void setup()
{
  Serial.begin (9600);       //allows output to print in serial monitor

  pinMode(trigPin, OUTPUT);   //sets trigger put to output
  pinMode(echoPin, INPUT);   //echo pin will measure duration of pulses from distance sensor

  //sets LEDs to output
  pinMode(redPin, OUTPUT); 
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
}

void loop() {
  distance = getDistance(); //function for measuring distance

  Serial.print(distance); //prints distance in inches
  Serial.println(" in");  //for display purposes

  float maxDistance = 30.0; //sets max distance for mapping function

  if (distance > maxDistance) { //if distance exceeds max, set it to max
    distance = maxDistance;
  }

  //converts distance to LED brightness in proportion
  int greenValue = map(distance, 0, maxDistance, 0, 255); 
  int redValue = 255 - greenValue;

  //sets brightness of LEDs, keeping blue off
  //brightness based on distance values
  analogWrite(redPin, redValue);
  analogWrite(greenPin, greenValue);
  analogWrite(bluePin, 0);

  //delay before reading
  delay(50);
}




float getDistance()
{
  float echoTime;                   //time for sound to travel
  float calculatedDistance;         //calculates final distance

  //send out an ultrasonic pulse that's 10ms long
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  echoTime = pulseIn(echoPin, HIGH);     //measure how long echPin stays HIGH
 

  calculatedDistance = echoTime / 148.0; //converts time to inches

  return calculatedDistance;      //returns distance to loop()
}
