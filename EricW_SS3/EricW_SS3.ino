// SENSOR PIN DEFINITIONS
const int potPin_1 = 1;
const int potPin_2 = 2;

const int buttonPin_1 = 4;
const int buttonPin_2 = 5;

// BUTTON VARIABLES
bool buttonState_1 = 0;
bool buttonState_2 = 0;

// POTENTIOMETER VARIABLES
int potValue_1 = 0;
int potValue_2 = 0;

// SOFTWARE TIMER VARIABLES
unsigned long lastTime = 0;
unsigned long currentTime = 0;
int timerInterval = 10;

void setup()
{
  // BUTTON INPUTS
  pinMode(buttonPin_1, INPUT_PULLUP);
  pinMode(buttonPin_2, INPUT_PULLUP);

  // ADC RESOLUTION
  analogReadResolution(12);

  // SERIAL COMMUNICATION
  Serial.begin(9600);
}

void loop()
{
  // READ POTENTIOMETERS
  potValue_1 = analogRead(potPin_1);
  potValue_2 = analogRead(potPin_2);

  
  buttonState_1 = !digitalRead(buttonPin_1);
  buttonState_2 = !digitalRead(buttonPin_2);

  // SOFTWARE TIMER
  currentTime = millis();

  if (currentTime - lastTime >= timerInterval)
  {
    lastTime = currentTime;

    // SEND SERIAL DATA
    Serial.print(buttonState_1);
    Serial.print(",");

    Serial.print(buttonState_2);
    Serial.print(",");

    Serial.print(potValue_1);
    Serial.print(",");

    Serial.print(potValue_2);

    Serial.print("\n");
  }
}