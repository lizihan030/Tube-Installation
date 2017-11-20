const int TrigPin1=2;
const int EchoPin1=3;



float cm1;

void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
pinMode(TrigPin1, OUTPUT);
pinMode(EchoPin1,INPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
digitalWrite(TrigPin1,LOW);
delay(20);
digitalWrite(TrigPin1,HIGH);
delay(100);
digitalWrite(TrigPin1,LOW);

cm1 = pulseIn(EchoPin1,HIGH)/100;
Serial.print(cm1);
Serial.println();





if(cm1>110)
{
  noTone(8);
}
else
{
  tone(8,800-cm1*3,3*cm1);
  delay(cm1*10);
}







}
