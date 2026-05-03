/* Circuit 4A-HelloWorld

Print a message to an LCD display using a potentiometer to control the contrast of the screen. 

*/

#include <LiquidCrystal.h>          //imports the LCD library

LiquidCrystal lcd(13, 12, 11, 10, 9, 8);   //assign LCD pins to Red Board pins

int moisture = 5;         //set moisture variable to 5

void setup() {

  lcd.begin(16, 2);                 //informs the library that we are using an LCD screen 16 characters wide and 2 high
  lcd.clear();                      //clear the display
}

void loop() {

  lcd.setCursor(0, 0);              //set the cursor to the 0,0 position (top left corner)
  lcd.print("Moisture: ");          // prints the characters in quote
  lcd.setCursor(15, 0);             //places integer at right most of first row.
  lcd.print(moisture);               // prints value of moisture

  lcd.setCursor(0, 1);              //put cursor to first character in bottom row
  lcd.print("Too much water!");   // prints message
}
