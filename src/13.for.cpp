#include <Arduino.h>
#include <mio.h>

// put function declarations here:
int myFunction(int, int);
// LED 핀 배열
int LED[] = {Q00, Q01, Q02, Q03, Q04, Q05, Q06, Q07, Q08, Q09, Q10, Q11, Q12, Q13, Q14, Q15};
int NUM_LED = 16;

void setup() {
  Serial.begin(115200);
  for (int i = 0; i < NUM_LED; i++)
  {
    pinMode (LED[i], OUTPUT);
  }
  
  int result = myFunction(2, 3);
}

void loop() {
  for (int i = 0; i < NUM_LED; i++)
  {
    digitalWrite(LED[i], HIGH);
    delay(500);
    digitalWrite(LED[i], LOW);
  }
  
  for (int i = NUM_LED; i >= 0; i--)
  {
    digitalWrite(LED[i], HIGH);
    delay(100);
    digitalWrite(LED[i], LOW);
  }
  

}

// put function definitions here:
int myFunction(int x, int y) {
  return x + y;
}