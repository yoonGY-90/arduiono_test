#include <Arduino.h>
#include <mio.h>

// put function declarations here:
int myFunction(int, int);

void setup() {
  Serial.begin(115200);
  pinMode(I00, OUTPUT); // pin제어 (핀번호, 용도(INPUT/OUTPUT))
  int result = myFunction(2, 3);
}

void loop() {
  digitalWrite(I00, HIGH);
  delay(1000);
  digitalWrite(I00, LOW);
  delay(1000);
}

// put function definitions here:
int myFunction(int x, int y) {
  return x + y;
}