//DC motor control through bluetooth
// motor one
int enA = 10;
int in1 = 9;
int in2 = 8;
// motor two
int enB = 5;
int in3 = 7;
int in4 = 6;
int state=4;
void setup()
{
  // set all the motor control pins to outputs
  pinMode(enA, OUTPUT);
  pinMode(enB, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
  Serial.begin(9600);
}
void forward()
{ //moves motor in forward direction
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);  
  analogWrite(enA,255);
  digitalWrite(in3, HIGH);
  digitalWrite(in4,LOW);
   analogWrite(enB,255);
 
 }

void reverse()
{
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);  
  analogWrite(enA,255);
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH); 
  analogWrite(enB,255);
 
}  

void right()
{
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);  
  analogWrite(enA,255);
  digitalWrite(in3,HIGH);
  digitalWrite(in4, LOW);
  analogWrite(enB,0);

}

void left()
{
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);  
  analogWrite(enA,0);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
  analogWrite(enB,255);
  
  
}

void mstop()
{
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);  
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
}

void loop()
{
  
  
   if(Serial.available() > 0) // Checks whether data is comming from the serial port
   {
   
       state = Serial.read(); // Reads the data from the serial port
       
       switch(state)
       {
        case '0' : forward(); break;  
        case '1' : reverse(); break;  
        case '2' : left();      break;
        case '3' : right();     break;
        case '4' : mstop();     break;
       } 
   }


}

