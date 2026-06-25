#include <Arduino.h>
#include <mio.h>

// put function declarations here:
int myFunction(int, int);
int LED1 = Q00;
int LED2 = Q01;
int LED3 = Q02;
void multiLEDControl(int duty1, int duty2, int duty3, int duration); 
// 아두이노 IDE에선 필요 없으나 VS코드는 순차적 실행이라 이걸로 미리 루프문 밑에 해당 내용 있는 것 알려줘야됨

void setup() {
  Serial.begin(115200);
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(LED3, OUTPUT);

  int result = myFunction(2, 3);
}

void loop() {
  //각 LED를 다른 밝기로 동시 제어
  multiLEDControl(25, 50, 75, 1000); //각각 25%, 50%, 75%, 1초간
  multiLEDControl(75, 50, 25, 1000); //각각 75%, 50%, 25%, 1초간
  multiLEDControl(100, 100, 100, 1000); //모두 100% 1초간
  multiLEDControl(0, 0, 0, 500); //모두 끄기, 0.5초간
}

// 3개 동시 제어 함수
void multiLEDControl(int duty1, int duty2, int duty3, int duration)
{ 
  int PERIOD_US = 2000;

  // 각 LED ON 시간 계산
  int onTime1 = (PERIOD_US * constrain(duty1, 0, 100)) / 100;
  int onTime2 = (PERIOD_US * constrain(duty2, 0, 100)) / 100;
  int onTime3 = (PERIOD_US * constrain(duty3, 0, 100)) / 100;

  unsigned long startTime = millis();

  while (millis() - startTime < duration) {
    unsigned long cycleStart = micros();

    // 모든 LED 켜기
    digitalWrite(LED1, HIGH);
    digitalWrite(LED2, HIGH);
    digitalWrite(LED3, HIGH);

    unsigned long now = micros();

    while (micros() - cycleStart < PERIOD_US) {
      now = micros() - cycleStart;

      if (now >= onTime1) digitalWrite(LED1, LOW);
      if (now >= onTime2) digitalWrite(LED2, LOW);
      if (now >= onTime3) digitalWrite(LED3, LOW);      
    }
  }

  // 모든 LED 끄기
  digitalWrite(LED1, LOW);
  digitalWrite(LED2, LOW);
  digitalWrite(LED3, LOW);
}

// put function definitions here:
int myFunction(int x, int y) {
  return x + y;
}