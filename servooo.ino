#include <Servo.h>

Servo shoulder, elbow, wrist;
Servo joints[] = {shoulder, elbow, wrist};

const int threshold = 60;
const int vel = 2;

int targets[] = {90, 90, 90};
int norm_read[] = {400, 90, 5};

void setup() {
  Serial.begin(57600);
  analogReference(INTERNAL);
  shoulder.attach(9);
  elbow.attach(10);
  wrist.attach(11);
  
  pinMode(12, INPUT_PULLUP);
  
  for (int i = 0; i < 3; i++) {
    joints[i].write(targets[i]);
  }
  
  delay(1000);
  
  set_norms();
}

int last_reads[] = {0, 0, 0};
boolean cw[] = {true, true, true};

void joint_step(int j) {
  int this_read = analogRead(j);
  if (this_read < norm_read[j] - threshold || norm_read[j] + threshold < this_read) {
    if (this_read > last_reads[j] + 40) {
      cw[j] = cw[j] ? false : true;
    }
    int target = targets[j];
    if (cw[j]) {
      target += vel;
    } else {
      target -= vel;
    }
    last_reads[j] = this_read;
    targets[j] = min(180, max(0, target));
    joints[j].write(targets[j]);
  }
}

void set_norms() {
  for (int i = 0; i < 3; i++) {
    norm_read[i] = analogRead(i);
    last_reads[i] = norm_read[i];
  }
}

void loop() {
  boolean needs_cal = false;
  while (digitalRead(12) == LOW) {
    needs_cal = true;
    delay(50);
  }
  if (needs_cal) {
    set_norms();
  }
    
  for (int i = 0; i < 3; i++) {
    joint_step(i);
  }
  delay(100);
}
