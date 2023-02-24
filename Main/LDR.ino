int sensorValue = 0;
void setup()
{
  pinMode(A0, INPUT_PULLUP);
  pinMode(A1, INPUT_PULLUP);
  pinMode(A2, INPUT_PULLUP);
  pinMode(9, OUTPUT);
  Serial.begin(9600);
}
void loop()
{
  // read the value from the sensor
  sensorValue = analogRead(A0);
  // print the sensor reading so you know its range
  Serial.println(sensorValue);
  Serial.println(analogRead(A1));
  Serial.println(analogRead(A2));
 // map the sensor reading to a range for the LED
  delay(100); // Wait for 100 millisecond(s)
}