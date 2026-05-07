// ESP32-S3 LED Pattern Assignment
// LEDs connected to GPIO 4, 5, 6, 7

// LED pin variables
int led1 = 4;
int led2 = 5;
int led3 = 6;
int led4 = 7;

// Pattern tracking variable
int pattern = 0;

// Delay variable
int waitTime = 500;

void setup() {

  // Set pins as outputs
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(led4, OUTPUT);
}

void loop() {

  // PATTERN 1
  if (pattern == 0) {

    digitalWrite(led1, HIGH);
    digitalWrite(led2, LOW);
    digitalWrite(led3, LOW);
    digitalWrite(led4, LOW);

    delay(waitTime);
  }

  // PATTERN 2
  else if (pattern == 1) {

    digitalWrite(led1, LOW);
    digitalWrite(led2, HIGH);
    digitalWrite(led3, LOW);
    digitalWrite(led4, LOW);

    delay(waitTime);
  }

  // PATTERN 3
  else if (pattern == 2) {

    digitalWrite(led1, LOW);
    digitalWrite(led2, LOW);
    digitalWrite(led3, HIGH);
    digitalWrite(led4, LOW);

    delay(waitTime);
  }

  // PATTERN 4
  else if (pattern == 3) {

    digitalWrite(led1, LOW);
    digitalWrite(led2, LOW);
    digitalWrite(led3, LOW);
    digitalWrite(led4, HIGH);

    delay(waitTime);
  }

  // PATTERN 5
  else if (pattern == 4) {

    digitalWrite(led1, HIGH);
    digitalWrite(led2, HIGH);
    digitalWrite(led3, LOW);
    digitalWrite(led4, LOW);

    delay(waitTime);
  }

  // PATTERN 6
  else {

    digitalWrite(led1, HIGH);
    digitalWrite(led2, HIGH);
    digitalWrite(led3, HIGH);
    digitalWrite(led4, HIGH);

    delay(waitTime);
  }

  // Move to next pattern
  pattern++;

  // Comparator conditional statement
  if (pattern > 5) {
    pattern = 0;
  }
}