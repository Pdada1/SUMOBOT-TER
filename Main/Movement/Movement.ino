//Declaring the pins for controlling the motors.
//I have not declared enable pins because I want the motor to run when I turn it on.
// If you want to turn on the motor manually then you can connect the enable pin.



// Turn off Motors by setting pinMode to something other than OUTPUT
// Motors run in one direction by using digitalWrite with one left and one right


#include <math.h>
#include <Ultrasonic.h>
Ultrasonic sensor1(2,3);
Ultrasonic sensor2(4,5);

const int leftForward =  4;
const int leftBackward = 5;
const int leftSpeed = 9;
const int rightForward =  7;
const int rightBackward =  8;
const int rightSpeed = 10;
//Sensor sense = new Sensor();
void setup()
{
  pinMode(leftForward, OUTPUT);
  pinMode(leftBackward, OUTPUT);
  pinMode(leftSpeed, OUTPUT);
  pinMode(rightForward, OUTPUT);
  pinMode(rightBackward, OUTPUT);
  pinMode(rightSpeed, OUTPUT);
  //Enable the Motor Shield output;  
  pinMode(6, OUTPUT); 
  digitalWrite(6, HIGH);  
}

// MOVEMENT METHODS

void stop ()
{
  // Brakes if enemy bot has dodged
  analogWrite(leftSpeed, 0);
  analogWrite(rightSpeed, 0);
}

void attack()
{
  // Aims to knock enemy bot out of circle
  // Charges
  // For left motor LOW HIGH is forward
  // For right motor HIGH LOW is forward
  // Code to move the bot forwards
  while (sense.inFront())
  {
    moveForward();
  }
  stop();
}

void avoidBoundaryFront () {
  // Helps the bot avoid danger by moving away when boundary in front
  // Code to move the bot backwards
  analogWrite(leftSpeed, 255);
  digitalWrite(leftForward, LOW);
  digitalWrite(leftBackward, HIGH);
  analogWrite(rightSpeed, 255);
  digitalWrite(rightForward, LOW);
  digitalWrite(rightBackward, HIGH);
}

void avoidBoundaryBack () {
  // Helps the bot avoid danger by moving away when boundary on back
  moveForward();
}

void moveForward () {
  // Moves bot forward
  analogWrite(leftSpeed, 255);
  digitalWrite(leftForward, HIGH);
  digitalWrite(leftBackward, LOW);
  analogWrite(rightSpeed, 255);
  digitalWrite(rightForward, HIGH);
  digitalWrite(rightBackward, LOW);
}

void rightTurn ()
{
  // Turns the bot right for defense and to get into attacking position by making one wheel spin faster
  digitalWrite(leftForward, HIGH);
  digitalWrite(leftBackward, LOW);
  analogWrite(leftSpeed, 255);
  digitalWrite(rightForward, LOW);
  digitalWrite(rightBackward, HIGH);
  analogWrite(rightSpeed, 255);  
}

void leftTurn()
{
  // Turns the bot right for defense and to get into attacking position by making one wheel spin faster
  digitalWrite(leftForward, LOW);
  digitalWrite(leftBackward, HIGH);
  analogWrite(leftSpeed, 255);
  digitalWrite(rightForward, HIGH);
  digitalWrite(rightBackward, LOW);
  analogWrite(rightSpeed, 255);
}

// SENSOR METHODS

double dcalc(long dsense, long d2, long d3)
{
  double s=(dsense+d2+d3)/2;
  double d=2*sqrt((double)(s*(s-dsense)*(s-d2)*(s-d3)))/(double)(dsense);
  return d;
}

// MAIN METHOD THAT CONTROLS PROGRAM

void loop ()
{
  // Ensures bot is safe by moving away from white line boundary toward center of circle
  
  unsigned long d2= sensor1.read(CM);
  unsigned long d3 = sensor2.read(CM);
  long snsed=2;//to change for later to cm
  double r2distance=dcalc(snsed,d2,d3);
  // If r2distance is NaN, then all comparisons involving it will be false
  // Front sensor
  int sensorValue1 = analogRead(A0);
  // Back sensor
  int sensorValue2 = analogRead(A1);
  int sensorValue3 = analogRead(A2);
  while (sensorValue1 > 80 && r2distance < 0) {
    avoidBoundaryFront();
    sensorValue1 = analogRead(A1);
  }
  while ((sensorValue2 > 80 || sensorValue3 > 80) && r2distance > 0) {
    avoidBoundaryBack();
    sensorValue2 = analogRead(A2);
    sensorValue3 = analogRead(A3);
  }
  

  // Turns the bot to prepare for attack     
  while (!(r2distance > 0)) {
    d2 = sensor1.read(CM);
    d3 = sensor2.read(CM);
    r2distance = dcalc(snsed,d2,d3);
    else if (d2 <= d3) {
      leftTurn();
    }
    else if (d3 < d2) {
      rightTurn();
    }
  }

  // Attacks
  while (!(r2distance > 0)) {
    d2 = sensor1.read(CM);
    d3 = sensor2.read(CM);
    r2distance = dcalc(snsed,d2,d3);
    attack(); // Aims to knock enemy bot out of circle
  }

  // Brakes the bot in case enemy dodges
  stop();
}
 