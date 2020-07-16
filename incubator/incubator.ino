#define FAN_PIN 8
#define LAMP_PIN 10

//Functions
void turnOnfan()
{
  digitalWrite(FAN_PIN,HIGH);
}

void turnOffFan()
{
  digitalWrite(FAN_PIN,LOW);
}

void turnOnLamp()
{
  digitalWrite(LAMP_PIN,HIGH);
}

void turnOffLamp()
{
   digitalWrite(LAMP_PIN,LOW);
}

void setup(){
  Serial.begin(9600);
  pinMode(FAN_PIN, OUTPUT);
 pinMode(FAN_PIN, OUTPUT);
  pinMode(10, OUTPUT);
}

void loop()
{
  
}
