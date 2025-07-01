const int potenPin = A0;
const int ledPins[6] = {12, 11, 10, 9, 8, 7};
const int ledPinsLength = sizeof(ledPins) / sizeof(ledPins[0]);

float getVoltage2(int analogVal) {
  return (5.0/1023.0) * analogVal;
}

void activateLedScale(float voltage) {
  const float maxLedIndex = (voltage/5) * ledPinsLength;
  // maxLedIndex will be 1.00 to 6.00 as from ledPinsLength ratio to 0-5 voltage

  for(int i = 0; i < ledPinsLength; i++) {
    digitalWrite(ledPins[i], (maxLedIndex - 1 >= i)? HIGH: LOW);
    // -1 to compenstae for starting 0, >= to reach 5.0 as the highest index
  }
}

void setup() {
  pinMode(potenPin, INPUT);
  for(int i = 0; i < ledPinsLength; i++) {
    pinMode(ledPins[i], OUTPUT);
  }
};

void loop () {
  const int potenValue = analogRead(potenPin);
  const float voltage = getVoltage2(potenValue);
  activateLedScale(voltage);
};
