// HW5_202255513

int pins_LED[] = {2,3,4,5};

int PWM_value[] = {0, 63, 127, 191};

void setup() {
  Serial.begin(9600);
  for (int i = 0; i < 4; i++) {
    pinMode(pins_LED[i], OUTPUT);
  }
}

void loop() {
  while (true) {
    for (int i = 0; i < 4; i++) {
      PWM_value[i] += 1;
      if (PWM_value[i] >= 256) {
        PWM_value[i] = 0;
      }
      analogWrite(pins_LED[i], PWM_value[i]);
    }
    delay(10);
  }
}
