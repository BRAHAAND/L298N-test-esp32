
// Requires ESP32 Arduino core 3.x (ledcAttach / ledcWrite take a pin)

const int ENA = 18;   // PWM speed
const int IN1 = 19;
const int IN2 = 21;

const int PWM_FREQ = 1000;  // 1 kHz
const int PWM_RES  = 8;     // 8-bit: 0-255
const int SPEED    = 170;   // raise toward 255 if the motor only hums

void motorForward(int speed) {
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  ledcWrite(ENA, speed);
}

void motorReverse(int speed) {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  ledcWrite(ENA, speed);
}

void motorStop() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  ledcWrite(ENA, 0);
}

void setup() {
  Serial.begin(115200);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  ledcAttach(ENA, PWM_FREQ, PWM_RES);
  motorStop();
  delay(1000);
  Serial.println("Motor test starting");
}

void loop() {
  Serial.println("Forward");
  motorForward(SPEED);
  delay(2000);

  Serial.println("Stop");
  motorStop();
  delay(1000);

  Serial.println("Reverse");
  motorReverse(SPEED);
  delay(2000);

  Serial.println("Stop");
  motorStop();
  delay(3000);
}
