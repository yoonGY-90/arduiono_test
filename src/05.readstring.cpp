#include <Arduino.h>

// put function declarations here:
int myFunction(int, int);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  Serial.println("=== 문자 수신 테스트===");
  Serial.println("메세지를 입력하시오.");
  int result = myFunction(2, 3);
}

void loop() {
  // 수신 버퍼에 데이터가 있는지 확인
  if (Serial.available() > 0) {
  // 1바이트 읽기 (0보다 크면 데이터 있음)
  String receivedString = Serial.readString(); // 모든 수신 데이터를 문자열로 읽기  
  
  Serial.print("받은 문자열): ");
  Serial.println(receivedString);//모든 수신 데이터 문자 출력
  Serial.print("문자열 길이: ");
  Serial.println(receivedString.length()); //문자 길이 출력
  Serial.println("---");
  }
  
}

// put function definitions here:
int myFunction(int x, int y) {
  return x + y;
}