
#include <Servo.h>   //servo library
Servo servo;     
int trigPin = 4;    
int echoPin = 0;   
int servoPin = 2;
   
 
int read1,dist;//array for average

const int IRSENSOR=14;//OUTPUT FROM IR SENSOR
void setup() {       
    Serial.begin(9600);
    servo.attach(servoPin);
    pinMode(IRSENSOR,INPUT);  
    pinMode(trigPin, OUTPUT);  
    pinMode(echoPin, INPUT);  
    //servo.write(0);         //close cap on power on
    //delay(100);
    //servo.detach(); 
} 


void loop() { 
  int read1=digitalRead(IRSENSOR);
  digitalWrite(trigPin, LOW);
delayMicroseconds(2);

// Sets the trigPin on HIGH state for 10 micro seconds
digitalWrite(trigPin, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin, LOW);

// Reads the echoPin, returns the sound wave travel time in microseconds
  if(read1==HIGH)
  {
dist = pulseIn(echoPin, HIGH);

               //delay between measurement 
if ( dist<500 ) {
   Serial.println("opening"); 
//Change distance as per your need
 servo.attach(servoPin);
  delay(1);
 servo.write(0);  
 delay(3000);

        
 servo.write(90);
    
 delay(1000);
 servo.detach(); 
 Serial.println(dist);     
}
else
{
  Serial.println(dist);
  Serial.println("closed not going to open");
  }
}
else
{
 Serial.println("hello"); 
}
//Serial.print(dist);
}
