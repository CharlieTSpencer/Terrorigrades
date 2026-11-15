#include <AFMotor.h>

AF_DCMotor motorbl(1);
AF_DCMotor motorbr(2);
AF_DCMotor motorfr(3);
AF_DCMotor motorfl(4);

const int SPEED = 250;

// Prawa strona jedzie do przodu
void rightForward() {
  motorfr.setSpeed(SPEED);
  motorfr.run(FORWARD);
  motorbr.setSpeed(SPEED);
  motorbr.run(BACKWARD);
}

// Lewa strona jedzie do przodu
void leftForward() {
  motorfl.setSpeed(SPEED);
  motorfl.run(BACKWARD);
  motorbl.setSpeed(SPEED);
  motorbl.run(FORWARD);
}

void stopRight() {
  motorfr.run(RELEASE);
  motorbr.run(RELEASE);
}

void stopLeft() {
  motorfl.run(RELEASE);
  motorbl.run(RELEASE);
}

void startMotors() {      // 1 - wszystko do przodu
  rightForward();
  leftForward();
}

void stopMotors() {       // 0 - wszystko stop
  stopRight();
  stopLeft();
}

void setup() {
  Serial.begin(38400);
  stopMotors();
  Serial.println("Czekam...");
}

void loop() {
  if (Serial.available()) {
    int incoming = Serial.read();

    if (incoming == '1') {
      startMotors();
      Serial.println("-> START");
    }
    else if (incoming == '0') {
      stopMotors();
      Serial.println("-> STOP");
    }
    else if (incoming == '2') {
      stopRight();
      leftForward();
      Serial.println("-> PRAWE STOP, LEWE JADA");
    }
    else if (incoming == '3') {
      stopLeft();
      rightForward();
      Serial.println("-> LEWE STOP, PRAWE JADA");
    }
  }
}