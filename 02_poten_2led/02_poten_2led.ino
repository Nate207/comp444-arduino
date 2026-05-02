/* Circuit 2 (1B) - Potentiometer - Additonal LED

  
*/

int potPosition;       //this variable will hold a value based on the position of the potentiometer

void setup()
{
  Serial.begin(9600);       //start a serial connection with the computer to view sensor values
                            //in serial monitor 

  pinMode(13, OUTPUT);  //LED output
  pinMode(8, OUTPUT);   //Additional LED output. This one will not blink. 
}

void loop()
{
  //read the position of the pot
  potPosition = analogRead (A0);    //set potPosition to a number between 0 and 1023 
  Serial.println(potPosition);     //print the value of potPosition in the serial monitor 

  //change the LED blink speed based on the pot value
  digitalWrite(13, HIGH);           // Turn on the LED
  delay(potPosition);              // delay for as many milliseconds as potPosition (0-1023)

  digitalWrite(13, LOW);            // Turn off the LED
  delay(potPosition);              // delay for as many milliseconds as potPosition (0-1023)

  
  //change the LED blink speed based on the pot value
  digitalWrite(8, HIGH);           // Turn on the LED
              

}

