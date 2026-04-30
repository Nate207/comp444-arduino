// Circuit 1D - RGB Nightlight - Red Pulse




int photoresistor = A0;          //photoresistor value
int potentiometer = A1;          //position of the knob
int threshold = 750;            //if the photoresistor reading is lower than this value the light will turn on


//LEDs are connected to these pins
int RedPin = 9;
int GreenPin = 10;
int BluePin = 11;

void setup() {
  Serial.begin(9600);           //start a serial connection with the computer

  //set the LED pins to output
  pinMode(RedPin, OUTPUT);
  pinMode(GreenPin, OUTPUT);
  pinMode(BluePin, OUTPUT);
}

void loop() {

  photoresistor = analogRead(A0);         //read the value of the photoresistor
  potentiometer = analogRead(A1);

  
  
  Serial.print("Light: ");
  Serial.print(photoresistor);
  Serial.print("  Threshold: ");
  Serial.println(threshold);

  if (photoresistor < threshold) {

  int colourRange = potentiometer / 150;

  switch(colourRange) {

    case 0:
      red();
      break;

    case 1:
      orange();
      break;

    case 2:
      yellow();
      break;

    case 3:
      green();
      break;

    case 4:
      cyan();
      break;

    case 5:
      blue();
      break;

    case 6:
      magenta();
      break;
  }

  
    } else{
      turnOff();

    
    }
  

  delay(100);                             //short delay so that the printout is easier to read
}

void red () {

  //set the LED pins to values that make red
  for (int brightness = 0; brightness <= 100; brightness++){
      analogWrite(RedPin, brightness);
      analogWrite(GreenPin, 0);
      analogWrite(BluePin, 0);
      delay(10);
  }

  for (int brightness = 100; brightness >= 0; brightness--){
    analogWrite(RedPin, brightness);
    delay(10);
  }
  }

void orange () {

  //set the LED pins to values that make orange
  analogWrite(RedPin, 100);
  analogWrite(GreenPin, 50);
  analogWrite(BluePin, 0);
}
void yellow () {

  //set the LED pins to values that make yellow
  analogWrite(RedPin, 100);
  analogWrite(GreenPin, 100);
  analogWrite(BluePin, 0);
}
void green () {

  //set the LED pins to values that make green
  analogWrite(RedPin, 0);
  analogWrite(GreenPin, 100);
  analogWrite(BluePin, 0);
}
void cyan () {

  //set the LED pins to values that make cyan
  analogWrite(RedPin, 0);
  analogWrite(GreenPin, 100);
  analogWrite(BluePin, 100);
}
void blue () {

  //set the LED pins to values that make blue
  analogWrite(RedPin, 0);
  analogWrite(GreenPin, 0);
  analogWrite(BluePin, 100);
}
void magenta () {

  //set the LED pins to values that make magenta
  analogWrite(RedPin, 100);
  analogWrite(GreenPin, 0);
  analogWrite(BluePin, 100);
}
void turnOff () {

  //set all three LED pins to 0 or OFF
  analogWrite(RedPin, 0);
  analogWrite(GreenPin, 0);
  analogWrite(BluePin, 0);
}


