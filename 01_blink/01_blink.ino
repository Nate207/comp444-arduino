/*  Circuit 1 - 1A - Blink an LED

Program has two functions

setup for setting up the program

loop makes LED blink by turning LED on, pausing, turning it off, pausing and loops forever.

*/

void setup() {

  pinMode(13, OUTPUT);      //sets pin 13 on Red Board to output. Connects to LED. 

}


void loop() {

  digitalWrite(13, HIGH);   //HIGH turns LED ON

  delay(2000);              //waits 2000 ms (2 s)

  digitalWrite(13, LOW);    //LOW turns off LED

  delay(2000);              ////waits 2000 ms (2 s)

}
