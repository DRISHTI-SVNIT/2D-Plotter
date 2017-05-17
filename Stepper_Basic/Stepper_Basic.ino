#define STEP 2
#define DIR 5
#define STEP_ 1.8

void setup()
{
  pinMode(STEP, OUTPUT);
  pinMode(DIR, OUTPUT);
  digitalWrite(DIR, LOW);
  Serial.begin(9600);
}

void loop()
{
  int i;
  for (i = 0; i < 200; ++i)
  {
    digitalWrite(STEP, HIGH);
    delayMicroseconds(500);
    digitalWrite(STEP, LOW);
    delayMicroseconds(500);
  }
  delay(2);
  digitalWrite(DIR,LOW);
  for(i=0;i<200;++i)
  {
    digitalWrite(STEP,HIGH);
    delayMicroseconds(1000);
    digitalWrite(STEP,LOW);
    delayMicroseconds(1000);
  }
}
