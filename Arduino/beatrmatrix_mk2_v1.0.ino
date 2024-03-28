#include <Adafruit_NeoPixel.h>
#include <Bounce2.h>

#define PIN            12  // Pin to which WS2812 LEDs are connected
#define NUM_LEDS       16  // Number of WS2812 LEDs

const int ROWS = 5;
const int COLS = 4;
char keys[ROWS][COLS] = {
  {'A', 'B', 'C', 'D'},
  {'E', 'F', 'G', 'H'},
  {'I', 'J', 'K', 'L'},
  {'M', 'N', 'O', 'P'},
  {'Q', 'R', 'S', 'T'}
};
int rowPins[ROWS] = {2, 3, 4, 5, 10};
int colPins[COLS] = {6, 7, 8, 9};

Bounce debouncers[ROWS][COLS];

// Define the analog input pins for the potentiometers
const int potPin1 = A6;
const int potPin2 = A5;
const int potPin3 = A7;

int prevPotValue1 = 0;
int prevPotValue2 = 0;
int prevPotValue3 = 0;

const int hysteresis = 2;  // Adjust the hysteresis value as needed

Adafruit_NeoPixel strip = Adafruit_NeoPixel(NUM_LEDS, PIN, NEO_GRB + NEO_KHZ800);

void setup() {
  Serial.begin(19200);
  strip.begin();
  strip.show();  // Initialize all pixels to 'off'

  while (!Serial);

  for (int r = 0; r < ROWS; r++) {
    for (int c = 0; c < COLS; c++) {
      pinMode(colPins[c], OUTPUT);
      digitalWrite(colPins[c], HIGH);
      pinMode(rowPins[r], INPUT_PULLUP);
      debouncers[r][c].attach(rowPins[r]);
      debouncers[r][c].interval(10);
    }
  }

}

void loop() {

  // Read potentiometer values
  int potValue1 = map(analogRead(potPin1), 0, 1023, 127, 0);
  int potValue2 = map(analogRead(potPin2), 0, 1023, 127, 0);
  int potValue3 = map(analogRead(potPin3), 0, 1023, 127, 0);

  // Apply hysteresis to potentiometer values
  if (abs(potValue1 - prevPotValue1) > hysteresis ||
      abs(potValue2 - prevPotValue2) > hysteresis ||
      abs(potValue3 - prevPotValue3) > hysteresis) {
    // Check for changes and print to Serial
Serial.print("p1 ");
Serial.println(potValue1);
Serial.print("p2 ");
Serial.println(potValue2);
Serial.print("p3 ");
Serial.println(potValue3);

    // Update previous values
    prevPotValue1 = potValue1;
    prevPotValue2 = potValue2;
    prevPotValue3 = potValue3;
  }


for (int c = 0; c < COLS; c++) {
    digitalWrite(colPins[c], LOW);
    for (int r = 0; r < ROWS; r++) {
      debouncers[r][c].update();
      if (debouncers[r][c].fell()) {
        Serial.println(keys[r][c]);
      }
    }
    digitalWrite(colPins[c], HIGH);
  } 


while (Serial.available() > 0) {
    // Read the serial input
    char command = Serial.read();

    // Check if the command is 'C' for color setting
    if (command == 'C') {
      // Read LED index and RGB values from serial
      int ledIndex = Serial.parseInt();
      int red = Serial.parseInt();
      int green = Serial.parseInt();
      int blue = Serial.parseInt();

      // Check if LED index is within the valid range
      if (ledIndex >= 0 && ledIndex < NUM_LEDS) {
        // Set the color for the specified LED
        strip.setPixelColor(ledIndex, red, green, blue);
      }
    } else if (command == 'O') {
      // Turn off all LEDs
      for (int i = 0; i < NUM_LEDS; i++) {
        strip.setPixelColor(i, 0, 0, 0); // Set color to black (off)
      }
    }

    // Skip until the end of the line or buffer is empty
    while (Serial.available() > 0 && Serial.peek() != '\n') {
      Serial.read();
    }

    // Consume the newline character
    if (Serial.available() > 0) {
      Serial.read();
    }
  }

delay(5);
strip.show();
}
