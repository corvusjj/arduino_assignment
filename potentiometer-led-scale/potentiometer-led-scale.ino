const int potenPin = A0;
const int delayT = 1000;

float getVoltage2(int analogVal) {
  return (5.0/1023.0) * analogVal;
}

void setup() {
  pinMode(potenPin, INPUT);

  Serial.begin(9600);
};

void loop () {
  const int potenValue = analogRead(potenPin);
  const float voltage = getVoltage2(potenValue);
  Serial.println(voltage);
  
  delay(delayT);
};
