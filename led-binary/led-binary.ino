int valueArray[4] = {8, 4, 2, 1};
int valueArrayLength = sizeof(valueArray) / sizeof(valueArray[0]);
int bit4ValueMax = 15;

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

void setup() {
  Serial.begin(9600);

  setBit4Array(1);
  Serial.println(bit4Array[0]);
  Serial.println(bit4Array[1]);
  Serial.println(bit4Array[2]);
  Serial.println(bit4Array[3]);

}

void loop() {}
