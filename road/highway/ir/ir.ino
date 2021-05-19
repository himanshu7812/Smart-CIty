//sensor ka input pins
int sensor1=16;
int sensor2=5;
int sensor3=4;
int sensor4=0;
int sensor5=2;

int sensor6=14;
int sensor7=10;
int LIGHT=13;

//street light ka output
int street1=1;
int street2=3;
int street3=15;
int street4=12;

//reset();
void setup() {
  
  Serial.begin(115200);
  // put your setup code here, to run once:
pinMode(sensor1, INPUT);
pinMode(sensor2, INPUT);
pinMode(sensor3, INPUT);
pinMode(sensor4, INPUT);
pinMode(sensor5, INPUT);
pinMode(sensor6, INPUT);
pinMode(sensor7, INPUT);


pinMode(street1, OUTPUT);
pinMode(street2, OUTPUT);
pinMode(street3, OUTPUT);
pinMode(street4, OUTPUT);


pinMode(LIGHT, INPUT);


}

void loop() {


  
 
  // put your main code here, to run repeatedly:
  int VAL=digitalRead(LIGHT);
 if(VAL==1)
  {
   int a = digitalRead(sensor1);
  int b = digitalRead(sensor2);
  int c = digitalRead(sensor3);
  int d = digitalRead(sensor4);
  int e = digitalRead(sensor5);
  int f = digitalRead(sensor6);
  int g = digitalRead(sensor7);
 
if(a==0){
  analogWrite(street1,1500);
  delay(2000);
}
else if(b==0)
{
  analogWrite(street2,1500);
  delay(2000);
}
else if(c==0)
{
 
 analogWrite(street3,1500);
 delay(2000);
}

else if(d==0)
{
  analogWrite(street4,1500);
 delay(2000);
}
else if(e==0)
{
  analogWrite(street3,1500);
  delay(2000);
}
else if(f==0)
{
  analogWrite(street2,1500);
  delay(2000);
}
else if(g==0)
{
  analogWrite(street1,1500);
  delay(2000);
}

else{
  analogWrite(street1, 200);
 analogWrite(street2, 200);
analogWrite(street3, 200);
 analogWrite(street4, 200); 
}

  }else{
    digitalWrite(street1, LOW);
    digitalWrite(street2, LOW);
    digitalWrite(street3, LOW);
    digitalWrite(street4, LOW);
    
  }
//Serial.print(b);
}
