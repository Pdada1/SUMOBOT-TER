
class Ultrasonic {
  int trigger_pin, echo_pin;  //pins on which the pulse is sent and recieved
public:
  Ultrasonic() {
  }

  Ultrasonic(int trigger_pin, int echo_pin)
    : trigger_pin(trigger_pin), echo_pin(echo_pin) {  //ultrasonic constructor
    pinMode(trigger_pin, OUTPUT);
    pinMode(echo_pin, INPUT);
  }
  //if an object is detected, true is returned if the object is within the threshold, else false is returned.
  long object_detected() {
    static const unsigned long PULSE_MIN = 7000, PULSE_MAX = 9400;  // duration of pulse in microseconds
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
Ultrasonic sensor1;
Ultrasonic sensor2;
double dcalc(long dsense, long d2, long d3) {
  double s = (dsense + d2 + d3) / 2;
  double d = 2 * sqrt((double)(s * (s - dsense) * (s - d2) * (s - d3))) / (double)(dsense);
  return d;
}

void setup() {
  sensor1 = Ultrasonic(2, 3);
  sensor2 = Ultrasonic(4, 5);
  Serial.begin(9600);
}

void loop() {
  unsigned long d2 = sensor1.object_detected();
  unsigned long d3 = sensor2.object_detected();
  long snsed = 7;  //to change for later to cm
  Serial.println(dcalc(snsed, d2, d3));
}