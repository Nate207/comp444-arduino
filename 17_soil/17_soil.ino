/*
    COMP444 Final Project
    Soil Moisture Monitoring System

    Components:
    LCD Display
    Soil Moisture Sensor
    LED light
    Buzzer alarm
    Button

    Moisture Ranges:
    0-20%   = Dry
    20-60%  = Good
    60-100% = Too Wet
*/

#include <LiquidCrystal.h>

// LCD pins
LiquidCrystal lcd(13, 12, 11, 10, 9, 8);

// component pins
const int buttonPin = 2;
const int buzzerPin = 6;
const int ledPin = 7;
const int moisturePin = A0;

// moisture level thresholds
const int dryThreshold = 20;
const int wetThreshold = 60;

// alarm mute variable
bool alarmMuted = false;
unsigned long muteStartTime = 0;
const unsigned long muteDuration = 60000; // 1 minute

void setup()
{
    pinMode(buttonPin, INPUT_PULLUP);
    pinMode(ledPin, OUTPUT);
    pinMode(buzzerPin, OUTPUT);

    lcd.begin(16, 2);

    Serial.begin(9600);

    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Soil Monitor");

    lcd.setCursor(0, 1);
    lcd.print("Starting...");

    delay(2000);

    lcd.clear();
}

void loop()
{
    // read raw value
    int moistureValue = analogRead(moisturePin);

    // convert raw value to percentage
    // calibrated values:
    // 572 = dry air
    // 226 = soaking wet

    int moisturePercent =
        map(moistureValue, 572, 226, 0, 100);

    moisturePercent =
        constrain(moisturePercent, 0, 100);

    // serial monitor output
    Serial.print("Raw Value: ");
    Serial.print(moistureValue);

    Serial.print(" Moisture: ");
    Serial.print(moisturePercent);
    Serial.println("%");

    // check if silence button is pressed
    if (digitalRead(buttonPin) == LOW)
    {
        alarmMuted = true;
        muteStartTime = millis();

        noTone(buzzerPin);

        delay(250); // debounce
    }

    // check silence timer
    if (alarmMuted &&
        millis() - muteStartTime >= muteDuration)
    {
        alarmMuted = false;
    }

    // display moisture percentage
    lcd.clear();

    lcd.setCursor(0, 0);
    lcd.print("Moisture:");

    lcd.setCursor(10, 0);
    lcd.print(moisturePercent);
    lcd.print("%");

    // Dry Condition
    if (moisturePercent < dryThreshold)
    {
        digitalWrite(ledPin, HIGH);

        lcd.setCursor(0, 1);

        if (!alarmMuted)
        {
            tone(buzzerPin, 1000);

            lcd.print("Add Water");
        }
        else
        {
            noTone(buzzerPin);

            lcd.print("Alarm Muted");
        }
    }

    // Wet condition
    else if (moisturePercent > wetThreshold)
    {
        digitalWrite(ledPin, LOW);

        noTone(buzzerPin);

        lcd.setCursor(0, 1);
        lcd.print("Too Wet");
    }

    // Good condition
    else
    {
        digitalWrite(ledPin, LOW);

        noTone(buzzerPin);

        lcd.setCursor(0, 1);
        lcd.print("Soil Good");
    }

    delay(100);
}