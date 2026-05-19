const int led1 = 1;
const int led2 = 20;
const int led3 = 4;

const int buttonPin = 16;

bool buttonState = 0;
bool lastButtonState = 0;

int val = 0;

void setup()
{
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);

  pinMode(buttonPin, INPUT_PULLUP);

  Serial.begin(9600);
}

void loop()
{
  buttonState = !digitalRead(buttonPin);

  if (Serial.available())
  {
    String incoming = Serial.readStringUntil('\n');

    incoming.trim();

    if (incoming == "A")
    {
      if (buttonState && !lastButtonState)
      {
        Serial.println("1");
      }
      else
      {
        Serial.println("0");
      }
    }

    else if (incoming.startsWith("M"))
    {
      val = incoming.substring(1).toInt();
    }
  }

  lastButtonState = buttonState;

  if (val == 0)
  {
    digitalWrite(led1, LOW);
    digitalWrite(led2, LOW);
    digitalWrite(led3, LOW);
  }

  else if (val < 120)
  {
    digitalWrite(led1, HIGH);
    digitalWrite(led2, LOW);
    digitalWrite(led3, LOW);

    delay(20);

    digitalWrite(led1, LOW);
    digitalWrite(led2, HIGH);
    digitalWrite(led3, LOW);

    delay(20);

    digitalWrite(led1, LOW);
    digitalWrite(led2, LOW);
    digitalWrite(led3, HIGH);

    delay(20);
  }

  else if (val < 200)
  {
    digitalWrite(led1, HIGH);
    digitalWrite(led2, HIGH);
    digitalWrite(led3, LOW);

    delay(30);

    digitalWrite(led1, LOW);
    digitalWrite(led2, HIGH);
    digitalWrite(led3, HIGH);

    delay(30);
  }

  else
  {
    digitalWrite(led1, HIGH);
    digitalWrite(led2, HIGH);
    digitalWrite(led3, HIGH);

    delay(35);

    digitalWrite(led1, LOW);
    digitalWrite(led2, LOW);
    digitalWrite(led3, LOW);

    delay(35);
  }

  delay(2);
}