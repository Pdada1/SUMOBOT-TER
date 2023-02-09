//Declaring the pins for controlling the motors.
//I have not declared enable pins because I want the motor to run when I turn it on.
// If you want to turn on the motor manually then you can connect the enable pin.
const int left = 8;
const int right = 9;
Sensor sense = new Sensor();
void setup()
{
  pinMode(left , OUTPUT);
  pinMode(right , OUTPUT);
  while (true) {
    // Ensures bot is safe by moving away from white line boundary toward center of circle
    avoidBoundaryLeft();
    avoidBoundaryRight();
    avoidBoundaryBack();
    // Turns to get into attacking position when enemy bot is directly in front
    while (!sense.inFront()) {
      leftTurn();
    }
    attack(); // Aims to knock enemy bot out of circle
  }  
}

void attack()
{
  // Aims to knock enemy bot out of circle
  // Charges
  while (sense.inFront()) {
    digitalWrite(left, HIGH);
    digitalWrite(right, HIGH);
  }
  // Brakes if enemy bot has dodged
  digitalWrite(left, LOW);
  digitalWrite(right, LOW);
}

void avoidBoundaryLeft () {
  // Helps the bot avoid danger by moving away when boundary on left
  while (sense.lineLeft()) {
    rightTurn90(); // Needs to be 90 degrees through trial and error to ensure we are moving towards inside of circle
    moveForward(); // Moves to center of circle to avoid boundary
  } 
}

void avoidBoundaryRight () {
  // Helps the bot avoid danger by moving away when boundary on right
  while (sense.lineRight()) {
    leftTurn90(); // Needs to be 90 degrees through trial and error to ensure we are moving towards inside of circle
    moveForward(); // Moves to center of circle to avoid boundary
  }
}

void avoidBoundaryBack () {
  // Helps the bot avoid danger by moving away when boundary on back
  while (sense.lineBehind()) {
    rightTurn180(); // Needs to be 180 degrees through trial and error to ensure we are moving towards inside of circle
    moveForward(); // Moves to center of circle to avoid boundary
  }
}

void moveForward () {
  // Moves bot forward slightly to avoid boundary
  // Bot moves forward for 1 second
  digitalWrite(left, HIGH);
  digitalWrite(right, HIGH);
  delay (1000);
  // Brakes the bot
  digitalWrite(left, LOW);
  digitalWrite(right, LOW);
}

void leftTurn ()
{
  // Turns the bot right for defense and to get into attacking position by making one wheel spin faster
  digitalWrite(left, LOW);
  digitalWrite(right, HIGH);
}

void rightTurn()
{
  // Turns the bot right for defense and to get into attacking position by making one wheel spin faster
  digitalWrite(right, LOW);
  digitalWrite(left, HIGH);
}

void leftTurn90 () {
  // Turns the bot left 90 degrees
  digitalWrite(left, LOW);
  digitalWrite(right, HIGH);
  delay(/*x*/); // x to be determined upon testing rotation speed
  digitalWrite(left, LOW);
  digitalWrite(right, LOW);
}

void rightTurn90 () {
  // Turns the bot right 90 degrees
  digitalWrite(right, LOW);
  digitalWrite(left, HIGH);
  delay(/*x*/); // x to be determined upon testing rotation speed
  digitalWrite(left, LOW);
  digitalWrite(right, LOW);
}