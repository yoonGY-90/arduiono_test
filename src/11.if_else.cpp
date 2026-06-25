#include <Arduino.h>
#include <mio.h>

// put function declarations here:
int myFunction(int, int);
int score = 83;


void setup() {
  Serial.begin(115200);
    if (score >= 90) {
  Serial.println("A");
} else if (score >= 80) {
  Serial.println("B");
} else if (score >= 70) {
  Serial.println("C");
} else {
Serial.println("재시험");
}
  int result = myFunction(2, 3);
}

void loop() {

}

// put function definitions here:
int myFunction(int x, int y) {
  return x + y;
}