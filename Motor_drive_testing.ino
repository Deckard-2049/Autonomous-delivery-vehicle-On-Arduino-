// Define the pins for the L298 motor driver
int enaA = 8;
int in1A = 9;
int in2A = 10;
int enaB = 13;
int in1B = 11;
int in2B = 12;


void setup() {
  // put your setup code here, to run once:
  // Set the L298 motor driver pins to output mode
  pinMode(enaA, OUTPUT);
  pinMode(in1A, OUTPUT);
  pinMode(in2A, OUTPUT);
  pinMode(enaB, OUTPUT);
  pinMode(in1B, OUTPUT);
  pinMode(in2B, OUTPUT);

  // Set the maximum speed of the motors
  analogWrite(enaA, 255);
  analogWrite(enaB, 255);
}

void backward() {
  digitalWrite(in1A, LOW); //Left Motor backword Pin 
  digitalWrite(in2A, HIGH); //Left Motor forword Pin 
  digitalWrite(in1B, LOW); //Right Motor backword Pin 
  digitalWrite(in2B, HIGH); //Right Motor forword Pin 
}

void forward() {
  digitalWrite(in1A, HIGH); //Left Motor backword Pin 
  digitalWrite(in2A, LOW); //Left Motor forword Pin 
  digitalWrite(in1B, HIGH); //Right Motor backword Pin 
  digitalWrite(in2B, LOW); //Right Motor backword Pin 
}

void turnRight() {
  digitalWrite(in1A, LOW); //Left Motor backword Pin 
  digitalWrite(in2A, HIGH); //Left Motor forword Pin 
  digitalWrite(in1B, HIGH); //Right Motor backword Pin 
  digitalWrite(in2B, LOW); //Right Motor backword Pin 
}

void turnLeft() {
  digitalWrite(in1A, HIGH); //Left Motor backword Pin 
  digitalWrite(in2A, LOW); //Left Motor forword Pin 
  digitalWrite(in1B, LOW); //Right Motor backword Pin 
  digitalWrite(in2B, HIGH); //Right Motor forword Pin 
}

void Stop() {
  digitalWrite(in1A, LOW); //Left Motor backword Pin 
  digitalWrite(in2A, LOW); //Left Motor forword Pin 
  digitalWrite(in1B, LOW); //Right Motor backword Pin 
  digitalWrite(in2B, LOW); //Right Motor backword Pin 
}



void loop() {
  // put your main code here, to run repeatedly:
  forward();
  delay(10000);
  backward();
  delay(10000);
  // turnRight();
  // delay(10000);
  // turnLeft();
  // delay(10000);
  // Stop();

}
