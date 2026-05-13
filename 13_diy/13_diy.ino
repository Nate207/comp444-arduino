/*   Circuit 13 (4C) - DIY WHOAMI

This circuit builds a game where an animal name is displayed and the person cannot see it. The other player
tells them if they correctly guess the animal name.  There is a time limit for each round. If they correctly guess
the animal, they pres the  button and a new animal name appears and resets the countdown. If they guess all 25 animals 
before the countdown completes they win the game.

*/

#include <LiquidCrystal.h>                  //import the LCD screen library
LiquidCrystal lcd(13, 12, 11, 10, 9, 8);   //pins for lcd

int buttonPin = 2;  //button input
int buzzerPin = 6;  //buzzer output

long timeLimit = 15000;     //15 second time limit per round
long startTime = 0;         //start time at 0

int roundNumber = 0;        //current round
const int arraySize = 25;   //number of animal names

const char* words[arraySize] = {

    "beaver", "duck", "squirrel", "otter", "moose", "deer", "wolf", "bear",
    "raven", "cow", "horse", "snake", "coyote", "rabbit", "turtle", "cat",
    "dog", "bison", "sheep", "elk", "marmot", "goose", "owl", "hawk", "cougar"
};

int sequence[] = { -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1}; //random order

void setup() {

    pinMode(buttonPin, INPUT_PULLUP); //setting up button
    lcd.begin(16, 2);                 //size of LCD screen

    generateRandomOrder();             //random order for aniaml names
    showStartSequence();               //start screen
}

void loop() {

    for (int i = 0; i < arraySize; i++){    //loops through all words

        lcd.clear();                //clears screen

        roundNumber = i + 1;        //Round number
        lcd.print(roundNumber);
        lcd.print(": ");
        lcd.print(words[sequence[i]]);  //shows word on screen

        startTime = millis();        //time starts

        while(digitalRead(buttonPin) == HIGH){

            int roundTime = round((timeLimit - (millis() - startTime )) / 1000);  //time left in round

            lcd.setCursor(14, 1);
            lcd.print(" ");
            lcd.setCursor(14, 1);
            lcd.print(roundTime);  //displays time

            delay(15);
            if(millis() - startTime > timeLimit) {
                gameOver();
            }

            if(digitalRead(buttonPin) == LOW) {
                tone(buzzerPin, 272, 10); //short beep

            }
        }
        delay(500); //short delay between rounds
        
    }
    winner();   //completion of all rounds
}


//------------- FUNCTIONS --------------

void showStartSequence(){              //starts count down

    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Category:");
    lcd.setCursor(0, 1);
    lcd.print("Animals");

    delay(2000);

    lcd.clear();
    lcd.print("Get ready!");
    delay(1000);

    lcd.clear();
    lcd.print("3");
    delay(1000);

    lcd.clear();
    lcd.print("2");
    delay(1000);

    lcd.clear();
    lcd.print("1");
    delay(1000);
}

void generateRandomOrder(){     //generates random order

    randomSeed(analogRead(0)); 

    for (int i = 0; i < arraySize; i++){

        int currentNumber = 0;
        boolean match = false;

        do{
            currentNumber = random(0, arraySize);
            match = false;

            for (int i = 0; i < arraySize; i++){
                if (currentNumber == sequence[i]){
                    match = true; 
                }
            }
        } while (match == true);

        sequence[i] = currentNumber;    //stores number
    }
}



void gameOver(){

    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Game Over");

    lcd.setCursor(0, 1);
    lcd.print("Score: ");
    lcd.print(roundNumber - 1);

    tone(buzzerPin, 130, 250);
    delay(275);
    tone(buzzerPin, 73, 250);
    delay(275);
    tone(buzzerPin, 65, 150);
    delay(175);
    tone(buzzerPin, 98, 500);
    delay(500);

    while (true) {}   //stop game

}

void winner() {

    lcd.clear();
    lcd.setCursor(7, 0);
    lcd.print("YOU");

    lcd.setCursor(7, 1);
    lcd.print("WIN!");

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
    tone(buzzerPin, 3135, 500); 
    delay(500);

    while (true){}      //stop game
}