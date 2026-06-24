#include <Arduino.h>
#include <mio.h>

// put function declarations here:
int myFunction(int, int);

int LED_PIN = Q00; // LED_PIN은 Q00 정수

void setup() {
  Serial.begin(115200);
  pinMode(LED_PIN, OUTPUT); //Q00은 아웃풋
  Serial.println("=== LED 제어 시스템 ===");
  Serial.println("명령어: ");
  Serial.println(" 'on' 또는 '1' : LED 켜기'");
  Serial.println(" 'off' 또는 '0' : LED 끄기");
  Serial.println(" 'blink' : LED 깜빡이기");
  
  int result = myFunction(2, 3);
}

void loop() {
  if (Serial.available() > 0) {
    String command = Serial.readStringUntil('\n'); // 줄바꿈까지 읽기
    command.trim(); // 공백 제거
    command.toLowerCase(); // 소문자로 변환

    if (command == "on" || command == "1") { // 커맨드가 on이거나 1이면
      digitalWrite(LED_PIN, HIGH);
      Serial.println("→ LED ON");
    }
    else if (command == "off" || command == "0") {
      digitalWrite(LED_PIN, LOW);
      Serial.println("→ LED OFF");
    }
    else if (command == "blink") {
      Serial.println("→ LED 깜빡임 시작 (5초)");
      for (int i=0; i < 10; i++) {
        digitalWrite(LED_PIN, HIGH);
        delay(250);
        digitalWrite(LED_PIN, LOW);
        delay(250);
      }
      Serial.println("→ 깜빡임 종료");
    }
    else {
      Serial.print("→ 알 수 없는 명령: ");
      Serial.println(command);
    }
  }
  
}

// put function definitions here:
int myFunction(int x, int y) {
  return x + y;
}