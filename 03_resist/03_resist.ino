// Circuit 1C - Photoresistor

//Declare variables

int photoresistor = 0;
int threshold = 700;

void setup() {
  
Serial.begin(9600);      //start connection with computer

pinMode(13, OUTPUT);     //set pin 13 as output so it can be HIGH or LOW

}

void loop() {
  
  //take reading from light

  photoresistor  = analogRead(A0);    //sets photoresistor to value between 0 and 1023. 10bits so 1024 possible values
  Serial.println(photoresistor);      //prints value of photoresistor in the serial monitor.  

  if (photoresistor < threshold){

    digitalWrite(13, HIGH);           //turns on LED
  }
  else{
    digitalWrite(13, LOW);            //turns off LED
  }

  delay(1000);                         //slows output of readout
}
