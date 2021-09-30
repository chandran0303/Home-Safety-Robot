int enA = 10;
int in1 = 9;
int in2 = 8;
// motor two
int enB = 5;
int in3 = 7;
int in4 = 6;
int sensorvalue2,sensorvalue1,tempsensor,gassensor;
#define rs A0
#define ls A1
#define temp A2
#define gas A3
#define sp 100
void setup()
{
  // set all the motor control pins to outputs
  pinMode(enA, OUTPUT);
  pinMode(enB, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
  Serial.begin(115200);
   pinMode(12,OUTPUT);
}
void loop()
{
  // this function will run the motors in both directions at a fixed speed
  // turn on motor A
  sensorvalue2 = analogRead(rs);
  sensorvalue1 = analogRead(ls);
  tempsensor=analogRead(temp);
  float c=((tempsensor/1024.0)*500);
  gassensor=analogRead(gas);
   if(sensorvalue2<100 && sensorvalue1<100) 
   {
     delay(30); 
  digitalWrite(in2, HIGH);
  digitalWrite(in1, LOW);
  // set speed to 200 out of possible range 0~255
  analogWrite(enA, sp);
  // turn on motor B
  digitalWrite(in4, HIGH);
  digitalWrite(in3, LOW);
  // set speed to 200 out of possible range 0~255
  analogWrite(enB, sp);
  
   }
   else if(sensorvalue2>100 && sensorvalue1 <100)
   {
    delay(30);
     digitalWrite(in2, HIGH);
  digitalWrite(in1, LOW);
  // set speed to 200 out of possible range 0~255
  analogWrite(enA, 0);
  // turn on motor B
  digitalWrite(in4, HIGH);
  digitalWrite(in3, LOW);
  // set speed to 200 out of possible range 0~255
  analogWrite(enB, sp);
  
   }
    else if(sensorvalue1>100 && sensorvalue2 <100)
   {
    delay(30);
     digitalWrite(in2, HIGH);
  digitalWrite(in1, LOW);
  // set speed to 200 out of possible range 0~255
  analogWrite(enA,sp);
  // turn on motor B
  digitalWrite(in4, HIGH);
  digitalWrite(in3, LOW);
  // set speed to 200 out of possible range 0~255
  analogWrite(enB, 0);
 
   }
    else 
   {
    delay(30);
     digitalWrite(in2, HIGH);
  digitalWrite(in1, LOW);
  // set speed to 200 out of possible range 0~255
  analogWrite(enA, 0);
  // turn on motor B
  digitalWrite(in4, HIGH);
  digitalWrite(in3, LOW);
  // set speed to 200 out of possible range 0~255
  analogWrite(enB, 0); 
   }
   Serial.print("Temperature-");
   Serial.println(c);
   Serial.print("Gas sensor-");
   Serial.println(gassensor);
   if(c>=40)
   {
    tone(12,500,10);
    delay(100);
   }
   else if(c<40)
   {
    noTone(12);
   }
   if(gassensor>=250)
   {
    tone(12,500,10);
   }
   else if(gassensor<250)
   {
     noTone(12);
   }
   }