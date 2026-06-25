#include <Arduino.h>
#include <mio.h>

// put function declarations here:
int myFunction(int, int);

void setup() {
  Serial.begin(115200);
  int result = myFunction(2, 3);
}

void loop() {
  
}

// put function definitions here:
int myFunction(int x, int y) {
  return x + y;
}