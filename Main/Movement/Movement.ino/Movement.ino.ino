//Declaring the pins for controlling the motors.
//I have not declared enable pins because I want the motor to run when I turn it on.
// If you want to turn on the motor manually then you can connect the enable pin.



// Turn off Motors by setting pinMode to something other than OUTPUT
// Motors run in one direction by using digitalWrite with one left and one right



const int leftForward = 8;
const int leftBackward = 9;
const int rightForward = 10;
const int rightBackward = 10;
Sensor sense = new Sensor();
void setup()
{
  pinMode(leftForward, OUTPUT);
  pinMode(leftBackward, OUTPUT);
  pinMode(rightForward, OUTPUT);
  pinMODE(rightBackward, OUTPUT);
  while (true) {
    // Ensures bot is safe by moving away from white line boundary toward center of circle
    avoidBoundaryLeft();
    avoidBoundaryRight();
    avoidBoundaryBack();
    // Turns to get into attacking position when enemy bot is directly in front
    // Chooses random direction to turn to make bot movement unpredictable
    int rand = random()%2; // Generates 0 or 1     
    while (!sense.inFront()) {
      if (rand == 0) {
        leftTurn();        
      }
      else {
        rightTurn();
      }
    }
    attack(); // Aims to knock enemy bot out of circle
  }  
}

void attack()
{
  // Aims to knock enemy bot out of circle
  // Charges
  while (sense.inFront()) {
    digitalWrite(leftForward, LOW);
    digitalWrite(leftBackward, HIGH);
    digitalWrite(rightForward, LOW);
    digitalWrite(rightBackward, HIGH);
  }
  // Brakes if enemy bot has dodged
  digitalWrite(leftForward, LOW);
  digitalWrite(leftBackward, LOW);
  digitalWrite(rightForward, LOW);
  digitalWrite(rightBackward, LOW);
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
  digitalWrite(leftForward, LOW);
  digitalWrite(leftBackward, HIGH);
  digitalWrite(rightForward, LOW);
  digitalWrite(rightBackward, HIGH);
  delay (1000);
  // Brakes the bot
  digitalWrite(leftForward, LOW);
  digitalWrite(leftBackward, LOW);
  digitalWrite(rightForward, LOW);
  digitalWrite(rightBackward, LOW);
}

void leftTurn ()
{
  // Turns the bot right for defense and to get into attacking position by making one wheel spin faster
  digitalWrite(leftForward, LOW);
  digitalWrite(leftBackward, HIGH);
  digitalWrite(rightForward, HIGH);
  digitalWrite(rightBackward, LOW);
}

void rightTurn()
{
  // Turns the bot right for defense and to get into attacking position by making one wheel spin faster
  digitalWrite(leftForward, HIGH);
  digitalWrite(leftBackward, LOW);
  digitalWrite(rightForward, LOW);
  digitalWrite(rightBackward, HIGH);
}

void leftTurn90 () {
  // Turns the bot left 90 degrees
  digitalWrite(leftForward, LOW);
  digitalWrite(leftBackward, HIGH);
  digitalWrite(rightForward, HIGH);
  digitalWrite(rightBackward, LOW);
  delay(/*x*/); // x to be determined upon testing rotation speed
  stop ();
}

void rightTurn90 () {
  // Turns the bot right 90 degrees
  digitalWrite(leftForward, HIGH);
  digitalWrite(leftBackward, LOW);
  digitalWrite(rightForward, LOW);
  digitalWrite(rightBackward, HIGH);
  delay(/*x*/); // x to be determined upon testing rotation speed
  stop ();
}
