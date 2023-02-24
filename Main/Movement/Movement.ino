//Declaring the pins for controlling the motors.
//I have not declared enable pins because I want the motor to run when I turn it on.
// If you want to turn on the motor manually then you can connect the enable pin.



// Turn off Motors by setting pinMode to something other than OUTPUT
// Motors run in one direction by using digitalWrite with one left and one right



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



void stop ()
{
  // Brakes if enemy bot has dodged
  analogWrite(leftSpeed, 0);
  analogWrite(rightSpeed, 0);
}

/*void attack()
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
}*/

/*void avoidBoundaryLeft () {
  // Helps the bot avoid danger by moving away when boundary on left
  if (sense.lineLeft()) {
    rightTurn(); // Needs to be 90 degrees through trial and error to ensure we are moving towards inside of circle
    delay(1000);
    moveForward(); // Moves to center of circle to avoid boundary
  } 
}

void avoidBoundaryRight () {
  // Helps the bot avoid danger by moving away when boundary on right
  if (sense.lineRight()) {
    leftTurn(); // Needs to be 90 degrees through trial and error to ensure we are moving towards inside of circle
    delay(1000);
    moveForward(); // Moves to center of circle to avoid boundary
  }
}

void avoidBoundaryBack () {
  // Helps the bot avoid danger by moving away when boundary on back
  while (sense.lineBehind()) {
    rightTurn(); // Needs to be 180 degrees through trial and error to ensure we are moving towards inside of circle
    delay(2000);
    moveForward(); // Moves to center of circle to avoid boundary
  }
}*/

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

void loop ()
{
  // Ensures bot is safe by moving away from white line boundary toward center of circle
  /*avoidBoundaryLeft();
  avoidBoundaryRight();
  avoidBoundaryBack();*/
  // Turns to get into attacking position when enemy bot is directly in front
  // Chooses random direction to turn to make bot movement unpredictable
  //int rand = random()%2; // Generates 0 or 1     
  /*while (!sense.inFront()) {
    if (sense.right()) {
       rightTurn();
    }
    else if (sense.left()) {
       leftTurn();
    }
    else {
      if (rand == 0) {
        rightTurn();        
      }
      else {
        leftTurn();
      }
    }*/
    moveForward();
  }
  //attack(); // Aims to knock enemy bot out of circle