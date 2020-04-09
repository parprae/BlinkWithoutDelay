/*
  Blink Without Delay
  Kara Ngamsopee
*/

#include <analogWrite.h>

//the numbers of LED pins
const int Green = 12;
const int White = 27;

//declaring value
long previousMillis = 0;
String currentLight = "green";

//time before switching from "green" to "white"
long interval = 1000;

void setup() {

  //initialize serial communication at 9600 bits per second
  Serial.begin(9600);

  //outputs
  pinMode(Green, OUTPUT);
  pinMode(White, OUTPUT);

}

void loop() {

  //declaring value
  unsigned long currentMillis = millis();

  //switch between the different colors
  //if it's current on one color, it will display that color then assign it to the next color
  if ((currentMillis - previousMillis > interval) && (currentLight == "green")) {

    previousMillis = currentMillis;

    analogWrite(Green, 255);
    analogWrite(White, 0);

    currentLight = "white";

  } else if ((currentMillis - previousMillis > interval) && (currentLight == "white")) {
    previousMillis = currentMillis;

    analogWrite(Green, 0);
    analogWrite(White, 255);


    currentLight = "green";
  }

}
