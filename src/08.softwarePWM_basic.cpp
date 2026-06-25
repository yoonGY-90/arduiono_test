#include <Arduino.h>
#include <mio.h>

// put function declarations here:
int myFunction(int, int);
int LED_PIN = (I01);
void softwarePWM(int pin, int dutyCycle, int duration) {
  dutyCycle = constrain(dutyCycle, 0, 100);

  const int PERIOD_US = 2000;

  int onTime = (PERIOD_US * dutyCycle) / 100;
  int offTime = PERIOD_US - onTime;

  unsigned long startTime = millis();
  while (millis() - startTime < duration) {
    if (onTime > 0) {
      digitalWrite(pin, HIGH);
      delayMicroseconds(onTime);
    }
    if (offTime > 0) {
      digitalWrite(pin, LOW);
      delayMicroseconds(offTime);
    }
  }
}

// put function definitions here:
void setup() {
  Serial.begin(115200);
  pinMode(I00, OUTPUT);
  pinMode(LED_PIN, OUTPUT);
  int result = myFunction(2, 3);
}

void loop() {
  digitalWrite(I00, HIGH);  
  softwarePWM(LED_PIN, 5, 10);
}


int myFunction(int x, int y) {
  return x + y;
}