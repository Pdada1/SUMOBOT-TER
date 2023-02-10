//Declaring the pins for controlling the motors.
//I have not declared enable pins because I want the motor to run when I turn it on.
//If you want to turn on the motor manually then you can connect the enable pin.
const int leftForward = 8;
const int leftBackward = 9;
const int rightForward = 10;
const int rightBackward = 11;
void setup()
{
  pinMode(leftForward , OUTPUT);
  pinMode(leftBackward , OUTPUT);
  pinMode(rightForward , OUTPUT);
  pinMode(rightBackward , OUTPUT);
}

void loop()
{
//One pin should be HIGH and the other should be LOW for the motor to turn in one
  digitalWrite(leftForward , HIGH);
  digitalWrite(leftBackward , LOW);
  digitalWrite(rightForward , HIGH);
  digitalWrite(rightBackward , LOW);
}