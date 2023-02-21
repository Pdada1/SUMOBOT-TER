void setup() {                
 // Motor_1 controll pin initiate;
 pinMode(4, OUTPUT);     
 pinMode(5, OUTPUT);    
 pinMode(9, OUTPUT); // Speed control
 
 // Motor_2 controll pin initiate;
 pinMode(7, OUTPUT);     
 pinMode(8, OUTPUT);    
 pinMode(10, OUTPUT);  // Speed control
 
 //Enable the Motor Shield output;  
 pinMode(6, OUTPUT); 
 digitalWrite(6, HIGH);  
}
void loop() {
    
   analogWrite(9,255);    // set the motor_1 speed ;
   digitalWrite(4, HIGH);   
   digitalWrite(5, LOW);  // Set the rotation of motor_1
   
   analogWrite(10,255);    // set the motor_2 speed ;
   digitalWrite(7, HIGH);  
   digitalWrite(8, LOW);  // Set the rotation of motor_1
 
  delay(5000);               // wait for a 5 seconds
}
