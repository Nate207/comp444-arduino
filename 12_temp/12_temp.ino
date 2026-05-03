/* Circuit 12 (4B) - Temperature Sensor

This circuit senses the temperature with a sensor and displays the value on the LCD screen
*/


#include <LiquidCrystal.h>      //import LCD library

LiquidCrystal lcd(13, 12, 11, 10, 9, 8);  //connect LCD to pins

float voltage = 0;    //sensor voltage
float degreesC = 0;   // temp in Celcius
float degreesF = 0;   //temp in farhenheit

void setup(){

  lcd.begin(16, 2);   //sets LCD screen size
  lcd.clear();
}

void loop(){

voltage = analogRead(A0) * 0.004882813;     //read sensor and convert to voltage
degreesC = (voltage -0.5) * 100.0;          //converts to celcius
degreesF = degreesC * (9.0 / 5.0) + 32.0;   //converts to farhenheit

lcd.clear();

lcd.setCursor(0, 0);      //put at first position in top row
lcd.print("Degrees C: "); //display string
lcd.print(degreesC);      //print variable after string

lcd.setCursor(0, 1);      //put at first position in bottom
lcd.print("Degrees F: ");  
lcd.print(degreesF);

delay(1000);        //take a reading every second

}

