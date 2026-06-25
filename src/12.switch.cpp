#include <Arduino.h>
#include <mio.h>

// put function declarations here:
int myFunction(int, int);

//switch 구문 연습
int Lamp[4] = {Q00, Q01, Q02, Q03}; // 여러개 묶을땐 중괄호 사용

void setup() {
  Serial.begin(115200);
  for (int i=0; i<4; i++) {
    pinMode(Lamp[i], OUTPUT);
  }

  int result = myFunction(2, 3);
}

void loop() {
  if (Serial.available() > 0) { 
    char command = Serial.read();
    switch (command) {
      case '0' :
      Serial.println("Q00 램프 ON");
      digitalWrite(Lamp[0], HIGH);
      break;

      case '1' :
      Serial.println("Q01 램프 ON");
      digitalWrite(Lamp[1], HIGH);
      break;

      case '2' :
      Serial.println("Q02 램프 ON");
      digitalWrite(Lamp[2], HIGH);
      break;

      case '3' :
      Serial.println("Q03 램프 ON");
      digitalWrite(Lamp[3], HIGH);
      break;

      case '4' :
      Serial.println("램프 OFF");
      for(int i=0; i<4; i++) {
        digitalWrite(Lamp[i], LOW);
      }
      break;
    }
}
}

// put function definitions here:
int myFunction(int x, int y) {
  return x + y;
}