
const int ledPin_1 = 4;
const int ledPin_2 = 5;

int ledValue_1 = 0;
int ledValue_2 = 0;

unsigned long currentTime = 0;
unsigned long lastTime = 0;

int timerInterval = 10;

void setup()
{
  pinMode(ledPin_1, OUTPUT);

  pinMode(ledPin_2, OUTPUT);

  Serial.begin(9600);
}

void loop()
{
  // SERIAL FORMAT:
  // value1,value2

  if (Serial.available() > 0)
  {
    ledValue_1 = Serial.parseInt();

    ledValue_2 = Serial.parseInt();

    ledValue_1 = constrain(ledValue_1, 0, 255);

    ledValue_2 = constrain(ledValue_2, 0, 255);
  }

  currentTime = millis();

  if (currentTime - lastTime >= timerInterval)
  {
    lastTime = currentTime;

    analogWrite(ledPin_1, ledValue_1);

    analogWrite(ledPin_2, ledValue_2);
  }
}