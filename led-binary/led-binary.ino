const int valueArray[4] = {8, 4, 2, 1};
const int valueArrayLength = sizeof(valueArray) / sizeof(valueArray[0]);
const int bit4ValueMax = 15;

const int ledPin0 = 9;
const int ledPin1 = 10;
const int ledPin2 = 11;
const int ledPin3 = 12;

int bit4Array[4] = {0, 0, 0, 0};

void resetBit4Array() {
  for (int i=0; i < valueArrayLength; i++) {
    bit4Array[i] = 0;
  }
}

void setBit4Array(int inputNum) {
  resetBit4Array();
  for (int i = 0; i < valueArrayLength; i++) {
    if (inputNum > bit4ValueMax) break;

    if (inputNum >= valueArray[i]) {
      bit4Array[i] = 1;
      inputNum -= valueArray[i];
    }

    if (inputNum <= 0) break;
  }
}

void setBinaryLedPins() {
  setBit4Array(12);

  digitalWrite(ledPin0, bit4Array[0]);
  digitalWrite(ledPin1, bit4Array[1]);
  digitalWrite(ledPin2, bit4Array[2]);
  digitalWrite(ledPin3, bit4Array[3]);
}


void setup() {
  Serial.begin(9600);

  // Serial.println(bit4Array[0]);
  // Serial.println(bit4Array[1]);
  // Serial.println(bit4Array[2]);
  // Serial.println(bit4Array[3]);

  pinMode(ledPin0, OUTPUT);
  pinMode(ledPin1, OUTPUT);
  pinMode(ledPin2, OUTPUT);
  pinMode(ledPin3, OUTPUT);
}

void loop() {
	setBinaryLedPins();
}
