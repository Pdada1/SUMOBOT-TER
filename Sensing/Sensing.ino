#include "FastTrig.h"
Ultrasonic sensor1;
Ultrasonic sensor2;
class Ultrasonic {
    int trigger_pin, echo_pin;//pins on which the pulse is sent and recieved
  public:
    Ultrasonic(int trigger_pin, int echo_pin): trigger_pin(trigger_pin), echo_pin(echo_pin) {//ultrasonic constructor
      pinMode(trigger_pin, OUTPUT);
      pinMode(echo_pin, INPUT);
    }
    //if an object is detected, true is returned if the object is within the threshold, else false is returned.
    long object_detected() {
      static const unsigned long PULSE_MIN = 7000, PULSE_MAX = 9400; // duration of pulse in microseconds
      digitalWrite(trigger_pin, HIGH);
      delayMicroseconds(15);
      digitalWrite(trigger_pin, LOW);
      unsigned long pulse = pulseIn(echo_pin, HIGH);
      return microsecondsToCentimeters(pulse);
    }
    long microsecondsToCentimeters(long microseconds) {
   return microseconds / 29 / 2;
}
};

long dcalc(long dsense, long d1, long d2)
{
   double angle1 = icos(double(pow(d2,2)-pow(d1,2)-pow(dsense,2))/(2*d1*dsense));
   double angle2 = icos(double(pow(d1,2)-pow(d2,2)-pow(dsense,2))/(2*d2*dsense));

}
void setup() {
Ultrasonic sensor1 = Ultrasonic(1, 2);
Ultrasonic sensor2 = Ultrasonic(3, 4);
long sensord=20; //to change for later to cm
}

void loop() {
  unsigned long d1= sensor1.object_detected();
  unsigned long d2= sensor1.object_detected();
  
