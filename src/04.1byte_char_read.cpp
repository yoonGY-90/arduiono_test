#include <Arduino.h>

// put function declarations here:
int myFunction(int, int);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  Serial.println("=== 문자 수신 테스트===");
  Serial.println("시리얼 모니터에 문자를 입력하시오.");
  int result = myFunction(2, 3);
}

void loop() {
  // 수신 버퍼에 데이터가 있는지 확인
  if (Serial.available() > 0) {
  // 1바이트 읽기 (0보다 크면 데이터 있음)
  int incomingByte = Serial.read(); // 정수데이터로 인커밍바이트는 수신 버퍼에서 1바이트(정수 데이터)를 읽었을때 나오는 값  
  
  Serial.print("받은 데이터 (정수): ");
  Serial.println(incomingByte);
  Serial.print("받은 데이터 (문자): ");
  Serial.println((char)incomingByte); //문자로 변환
  Serial.print("ASCII 코드: ");
  Serial.println(incomingByte);
  Serial.println("---");
  }
  
}

// put function definitions here:
int myFunction(int x, int y) {
  return x + y;
}