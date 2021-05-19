#include <Servo.h>
#include <Wire.h>  // This library is already built in to the Arduino IDE
#include <LiquidCrystal_I2C.h>
void doorclose();
void dooropen();

const int greensignal=12;
const int redsignal=13;
const int tracksensor=16;
 
 
Servo servo, servo1;
LiquidCrystal_I2C lcd(0x27, 16, 2);
void setup() {
 pinMode(tracksensor, INPUT);//d0
 //pinMode(14, INPUT);
   pinMode(greensignal, OUTPUT);
   pinMode( redsignal, OUTPUT);      
   servo.attach(2);//d4
   servo1.attach(0);//D3
   servo.write(0);//motor
   servo1.write(0);//motor1
   lcd.init();   // initializing the LCD
  lcd.backlight(); // Enable or Turn On the backlight
  Serial.begin(9600);
}

void loop(){
                     
 int trackvalue=digitalRead(tracksensor);
 Serial.println(trackvalue);
 if(trackvalue == 0){
 doorclose();                         
 }
 else{
 dooropen();
 }
 //restart1();
 
}
void doorclose()
{
  digitalWrite( redsignal, HIGH);
  digitalWrite(greensignal, LOW);
//digitalWrite(14, LOW);
  servo.write(0);
  servo1.write(0);
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("train coming");
  delay(1000);
}
void dooropen()
{
   digitalWrite(greensignal, HIGH);
   digitalWrite( redsignal, LOW); 
 // digitalWrite(14, HIGH);
   servo.write(90);
   servo1.write(90);
lcd.clear();                                         
 lcd.setCursor(0, 0);
 lcd.print("track clear ");
   delay(50);
}
void restart1()
{
  
    
  
}
  
