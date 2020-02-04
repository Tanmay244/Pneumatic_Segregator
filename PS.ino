#include<SoftwareSerial.h>
#define in1 2
#define in2 3
#define in3 4 
#define in4 5
#define si 7
#define so 8
int f;
void setup() {
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
  pinMode(si, INPUT);
  pinMode(so, OUTPUT);
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
  Serial.begin(9600);
}

void piston1_ex()
{
     digitalWrite(in1, HIGH);
     digitalWrite(in2, LOW);
     Serial.println("Piston1 OUT");
    // delay(5000); 
}
void piston1_re()
{
     digitalWrite(in1, 0);
     digitalWrite(in2, 1);
     Serial.println("Piston1 IN");
    // delay(5000); 
}
 void piston2_ex()
{
     digitalWrite(in3, HIGH);
     digitalWrite(in4, LOW);
     Serial.println("Piston2 OUT");
     delay(5000); 
}
void piston2_re()
{
     digitalWrite(in3, 0);
     digitalWrite(in4, 1);
     Serial.println("Piston2 IN");
    // delay(5000); 
}
bool sensor()
{
    digitalWrite(so, HIGH);
    f=digitalRead(si);
    if(f!=0)
    {
     Serial.println("It's a Metal");
     return 1;
    }
    else 
    {
     Serial.println("Non Metal");
     Serial.println(f);
     return 0;
    }
    digitalWrite(so, LOW);
    //delay(5000); 
  
}
void loop() {
    piston1_ex();
    delay(1000);
    piston1_re();
    if(sensor()==1)
    {
     piston2_ex();
     delay(1000);
     piston2_re();
    }  
    delay(5000);
}
