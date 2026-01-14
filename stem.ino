int enA = 9;
int in1 = 8;
int in2 = 7;

int enB = 5;
int in3 = 4;
int in4 = 3;

int trig1 = 10;
int echo1 = 12;

int trig2 = 11;
int echo2 = 13;

int baseSpeed = 115;     

void setup() {
  pinMode(enA, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(enB, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
  
  pinMode(trig1, OUTPUT);
  pinMode(echo1, INPUT);

  pinMode(trig2, OUTPUT);
  pinMode(echo2, INPUT);
  Serial.begin(9600);
}

void loop() {
  int distanceRight = getDistance(trig1, echo1);
  Serial.print(distanceRight);
  Serial.println("right cm");

  int distanceLeft = getDistance(trig2, echo2);
  Serial.print(distanceLeft);
  Serial.println("left cm");

  if (distanceRight < 15) {
    moveRobot(baseSpeed, baseSpeed * 0.27); 
  } 
  else if (distanceLeft < 15) {
    moveRobot(baseSpeed * 0.45, baseSpeed*0.85);
  } 
  else {
    moveRobot(baseSpeed , baseSpeed* 0.85);
  }
  delay(50);
}

int getDistance(int trig, int echo) {
  digitalWrite(trig, LOW);
  delayMicroseconds(2);
  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig, LOW);
  long duration = pulseIn(echo, HIGH);
  return duration * 0.034 / 2;
}

void moveRobot(int leftSpeed, int rightSpeed) {
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  analogWrite(enA, rightSpeed);

  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
  analogWrite(enB, leftSpeed);
}