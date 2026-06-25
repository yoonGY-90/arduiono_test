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
  pinMode(LED_PIN, OUTPUT);
  Serial.println("=== 소프트웨어 PWM LED 페이드 효과 ===");
  int result = myFunction(2, 3);
}

void loop() {
  Serial.println("LED 밝아지는 중...");
  // 0%에서 100%까지 서서히 밝아지기
  for (int brightness = 0; brightness <=100; brightness++) {
    softwarePWM(LED_PIN, brightness, 50); // 각 밝기를 50ms동안 유지

    //10% 단위로 진행 상황 출력
    if (brightness % 10 == 0) {
      Serial.print("밝기: ");
      Serial.println(brightness);
      Serial.println("%");
    }
  }

  Serial.println("LED 어두워지는 중...");

  // 100%에서 0%까지 서서히 밝아지기
  for (int brightness = 100; brightness >=0; brightness--) {
    softwarePWM(LED_PIN, brightness, 50); // 각 밝기를 50ms동안 유지

    //10% 단위로 진행 상황 출력
    if (brightness % 10 == 0) {
      Serial.print("밝기: ");
      Serial.println(brightness);
      Serial.println("%");
    }
  }

  Serial.println("--- 사이클 완료 --n");
  delay(500); // 다음 사이클 전 잠깐 대기
}


int myFunction(int x, int y) {
  return x + y;
}