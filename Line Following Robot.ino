/*------ Arduino Line Follower Code----- */
/*-------definning Inputs------*/
#define LS 4      // left sensor
#define RS 3     // right sensor
int flag=0;
/*-------definning Outputs------*/
#define LM1 6       // left motor
#define LM2 7       // left motor
#define RM1 8       // right motor
#define RM2 9       // right motor
#define MtrspeedA 10 
#define MtrspeedB 5
#define mainl 13
#define mainr 12 

void setup()
{
  pinMode(LS, INPUT);
  pinMode(RS, INPUT);
  pinMode(LM1, OUTPUT);
  pinMode(LM2, OUTPUT);
  pinMode(RM1, OUTPUT);
  pinMode(RM2, OUTPUT);
  Serial.begin(9600);
}
void loop()
{
  if(!(digitalRead(LS)) && !(digitalRead(RS)) )     // Move Forward
  {
    digitalWrite(LM1, LOW);
    digitalWrite(LM2, HIGH);
    digitalWrite(RM1, HIGH);
    digitalWrite(RM2, LOW);
    
    analogWrite(MtrspeedA, 170);
    analogWrite(MtrspeedB, 100);
  }
  
  if(digitalRead(LS) && !(digitalRead(RS)))     // Turn LEFT
  {
    digitalWrite(LM1, HIGH);
    digitalWrite(LM2, LOW);
    digitalWrite(RM1, HIGH);
    digitalWrite(RM2, LOW);
    analogWrite(MtrspeedA, 180);//LEFT
    analogWrite(MtrspeedB,120);//RIGHT

   
  }
  
  if(!(digitalRead(LS)) && digitalRead(RS))     // turn RIGHT
  {
    digitalWrite(LM1, LOW);
    digitalWrite(LM2, HIGH);
    digitalWrite(RM1, LOW);
    digitalWrite(RM2, HIGH);
    analogWrite(MtrspeedA, 200);//LEFT
    analogWrite(MtrspeedB, 120);//RIGTH

   
  }
  
  if(digitalRead(LS) && digitalRead(RS))     // stop
  {
    digitalWrite(LM1, HIGH);
    digitalWrite(LM2, HIGH);
    digitalWrite(RM1, HIGH);
    digitalWrite(RM2, HIGH);
    analogWrite(MtrspeedA, 0);
    analogWrite(MtrspeedB, 0);
   
    
    if(flag==0)
    { 
      int c=0;
     while(c<10)
     {
      digitalWrite(mainl, HIGH);
     digitalWrite(mainr, LOW);
     delay(20);
     digitalWrite(mainl, LOW);
     digitalWrite(mainr, LOW);
     delay(80);
      c++;
     }
     digitalWrite(mainl, LOW);
     digitalWrite(mainr, LOW);
    }
    else
    { 
      int c1=0;
     while(c1<10)
     {
      digitalWrite(mainl, LOW);
     digitalWrite(mainr, HIGH);
     delay(20);
     digitalWrite(mainl, LOW);
     digitalWrite(mainr, LOW);
     delay(80);
      c1++;
     }
     digitalWrite(mainl, LOW);
     digitalWrite(mainr, LOW);
     
    
    }
    while(digitalRead(LS) && digitalRead(RS))
    {
      
    digitalWrite(LM1, LOW);
    digitalWrite(LM2, HIGH);
    
    digitalWrite(RM1, HIGH);
    digitalWrite(RM2, LOW);
    
    analogWrite(MtrspeedA, 170);
    analogWrite(MtrspeedB, 100);
    }
    if(flag==0)
    {
     flag=1; 
    }
    else
    {
      flag=0;
    }
}
}
