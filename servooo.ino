#include <Servo.h>

Servo tester;

const int threshold = 60;
const int delta = 2;
const int dd = 50;
int target = 90;

void setup() {
  Serial.begin(57600);
  analogReference(INTERNAL);
  tester.attach(9);
}

int i = 0;

void floop() {
  tester.write(target - delta);
  int low = analogRead(3);
  delay(dd);
  tester.write(target + delta);
  int high = analogRead(3);
  delay(dd);
  if (low > threshold || high > threshold) {
    if (low > high) {
      target = max(0, target - delta);
    } else {
      target = min(180, target + delta);
    }
  }
  if (++i >= 1) {
    i = 0;
    Serial.print(low);
    Serial.print("/");
    Serial.println(high);
  }
}

int last_read = 0;
int last_delta = 5;
void bloop() {
  int this_read = analogRead(3);
  tester.write(target);
  if (this_read > threshold) {
    if (this_read - last_read > 50) {
      last_delta = 0 - last_delta;
    }
    target = min(180, max(0, target + last_delta));
  }
  last_read = this_read;
  Serial.print(target);
  Serial.print(": ");
  Serial.println(last_read);
  delay(200);
}

boolean cw = true;
int vel = 2;

void loop() {
  int this_read = analogRead(3);
  if (this_read > threshold) {
    //vel = min(vel + 1, 10);
    if (this_read > last_read + 40) {
      cw = cw ? false : true;
      //vel = 1;
    }
    if (cw) {
      target += vel;
    } else {
      target -= vel;
    }
    last_read = this_read;
    target = min(180, max(0, target));
    tester.write(target);
  } else {
    //vel = 1;
  }
  delay(100);
}
