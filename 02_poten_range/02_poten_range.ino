/* Circuit 2 (1B) - Potentiometer - Range Change

Change range of potPosition

*/

int potPosition;       //this variable will hold a value based on the position of the potentiometer

void setup()
{
  Serial.begin(9600);       //start a serial connection with the computer

  pinMode(13, OUTPUT);  
  pinMode(8, OUTPUT);    //set pin 13 as an output that can be set to HIGH or LOW
}

void loop()
{
  //read the position of the pot
  potPosition = 2* analogRead (A0);    //increase range to 2*
  Serial.println(potPosition);     //print the value of potPosition

  //change the LED blink speed based on the pot value
  digitalWrite(13, HIGH);           //Turn on the LED
  delay(potPosition);              //delay for as many milliseconds as potPosition (0-2046)

  digitalWrite(13, LOW);            // Turn off the LED
  delay(potPosition);              // delay for as many milliseconds as potPosition (0-2046)

  
  //change the LED blink speed based on the pot value
  digitalWrite(8, HIGH);           // Turn on the LED
              

}

