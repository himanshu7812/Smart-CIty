int sen1=16;
int sen2=5;
int sen3=4;
void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
pinMode(sen1,INPUT);
pinMode(sen2,INPUT);
pinMode(sen3,INPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
int state1=digitalRead(sen1);
int state2=digitalRead(sen2);
int state3=digitalRead(sen3);
int n;
if(state1==LOW)
{
  if(state1==LOW&&state2==LOW&&state3==LOW)
  {
    Serial.println("all three parking slots are busy");
  }
  else if(state1==LOW&&state2==LOW)
  {
    Serial.println("2nd parking slots and 1st parking slots are busy");
  }
  else if(state1==LOW&&state3==LOW)
  {
    Serial.println("3rd parking slots and 1st parking slots are busy");
  }
  else
  {
    Serial.println("only 1st parking slot is busy");
  }
}
else if(state2==LOW)
{
  if(state1==LOW&&state2==LOW&&state3==LOW)
  {
    Serial.println("all three are busy");
  }
  else if(state1==LOW&&state2==LOW)
  {
    Serial.println("2nd parking slots and 1st parking slot are busy");
  }
  else if(state2==LOW&&state3==LOW)
  {
    Serial.println("3rd parking slots and 2nd parking slots are busy");
  }
  else
  {
    Serial.println("only 2nd parking slot is busy");
  }
}
else if(state3==LOW)
{
  if(state1==LOW&&state2==LOW&&state3==LOW)
  {
    Serial.println("all three parking slots are busy");
  }
  else if(state3==LOW&&state2==LOW)
  {
    Serial.println("2nd and 3rd parking slots are busy");
  }
  else if(state1==LOW&&state3==LOW)
  {
    Serial.println("3rd and 1st parking slots are busy");
  }
  else
  {
    Serial.println("only 3 parking slot is busy");
  }
}
else 
{
  Serial.println("all parking slots  are empty");
}
}
