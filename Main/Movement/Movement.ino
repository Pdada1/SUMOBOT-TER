//Declaring the pins for controlling the motors.
//I have not declared enable pins because I want the motor to run when I turn it on.
// If you want to turn on the motor manually then you can connect the enable pin.
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
  direction. By reversing, you can change the direction of the motors.
  digitalWrite(leftForward , HIGH);
  digitalWrite(leftBackward , LOW);
  digitalWrite(rightForward , HIGH);
  digitalWrite(rightBackward , LOW);
  printf("Something was changed");
}
void attack()
{
  // Aims to push enemy bot out of circle
}

void defend()
{
  // Aims to prevent being pushed out of the circle
}

void leftTurn()
{
  // Turns the bot left for defense and to get into attacking position
}

void rightTurn()
{
  // Turns the bot right for defense and to get into attacking position
}

void charge()
{
  // Motors set to full speed forwards to attack
}

void moveForward ()
{
  // Moves the bot forwards
}

void moveBackward ()
{
  // Moves the bot backwards+
}