
const int potPin_1 = 1;
const int potPin_2 = 2;

const int buttonPin_1 = 4;
const int buttonPin_2 = 5;


bool buttonState_1 = 0;
bool buttonState_2 = 0;


int potValue_1 = 0;
int potValue_2 = 0;


unsigned long lastTime = 0;
unsigned long currentTime = 0;
int timerInterval = 10;

void setup()
{
  pinMode(buttonPin_1, INPUT_PULLUP);
  pinMode(buttonPin_2, INPUT_PULLUP);

  analogReadResolution(12);

  Serial.begin(9600);
}

void loop()
{
  potValue_1 = analogRead(potPin_1);
  potValue_2 = analogRead(potPin_2);

  
  buttonState_1 = !digitalRead(buttonPin_1);
  buttonState_2 = !digitalRead(buttonPin_2);

  currentTime = millis();

  if (currentTime - lastTime >= timerInterval)
  {
    lastTime = currentTime;

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