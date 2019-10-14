#include <Servo.h>

Servo shoulder, elbow, wrist;
Servo joints[] = {shoulder, elbow, wrist};

const int threshold = 60;         // ADC counts
const int vel = 2;                // degrees/step

int targets[] = {90, 90, 90};     // target servo positions
int norm_read[] = {400, 90, 5};   // undisturbed current reading

uint8_t joint_leds[] = {2, 4, 6}; // shoulder, elbow, wrist
uint8_t led_blink = LOW;


void setup() {
  Serial.begin(57600);
  analogReference(INTERNAL);

  shoulder.attach(9);
  elbow.attach(10);
  wrist.attach(11);
  
  // hold-pose button
  pinMode(12, INPUT_PULLUP);
  
  for (int i = 0; i < 3; i++) {
    joints[i].write(targets[i]);
    digitalWrite(joint_leds[i], LOW);
  }
  
  Serial.println("--STARTUP--");
  delay(1000);
  
  set_norms();
}


// for figuring out which direction we're being nudged
int last_reads[] = {0, 0, 0};
boolean cw[] = {true, true, true};

void joint_step(int j) {
  // conveviently, the joints are using ADC inputs 0, 1, 2
  int this_read = analogRead(j);
  if (this_read < norm_read[j] - threshold
      || norm_read[j] + threshold < this_read) {
	// motor current is off by more than `threshold`, so we're being nudged
    digitalWrite(joint_leds[j], led_blink);
    if (this_read > last_reads[j] + 40) {
	  // the last step increased current, so probably wrong direction
      cw[j] = cw[j] ? false : true;
    }

    int target = targets[j];
    if (cw[j]) {
      Serial.print(" +");
      target += vel;
    } else {
      Serial.print(" -");
      target -= vel;
    }

    last_reads[j] = this_read;
    targets[j] = min(180, max(0, target));
    joints[j].write(targets[j]);
  } else {
    // no need to do anything
    Serial.print("  ");
    digitalWrite(joint_leds[j], LOW);
  }
  Serial.print(this_read);
}


void set_norms() {
  // Measure current on all three joints and save those as the new baseline
  Serial.print("CAL: ");
  for (int i = 0; i < 3; i++) {
    norm_read[i] = analogRead(i);
    last_reads[i] = norm_read[i];
    Serial.print(norm_read[i]);
    Serial.print(", ");
  }
  Serial.println("");
}


void loop() {
  led_blink = (led_blink == HIGH ? LOW : HIGH);
  boolean needs_cal = false;

  while (digitalRead(12) == LOW) {
    // hold-pose button depressed
    needs_cal = true;
    for (int i = 0; i < 3; i++) {
      digitalWrite(joint_leds[i], HIGH);
    }
    delay(50);
  }

  if (needs_cal) {
    // first iteration since releasing the button, so set baseline currents
    set_norms();
    for (int i = 0; i < 3; i++) {
      digitalWrite(joint_leds[i], LOW);
    }
  }
  
  Serial.print("(");
  for (int i = 0; i < 3; i++) {
    joint_step(i);
  }
  Serial.println(")");

  delay(100);
}
