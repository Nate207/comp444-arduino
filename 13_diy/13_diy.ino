/*   Circuit 13 (4C) - DIY WHOAMI

This circuit builds a game where an animal name is displayed and the person cannot see it. The other player
tells them if they correctly guess the animal name.  There is a time limit for each round. If they correctly guess
the animal, they pres the  button and a new animal name appears and resets the countdown. If they guess all 25 animals 
before the countdown completes they win the game.

*/

#include <LiquidCrystal.h>                  //import the LCD screen library
Liquid Crystak lcd(13, 12, 11, 10, 9, 8);   //pins for lcd

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

int sequence{arraySize] = }