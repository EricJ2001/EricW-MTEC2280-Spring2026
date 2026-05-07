// ESP32-S3 Pushbutton LED Pattern Assignment
// LEDs on pins 4, 5, 6, 7
// Pushbutton on pin 8

// LED variables
int led1 = 4;
int led2 = 5;
int led3 = 6;
int led4 = 7;

// Button variable
int buttonPin = 8;

// Pattern variable
int pattern = 0;

// Button state variable
int buttonState = 0;

void setup() {

  // Set LED pins as outputs
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(led4, OUTPUT);

  // Set button pin as input with internal pull-up resistor
  pinMode(buttonPin, INPUT_PULLUP);
}

void loop() {

  // Read button state
  buttonState = digitalRead(buttonPin);

  // If button is pressed
  if (buttonState == LOW) {

    // Go to next pattern
    pattern++;

    // Small delay to prevent multiple presses
    delay(300);

    // Reset back to pattern 0 after pattern 5
    if (pattern > 5) {
      pattern = 0;
    }
  }

  // PATTERN 1
  if (pattern == 0) {

    digitalWrite(led1, HIGH);
    digitalWrite(led2, LOW);
    digitalWrite(led3, LOW);
    digitalWrite(led4, LOW);
  }

  // PATTERN 2
  else if (pattern == 1) {

    digitalWrite(led1, LOW);
    digitalWrite(led2, HIGH);
    digitalWrite(led3, LOW);
    digitalWrite(led4, LOW);
  }

  // PATTERN 3
  else if (pattern == 2) {

    digitalWrite(led1, LOW);
    digitalWrite(led2, LOW);
    digitalWrite(led3, HIGH);
    digitalWrite(led4, LOW);
  }

  // PATTERN 4
  else if (pattern == 3) {

    digitalWrite(led1, LOW);
    digitalWrite(led2, LOW);
    digitalWrite(led3, LOW);
    digitalWrite(led4, HIGH);
  }

  // PATTERN 5
  else if (pattern == 4) {

    digitalWrite(led1, HIGH);
    digitalWrite(led2, HIGH);
    digitalWrite(led3, LOW);
    digitalWrite(led4, LOW);
  }

  // PATTERN 6
  else {

    digitalWrite(led1, HIGH);
    digitalWrite(led2, HIGH);
    digitalWrite(led3, HIGH);
    digitalWrite(led4, HIGH);
  }
}