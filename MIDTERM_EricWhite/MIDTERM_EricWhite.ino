const int potPin = 4;     // potentiometer
const int led1 = 7;       // LED 1 (brightness)

const int buttonPin = 20; 
const int led2 = 1;       

bool led2State = false;
bool lastButtonState = HIGH;
bool blinkMode = false;   // false = slow, true = fast

void setup() {
  pinMode(buttonPin, INPUT_PULLUP);  // IMPORTANT
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);

  Serial.begin(115200);

  // PWM (for LED1)
  ledcSetup(0, 5000, 8);
  ledcAttachPin(led1, 0);
}

void loop() {

  
  int potValue = analogRead(potPin);
  int brightness = map(potValue, 0, 4095, 0, 255);
  ledcWrite(0, brightness);


  
  bool buttonState = digitalRead(buttonPin);

  if (buttonState == LOW && lastButtonState == HIGH) {
    led2State = !led2State;

    
    if (led2State == true) {
      blinkMode = !blinkMode;
    }

    delay(200); 
  }

  lastButtonState = buttonState;


  
  if (led2State) {
    digitalWrite(led2, HIGH);
    delay(blinkMode ? 100 : 400);

    digitalWrite(led2, LOW);
    delay(blinkMode ? 100 : 400);
  } else {
    digitalWrite(led2, LOW);
  }
}