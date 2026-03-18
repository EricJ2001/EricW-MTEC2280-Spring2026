
const int ledPin = 4; 
int ms = 500;
bool ledState = 0; 



void setup() 
{
  pinMode (ledPin, OUTPUT);

  Serial.begin(115200);

}

void loop() 
{
  digitalWrite(ledPin, HIGH);
  delay(ms); 
  digitalWrite(ledPin, LOW);
  delay(ms);

}
