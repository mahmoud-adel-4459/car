#include <AFMotor.h>

AF_DCMotor motor1(1); // Motor 1 connected to M1
AF_DCMotor motor2(2); // Motor 2 connected to M
char t;
 
void setup() {
pinMode(13,OUTPUT);   //left motors forward
pinMode(12,OUTPUT);   //left motors reverse
pinMode(11,OUTPUT);   //right motors forward
pinMode(10,OUTPUT);   //right motors reverse
pinMode(9,OUTPUT);   //Led
Serial.begin(9600);
 
}
 
void loop() {
if(Serial.available()){
  t = Serial.read();
  Serial.println(t);
}
 
if(t == 'F'){            //move forward(all motors rotate in forward direction)
  digitalWrite(13,HIGH);
  digitalWrite(11,HIGH);
}
 
else if(t == 'G'){      //move reverse (all motors rotate in reverse direction)
  digitalWrite(12,HIGH);
  digitalWrite(10,HIGH);
}
 
else if(t == 'R'){      //turn right (left side motors rotate in forward direction, right side motors doesn't rotate)
  digitalWrite(11,HIGH);
}
 
else if(t == 'L'){      //turn left (right side motors rotate in forward direction, left side motors doesn't rotate)
  digitalWrite(13,HIGH);
}

else if(t == 'M'){    //turn led on or off)
  digitalWrite(9,HIGH);
}
else if(t == 'm'){
  digitalWrite(9,LOW);
}
 
else if(t == 'S'){      //STOP (all motors stop)
  digitalWrite(13,LOW);
  digitalWrite(12,LOW);
  digitalWrite(11,LOW);
  digitalWrite(10,LOW);
}
else if(t == 'Q'){
   digitalWrite(13,HIGH);
  delay(2000);
    digitalWrite(13,HIGH);
  digitalWrite(11,HIGH);
  delay(2000) ;
  digitalWrite(13,LOW);
  digitalWrite(11,LOW);
}
 else if(t == 'E'){
   digitalWrite(11,HIGH);
  delay(2000);
    digitalWrite(13,HIGH);
  digitalWrite(11,HIGH);
  delay(2000); 
  digitalWrite(13,LOW);
  digitalWrite(11,LOW);
}
 else if(t == 'Z'){
   digitalWrite(13,HIGH);
  delay(2000);
  digitalWrite(12,HIGH);
  digitalWrite(10,HIGH);
  delay(2000) ;
  digitalWrite(12,LOW);
  digitalWrite(10,LOW);
  digitalWrite(13,LOW);
}
 else if(t == 'C'){
   digitalWrite(11,HIGH);
  delay(2000);
    digitalWrite(12,HIGH);
  digitalWrite(10,HIGH);
  delay(2000); 
  digitalWrite(12,LOW);
  digitalWrite(11,LOW);
  digitalWrite(10,LOW);
}
}