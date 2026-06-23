#include <Arduino.h>
#include <mio.h> 

// put function declarations here:
int myFunction(int, int);

void setup() {
  // 시작할 때 한번 실행함
  Serial.begin(115200);
  Serial.println("=== 아두이노 시작 ===");
  Serial.println("안녕하세요, 아두이노입니다!");

  int result = myFunction(2, 3);
}

void loop() {
  // 무한히 반복함
Serial.println("Hello World!");
delay(1000);
  
}

// put function definitions here:
int myFunction(int x, int y) {
  return x + y;
}