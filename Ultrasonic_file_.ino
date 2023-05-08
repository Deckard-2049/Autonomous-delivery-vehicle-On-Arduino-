#include <Servo.h>

const int TRIG_PIN = 9;                    // Arduino pin connected to Ultrasonic Sensor's TRIG pin
const int ECHO_PIN = 8;                    // Arduino pin connected to Ultrasonic Sensor's ECHO pin
const int SERVO_PIN = 10;                   // Arduino pin connected to Servo Motor's pin
const int DISTANCE_THRESHOLD = 25;         // centimeters

Servo servo;                                // create servo object to control a servo
float duration_us, distance_cm;

void setup() {
  Serial.begin(9600);                      // initialize serial port
  pinMode(TRIG_PIN, OUTPUT);               // set arduino pin to output mode
  pinMode(ECHO_PIN, INPUT);                // set arduino pin to input mode
  servo.attach(SERVO_PIN);
  servo.write(90);                         // set initial position of the servo to center
}

void loop() {
  // generate 10-microsecond pulse to TRIG pin
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);

  // measure duration of pulse from ECHO pin
  duration_us = pulseIn(ECHO_PIN, HIGH);

  // calculate the distance
  distance_cm = 0.017 * duration_us;

  Serial.print("distance: ");
  Serial.print(distance_cm);
  Serial.println(" cm");
  delay(500);

  // Check if distance is less than threshold
  if(distance_cm < DISTANCE_THRESHOLD){
    // Turn left and get the distance
    servo.write(0);                       // Turn left
    delay(500);
    float left_distance = get_distance();
    delay(500);
    
    // Turn right and get the distance
    servo.write(180);                     // Turn right
    delay(500);
    float right_distance = get_distance();
    delay(500);
    
    servo.write(90);                      // Center position

    // Take diversion based on the obstacle on the sides
    if (left_distance > right_distance) {
      Serial.println("Take Right");
    } else {
      Serial.println("Take Left");
    }
  }
}

float get_distance() {
  // generate 10-microsecond pulse to TRIG pin
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);

  // measure duration of pulse from ECHO pin
  duration_us = pulseIn(ECHO_PIN, HIGH);

  // calculate the distance
  return 0.017 * duration_us;
}
