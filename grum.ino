#include <Servo.h>

Servo myservo;
//Ultrasonic Pins
const int trigPin = 11;
const int echoPin = 12;
long duration;
int distance;

int stopper = 45;

//Motor1 Pins
const int en1 = 6;
const int f1 = 4;
const int b1 = 5;

//Motor2 Pins
const int en2 = 13;
const int f2 = 8;
const int b2 = 7;

const int servo = 9;

void setup() {
  // put your setup code here, to run once:
  pinMode(en2, OUTPUT);
  pinMode(f2, OUTPUT);
  pinMode(b2, OUTPUT);

  pinMode(en1, OUTPUT);
  pinMode(f1, OUTPUT);
  pinMode(b1, OUTPUT);

  myservo.attach(9);
  
  //pinMode(servo, OUTPUT);

  


  pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
  pinMode(echoPin, INPUT); // Sets the echoPin as an Input
  Serial.begin(9600); // Starts the serial communication
  
  digitalWrite(f2, LOW);
  digitalWrite(b2, HIGH);
  digitalWrite(f1, LOW);
  digitalWrite(b1, HIGH);
}

//void turn_right(){
//}
//
void turn_right(){
  digitalWrite(f2, HIGH);
  digitalWrite(b2, LOW);
  digitalWrite(f1, LOW);
  digitalWrite(b1, HIGH);
  analogWrite(en1, 170);
  analogWrite(en2, 220);
  delay(1000);
  
}

void turn_left(){
  digitalWrite(f2, LOW);
  digitalWrite(b2, HIGH);
  digitalWrite(f1, HIGH);
  digitalWrite(b1, LOW);
  analogWrite(en1, 170);
  analogWrite(en2, 220);
  delay(1000);
  
}

void set_stop(){
  analogWrite(en1, 0);
  analogWrite(en2, 0);
}

void set_forward(){
  digitalWrite(f2, LOW);
  digitalWrite(b2, HIGH);
  digitalWrite(f1, LOW);
  digitalWrite(b1, HIGH);
  analogWrite(en1, 170);
  analogWrite(en2, 220);
}


void set_backward(){
  digitalWrite(f2, HIGH);
  digitalWrite(b2, LOW);
  digitalWrite(f1, HIGH);
  digitalWrite(b1, LOW);
  analogWrite(en1, 170);
  analogWrite(en2, 220);
}


void read_ultra(){
  digitalWrite(trigPin, LOW);
delayMicroseconds(2);
// Sets the trigPin on HIGH state for 10 micro seconds
digitalWrite(trigPin, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin, LOW);
// Reads the echoPin, returns the sound wave travel time in microseconds
duration = pulseIn(echoPin, HIGH);
// Calculating the distance
distance= duration*0.034/2;
// Prints the distance on the Serial Monitor
Serial.print("Distance: ");
Serial.println(distance);
}

//servo max = 140- 20. 80=mid
void loop() {
  if(distance <= stopper)
  {
    set_stop();
  }
  else{
    turn_left();
    set_stop();
    delay(4000);
  
    
  }
  read_ultra();

}


