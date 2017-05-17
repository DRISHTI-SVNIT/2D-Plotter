
/* This code takes the input angle for both X & Y directions from the Serial Window and rotates the stepper accordingly */
/* AntiClockwise Direction is Positive */
#include <math.h>

#define step_x 2                         

#define dir_x 5

#define enable 8

#define angle 1.8

int stepx, flag;

long int angle_x()
{
  long int nx=Serial.parseInt();                              //reads angle for x direction from serial window
  flag=1;
  return nx;
}

void num_stepx(float nx)
{
  int steps,N;                                              //calcuates no. of steps required for x
  N=abs(nx);
  stepx=N/angle;
}

void pulsex(int stepx)
{ 
  for(int i=0;i<=stepx;++i)
      {
        
        digitalWrite(step_x,HIGH);
        delayMicroseconds(500);
        digitalWrite(step_x,LOW);
        delayMicroseconds(500);
        
      }
}

void setup() 
{
  pinMode(step_x,OUTPUT);
  pinMode(dir_x,OUTPUT);
  pinMode(enable,OUTPUT);
  Serial.begin(57600);
}

void loop() 
{
  
  long int nx;
  
  if (Serial.available())
  {
    Serial.println("enter value of nx=");                              
    nx=angle_x();
    Serial.println(nx);
  }
  
  if(flag==1)
  {
    if(nx>=0)
    {
        digitalWrite(dir_x,LOW);
        num_stepx(nx);
        pulsex(stepx);
        flag=0; 
    }
    else if(nx<0)
    {
        digitalWrite(dir_x,HIGH);
        num_stepx(nx);
        pulsex(stepx);
        flag=0; 
    }
  }
} 
