#define FLOAT_PIN 17       // Float switch (Tank 1)
#define RELAY_PIN 26       // Relay controlling the pump
#define TRIG_PIN 13        // Ultrasonic sensor trigger (Tank 2)
#define ECHO_PIN 12        // Ultrasonic sensor echo (Tank 2)
#define BUZZER_PIN 14      // Buzzer pin

const int TANK2_EMPTY_THRESHOLD_CM = 10;

void setup() {
  Serial.begin(115200);
  pinMode(FLOAT_PIN, INPUT_PULLUP);
  pinMode(RELAY_PIN, OUTPUT);
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
  pinMode(BUZZER_PIN, OUTPUT);

  digitalWrite(RELAY_PIN, LOW);    // Pump OFF
  digitalWrite(BUZZER_PIN, LOW);   // Buzzer OFF
}

long readUltrasonicDistance() {
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);

  long duration = pulseIn(ECHO_PIN, HIGH, 30000);
  long distanceCm = duration * 0.034 / 2;
  return distanceCm;
}

void loop() {
  bool tank1Low = digitalRead(FLOAT_PIN) == LOW;
  long distance = readUltrasonicDistance();
  bool tank2HasWater = (distance > 0 && distance < TANK2_EMPTY_THRESHOLD_CM);

  Serial.print("Tank 1: ");
  Serial.print(tank1Low ? "LOW" : "FULL");
  Serial.print(" | Tank 2 Distance: ");
  Serial.print(distance);
  Serial.print(" cm → ");
  Serial.println(tank2HasWater ? "WATER AVAILABLE" : "LOW WATER LEVEL");

  // Intermittent beep if Tank 2 water is LOW
  if (!tank2HasWater) {
    Serial.println("** ALERT: Beeping - Tank 2 Low Water Level **");
    digitalWrite(BUZZER_PIN, HIGH);
    delay(100);  // Beep duration
    digitalWrite(BUZZER_PIN, LOW);
    delay(400);  // Pause between beeps
  } else {
    digitalWrite(BUZZER_PIN, LOW);  // Ensure buzzer is off
    delay(500);  // Normal delay
  }

  // Pump control
  if (tank1Low && tank2HasWater) {
    Serial.println("Pump ON");
    digitalWrite(RELAY_PIN, LOW);  // ON
  } else {
    Serial.println("Pump OFF");
    digitalWrite(RELAY_PIN, HIGH); // OFF
  }
}