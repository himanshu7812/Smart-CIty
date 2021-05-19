#include <LiquidCrystal_I2C.h> //This library you can add via Include Library > Manage Library > 
LiquidCrystal_I2C lcd(0x27, 16, 2);


// defines pins numbers
const int trigPin = 2;  //D4
const int echoPin = 0;  //D3
int ledpin = 14;//D5
// defines variables
long duration;
int distance;

void setup() {
pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
pinMode(echoPin, INPUT);// Sets the echoPin as an Input
pinMode(ledpin,OUTPUT);
Serial.begin(9600); 
lcd.begin(16,2);
lcd.setCursor(5,0);
  lcd.init();   // initializing the LCD
  lcd.backlight(); // Enable or Turn On the backlight 
  lcd.clear();
}// Starts the serial communication


void loop() {
// Clears the trigPin
digitalWrite(trigPin, LOW);
delayMicroseconds(2);

// Sets the trigPin on HIGH state for 10 micro seconds
digitalWrite(trigPin, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin, LOW);

// Reads the echoPin, returns the sound wave travel time in microseconds
duration = pulseIn(echoPin, HIGH);

// Calculating the distance
distance= duration*0.034/2;
if(distance<10)
{ String myString = "people are crossing";
  lcd.setCursor(16,1);
  lcd.print(myString);

  for (int scrollCounter = 0; scrollCounter < 28; scrollCounter++) 
  { 

    lcd.scrollDisplayLeft(); 

    delay(250);
  }
  digitalWrite(ledpin,HIGH);
   //lcd.setCursor(0,0);
 //lcd.print("people are crossing");
//delay(3500);
 lcd.clear();
 //delay(500);
}
else
{
  digitalWrite(ledpin,LOW);
   
}
// Prints the distance on the Serial Monitor
Serial.print("Distance: ");
Serial.println(distance);
delay(2000);
}
