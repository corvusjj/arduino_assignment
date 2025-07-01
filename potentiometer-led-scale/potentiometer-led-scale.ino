const int potenPin = A0;
const int ledPins[6] = {12, 11, 10, 9, 8, 7};
const int ledPinsLength = sizeof(ledPins) / sizeof(ledPins[0]);

const int delayT = 1000;

float getVoltage2(int analogVal) {
  return (5.0/1023.0) * analogVal;
}

void setup() {
  pinMode(potenPin, INPUT);
  for (int i = 0; i < ledPinsLength; i++) {
    pinMode(ledPins[i], OUTPUT);
  }

  Serial.begin(9600);
};

void loop () {
  const int potenValue = analogRead(potenPin);
  const float voltage = getVoltage2(potenValue);
  Serial.println(voltage);

  digitalWrite(ledPins[1], HIGH);
  digitalWrite(ledPins[2], HIGH);
  digitalWrite(ledPins[3], HIGH);

  // delay(delayT);
};
