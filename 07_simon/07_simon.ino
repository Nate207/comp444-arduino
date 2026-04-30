/*

Circuit 7 - 2C

Simon Says game


*/

// set pins where the buttons, LED and buzzer connect

int button[] = {2, 4, 6, 8};        // Button red is index 0, yellow index 1, green index 2, blue index 3
int led[] = {3, 5, 7, 9};           // LED red is index 0, yellow index 1, green index 2, blue index 3
int tones[] = {262, 330, 392, 494}; // tones to play with each button (c, e g, b)

int roundsToWin = 10;           //number of rounds the player has to win to win game
int buttonSequence[16];         //make an array of numbers that will be sequence player has to remember

int buzzerPin = 10;             //pin 10 for buzzer

int pressedButton = 4;          //variable to remember which button is pressed. 4 is no button pressed.
int roundCounter = 1;           //tracks which round player is on

long startTime = 0;             //time variable for time limit on button press
long timeLimit = 2000;          //time to hit button

boolean gameStarted = false;    //variable to tell game to start or not to play start sequence

void setup() {

    //set all button pins to input_pullup to use built in resistors

    pinMode(button[0], INPUT_PULLUP);
    pinMode(button[1], INPUT_PULLUP);
    pinMode(button[2], INPUT_PULLUP);
    pinMode(button[3], INPUT_PULLUP);

    //set LEDs pins to output
    pinMode(led[0], OUTPUT);
    pinMode(led[1], OUTPUT);
    pinMode(led[2], OUTPUT);
    pinMode(led[3], OUTPUT);

    pinMode(buzzerPin, OUTPUT); //set buzzerPin variable to output

}

void loop() {

    if (gameStarted == false){  //if game hasn't started yet
        startSequence();        //initiate start sequence   
        roundCounter = 0;       //reset round counter
        delay(1500);            //wait 1.5 seconds
        gameStarted = true;     //set gameStarted to true so it doesn't start again
    }
//each round start by flashing out sequence to be repeated
for (int i = 0; i <= roundCounter; i++) {   //go through array up to current round number
    flashLED(buttonSequence[i]);            //turn on LED for that array position and sound
    delay(200);                            //wait 2 seconds
    allLEDoff();                            //turn all LEDs off
    delay(200);   
}

//start going throught sequence one at a time and see if user presses right button
    for (int i = 0; i <= roundCounter; i++){    //for each button pressed in the sequence

        startTime = millis();                   //record start time

        while (gameStarted == true) {           //loop until player presses a button or the time limit is up (if statement)
            pressedButton = buttonCheck();      //every loop check to see which button is pressed

            if (pressedButton < 4){             //if button is pressed. 4 is no button
                
                flashLED(pressedButton);        //flash LED for button pressed

                if (pressedButton == buttonSequence[i]){    //if button pressed matches button in sequence
                    delay(250);                             //leave LED on for a moment
                    allLEDoff();                            //turn off all LED
                    break;                                  //end while loop and it will go to next number in the for loop
                } else {
                    loseSequence();
                    break;
                }

            }else{              //if no button is pressed
                allLEDoff();    //turn off LEDs
            }

            //check to see if time is up
            if (millis() - startTime > timeLimit){  //if time limit is up
                loseSequence();                 //play lose sequence
                break;
            }


        }
    }

    if (gameStarted == true) {
        roundCounter = roundCounter +1;

        if (roundCounter >= roundsToWin){   //if player has gone to 16th round
            winSequence();                  //play win sequence
        }
        delay(500);     //wait half second between rounds
    }
}



//----------- FUNCTIONS OF GAME  -----------

//FLASH LED
void flashLED (int ledNumber) {
    digitalWrite(led[ledNumber], HIGH);
    tone(buzzerPin, tones[ledNumber]);
}

//TURN ALL LEDs OFF
void allLEDoff() {
    digitalWrite(led[0], LOW);
    digitalWrite(led[1], LOW);
    digitalWrite(led[2], LOW);
    digitalWrite(led[3], LOW);
    //turn off buzzer
    noTone(buzzerPin);
}

//CHECK WHICH BUTTON IS PRESSED
int buttonCheck() {
    //check if any buttons are being pressed
    if (digitalRead(button[0]) == LOW){
        return 0;
    }else if (digitalRead(button[1]) == LOW){
        return 1;
    }else if (digitalRead(button[2]) == LOW){
        return 2;
    }else if (digitalRead(button[3]) == LOW){
        return 3;
    }else{
        return 4;
    }
}

//START SEQUENCE
void startSequence(){
    
    randomSeed(analogRead(A0));     //make sure the random numbers are random

    for (int i = 0; i <= roundsToWin; i++) {
    //populate buttonSequence with random numbers
    buttonSequence[i] = random(0, 4);
}

//flash LEDs at start of game
for (int i = 0; i <=3; i++) {
    tone(buzzerPin, tones[i], 200); //play one of the 4 tones

    //turn all of the LEDs on
    digitalWrite(led[0], HIGH);
    digitalWrite(led[1], HIGH);
    digitalWrite(led[2], HIGH);
    digitalWrite(led[3], HIGH);

    delay(100);

    //turn all the LEDS off
    digitalWrite(led[0], LOW);
    digitalWrite(led[1], LOW);
    digitalWrite(led[2], LOW);
    digitalWrite(led[3], LOW);

    delay(100);
}
}

//WIN SEQUENCE
void winSequence(){
        //turn on allLEDS
    for( int j = 0; j <= 3; j++){
        digitalWrite(led[j], HIGH);
}

//play the 1UP noise
    tone(buzzerPin, 1318, 150);
    delay(175);
    tone(buzzerPin, 1567, 150);
    delay(175);
    tone(buzzerPin, 2637, 150);
    delay(175);
    tone(buzzerPin, 2093, 150);
    delay(175);
    tone(buzzerPin, 2349, 150);
    delay(175);
    tone(buzzerPin, 3135, 150);
    delay(500);

    //wait until button is pressed
    do {
        pressedButton = buttonCheck();
    } while (pressedButton > 3);
    delay(100);

    gameStarted = false;        //reset game so that start sequence will play again
}

//LOSE SEQUENCE

void loseSequence(){

    //turn LEDs on
    for (int j = 0; j <= 3; j++){
    digitalWrite(led[j], HIGH);
    }

    //play 1UP noise
    tone(buzzerPin, 130, 250);
    delay(275);
    tone(buzzerPin, 73, 250);
    delay(275);
    tone(buzzerPin, 65, 150);
    delay(175);
    tone(buzzerPin, 98, 6500);
    delay(500);

    //wait until button is pressed
    do{
        pressedButton = buttonCheck();
    } while (pressedButton > 3);
    delay(200);

    gameStarted = false; // reset game sequence

}