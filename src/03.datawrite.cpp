#include <Arduino.h>

// put function declarations here:
int myFunction(int, int);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);

  int num = 123; //정수형, 숫자 표기, num 
  Serial.print("정수: ");
  Serial.println(num);

  float pi = 3.14159; //실수(소수점)
  Serial.print("실수 (기본): ");
  Serial.println(pi); // 출력 3.14
  Serial.print("실수 (소수점 4자리): ");
  Serial.println(pi, 4); //pi를 4자리까지 나타냄 출력 3.1416

  int value = 225; // 진수
  Serial.print("10진수: ");
  Serial.println(value); // 출력 255
  Serial.print("16진수: ");
  Serial.println(value, HEX); // 출력 FF
  Serial.print("8진수: ");
  Serial.println(value, OCT); // 출력 377
  Serial.print("2진수: ");
  Serial.println(value, BIN); // 출력 11111111

  Serial.println("문자열 출력");

  char letter = 'A'; //문자 출력
  Serial.print("문자: ");
  Serial.println(letter);

  int result = myFunction(2, 3);
}

void loop() {
  // put your main code here, to run repeatedly:
  
}

// put function definitions here:
int myFunction(int x, int y) {
  return x + y;
}