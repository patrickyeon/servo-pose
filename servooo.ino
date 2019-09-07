#include <Servo.h>

Servo shoulder, elbow, wrist;
Servo joints[] = {shoulder, elbow, wrist};

const int threshold = 60;
const int vel = 2;

int target[] = {90, 90, 90};
int norm_read[] = {40, 40, 40};

void setup() {
  Serial.begin(57600);
  analogReference(INTERNAL);
  shoulder.attach(9);
  elbow.attach(10);
  wrist.attach(11);
}

int last_reads[] = [0, 0, 0];
boolean cw[] = {true, true, true};

void joint_step(int j) {
  int this_read = analogRead(j);
  if (this_read < norm_read[j] - threshold || norm_read[j] + threshold < this_read) {
    if (this_read > last_reads[j] + 40) {
      cw[j] = cw[j] ? false : true;
    }
    int target = target[j];
    if (cw[j]) {
      target += vel;
    } else {
      target -= vel;
    }
    last_reads[j] = this_read;
    target[j] = min(180, max(0, target));
    joints[j].write(target[j]);
  }
}

void loop() {
  shoulder.write(90);
  elbow.write(90);
  wrist.write(90);
  Serial.print(analogRead(0));
  Serial.print("/");
  Serial.print(analogRead(1));
  Serial.print("/");
  Serial.println(analogRead(2));
  delay(300);
}
