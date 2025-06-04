// 4bit binary
void getBinary(int inputNum) {
  int valueArray[4] = {8, 4, 2, 1};
  int valueArrayLength = sizeof(valueArray) / sizeof(valueArray[0]);
  int bit4ValueMax = 15; 
  int bit4Array[4] = {0, 0, 0, 0};

  for (int i = 0; i < valueArrayLength; i++) {
    if (inputNum > bit4ValueMax) return bit4Array;

    if (inputNum >= valueArray[i]) {
      Serial.println(valueArray[i]);
      inputNum -= valueArray[i];
      delay(1000);
    }

    if (inputNum <= 0) break;
  }
}

void setup() {
  Serial.begin(9600);
  getBinary(5);
}

void loop() {}