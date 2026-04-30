// Circuit 6 (2B)-ButtonTrumpet

//set the pins for the button and buzzer
int firstKeyPin = 2;
int secondKeyPin = 3;
int thirdKeyPin = 4;

int buzzerPin = 10;


void setup() {
  //set the button pins as inputs
  pinMode(firstKeyPin, INPUT_PULLUP);
  pinMode(secondKeyPin, INPUT_PULLUP);
  pinMode(thirdKeyPin, INPUT_PULLUP);

  //set the buzzer pin as an output
  pinMode(buzzerPin, OUTPUT);
}

void loop() {

  if (digitalRead(firstKeyPin) == LOW) {      //if the first key is pressed
    tone(buzzerPin, 262);                     //play the frequency for c
  }
  else if (digitalRead(secondKeyPin) == LOW) { //if the second key is pressed
    tone(buzzerPin, 330);                     //play the frequency for e
  }
  else if (digitalRead(thirdKeyPin) == LOW) { //if the third key is pressed
    tone(buzzerPin, 392);                     //play the frequency for g
  }
  else {
    noTone(buzzerPin);                        //if no key is pressed turn the buzzer off
  }
}


