#include <Arduino.h>
#include <mio.h> 

// put function declarations here:
int myFunction(int, int);

int count = 0; // 카운트는 0으로 정의했음 (0부터 시작)

void setup() {
  // 시작할 때 한번 실행함
  Serial.begin(115200); // 시리얼 속도 (9600, 115200)
  Serial.println("=== Setup 시작 ==="); // 해당 메세지 출력
  Serial.println("이 메시지는 1번만 출력됩니다");
  Serial.println("=== Setup 끝 ===");
  int result = myFunction(2, 3);
}

void loop() {
  // 무한히 반복함
  count++; // 카운트를 1씩 더함
  Serial.print("Loop 실행 횟수: "); // 가로로 이어씀 (이 다음 써지는 것도 바로 옆에 붙어서 나옴)
  Serial.println(count); // (줄바꿈(엔터치기))
  delay(1000); // 1초 딜레이 줌
  
}

// put function definitions here:
int myFunction(int x, int y) {
  return x + y;
}