// HW10_board2_202255513

// 온도 출력 및 수신 보드
void setup() {
  Serial.begin(9600); // 컴퓨터와의 시리얼 연결
  Serial1.begin(9600); // 우노와의 시리얼 연결
}

void loop() {
  if (Serial1.available()) { // 우노로부터 데이터 수신
    String temp = Serial1.readStringUntil('\n');
    Serial.println(temp);
  }
}
