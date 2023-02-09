void setup() {
  class Ultrasonic {
    int trigger_pin, echo_pin;//pins on which the pulse is sent and recieved
  public:
    Ultrasonic(int trigger_pin, int echo_pin): trigger_pin(trigger_pin), echo_pin(echo_pin) {//ultrasonic constructor
      pinMode(trigger_pin, OUTPUT);
      pinMode(echo_pin, INPUT);
    }
    //if an object is detected, true is returned if the object is within the threshold, else false is returned.
    bool object_detected() {
      static const unsigned long PULSE_MIN = 7000, PULSE_MAX = 9400; // duration of pulse in microseconds
      digitalWrite(trigger_pin, HIGH);
      delayMicroseconds(15);
      digitalWrite(trigger_pin, LOW);
      unsigned long pulse = pulseIn(echo_pin, HIGH);
      return pulse >= PULSE_MIN && pulse <= PULSE_MAX;
    }
};
Ultrasonic sense1= new Ultrasonic(1,2);
Ultrasonic sense2= new Ultrasonic(3,4);
}

void loop() {
  // put your main code here, to run repeatedly:

}
