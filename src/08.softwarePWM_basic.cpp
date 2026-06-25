#include <Arduino.h>
#include <mio.h>

// put function declarations here:
int myFunction(int, int);
int LED_PIN = (I01); //디지털 핀 사용

// 소프트웨어 PWM 함수
// pin : 제어할 핀 번호
// dutyCycle: 듀티 사이클 (0~100%)
// duration: 지속시간 (밀리초)
void softwarePWM(int pin, int dutyCycle, int duration)  {
  dutyCycle = constrain(dutyCycle, 0, 100); //범위 제한
  
  //한 주기의 시간 (마이크로초)
  const int PERIOD_US = 2000; //2ms = 500hz

  // HIGH 상태 유지 시간 계산
  int onTime = (PERIOD_US * dutyCycle) / 100;
  // LOW 상태 유지 시간 계산
  int offTime = PERIOD_US - onTime;

  // 지속 시간 동안 반복
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
  // 밝기 5%*, 듀티사이클 50%
  softwarePWM(LED_PIN, 5, 10); // 핀, 듀티%, 지속시간(ms)
}

int myFunction(int x, int y) {
  return x + y;
}