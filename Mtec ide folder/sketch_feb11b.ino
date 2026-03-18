

int loopCount = 0;
int ms = 500;


void setup() {
  Serial.begin(115200);
  Serial.println("SETUP COMPLETE");

}

void loop() {
Serial.println("Hello World!");
Serial.print("Loop Count = ");
Serial.println(loopCount);

delay(ms);

loopCount++;

if(loopCount > 10)
{
  loopCount = 0;
  Serial.println("LOOP COUNT RESET");
}

}
