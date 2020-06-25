#include <dht.h>

dht DHT;

#define DHT11_PIN 7
#define FAN_PIN 6

void setup(){
  Serial.begin(9600);
  pinMode(FAN_PIN, OUTPUT);
 
}

void loop()
{
  digitalWrite(FAN_PIN,HIGH);
  delay(10000);
  digitalWrite(FAN_PIN,LOW);
  delay(10000);
//  int chk = DHT.read11(DHT11_PIN);
//  Serial.print("Temperature = ");
//  Serial.println(DHT.temperature);
//  Serial.print("Humidity = ");
//  Serial.println(DHT.humidity);
//  delay(2000);
}
