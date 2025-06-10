const int readPin = A3;
float v2 = 0;
int readVal = 0;

const int delayTime = 500;

void printVoltage() {
  readVal = analogRead(readPin);
  v2 = (5.0/1023.0) * readVal;
  Serial.println(v2);
}

void setup() {
  pinMode(readPin, INPUT);
  Serial.begin(9600);
}

void loop() {
  printVoltage();
  delay(delayTime);
}