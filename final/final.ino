const int led1 = 1;
const int led2 = 20;
const int led3 = 4;

const int buttonPin = 41;

bool buttonState = 0;

int inByte = 0;

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
  // READ BUTTON
  buttonState = !digitalRead(buttonPin);

  // SERIAL COMMUNICATION
  if (Serial.available())
  {
    inByte = Serial.read();

    // HANDSHAKE
    if (inByte == 'A')
    {
      // SEND BUTTON STATE + LED VALUE
      Serial.print(buttonState);

      Serial.print(',');

      Serial.print(val);

      Serial.print('\n');
    }
else if (inByte == 'B') //if incoming byte is 'B'...
    {
      //digitalWrite(ledPin, 0);  //turn LED OFF
      Serial.println("Sensor Update Paused...");  //send paused status message
      //using Serial.println adds a newline after each print, so no need for Serial.print('/n')
    }
    else //if incoming byte is neither 'A' nor 'B'...
    {
      //digitalWrite(ledPin, 0);  //turn LED OFF
      Serial.println("Rx Byte is neither 'A' nor 'B'"); //send status message
      val = inByte;
    }
    // MUSIC VALUES
    //  else
    // {
    //   val = inByte;
    // }
  }

  // LED OFF
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
}