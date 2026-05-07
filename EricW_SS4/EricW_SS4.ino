
const int ledPin_1 = 4;
const int ledPin_2 = 5;

int serialValue = 0;

int ledBrightness_1 = 0;
int ledBrightness_2 = 0;

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
  
  if (Serial.available() > 0)
  {
    serialValue = Serial.parseInt();

    
    ledBrightness_1 = map(serialValue, 0, 1000, 0, 255);

    ledBrightness_1 = constrain(ledBrightness_1, 0, 255);


    ledBrightness_2 = map(serialValue, 0, 1000, 255, 0);

    ledBrightness_2 = constrain(ledBrightness_2, 0, 255);
  }

  currentTime = millis();

  if (currentTime - lastTime >= timerInterval)
  {
    lastTime = currentTime;

    analogWrite(ledPin_1, ledBrightness_1);

    analogWrite(ledPin_2, ledBrightness_2);
  }
}