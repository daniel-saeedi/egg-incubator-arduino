#include <dht.h>
#include <LiquidCrystal.h>
#include <avr/wdt.h>

#define FAN_PIN 8
#define LAMP_PIN 10
#define DHT22_PIN 9
#define BUZZER_PIN 13

dht DHT;
unsigned long time;

boolean reachedPerfectTemp;

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

//Functions
void turnOnFan()
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

void turnOnBuzzer()
{
  digitalWrite(BUZZER_PIN,HIGH);
}


void turnOffBuzzer()
{
  digitalWrite(BUZZER_PIN,LOW);
}

float temp = 0;
float hum  = 0;

void updateTempAndHum()
{
  int readData = DHT.read22(DHT22_PIN);
  temp = DHT.temperature; // Gets the values of the temperature
  hum = DHT.humidity; // Gets the values of the humidity
}

void updateDisplay()
{
  char line0[21]; 
  char line1[21];

  char temp_str[21];
  dtostrf(temp,4,2,temp_str);
  sprintf(line0, "T:%-7s", temp_str);

  char hum_str[21];
  dtostrf(hum,4,2,hum_str);
  sprintf(line1, "H:%-7s", hum_str);

  lcd.setCursor(0,0);
  lcd.print(line0);
   lcd.setCursor(8,0);
  lcd.print(line1);
}

void setup(){
  Serial.begin(9600);
  pinMode(FAN_PIN, OUTPUT);
  pinMode(LAMP_PIN, OUTPUT);

  // this delay help to complete all initial tasks
  delay(2000);
  wdt_enable(WDTO_8S);
}

void loop()
{
    turnOnFan();
  updateTempAndHum();
  updateDisplay();
  Serial.print("Humidity: ");
  Serial.print(hum);
  Serial.print(" %, Temp: ");
  Serial.print(temp);
  Serial.println(" Celsius");

  
  if(temp > 39)
  {
    turnOnFan();
  }else
  {
    turnOffFan();
  }

  
  if(temp < 37.2){
     turnOnLamp();
  }
  else if(temp <= 37.5 && temp >= 37.2)
  {
    if(temp == 37.5){
      reachedPerfectTemp = true;
    }else if(temp == 37.2){
      reachedPerfectTemp = false;
    }

    if(reachedPerfectTemp == true){
      turnOffLamp();
    }else{
      turnOnLamp();
    }
  }
  else{
    turnOffLamp();
  }
  if(hum > 62)
  {
    turnOnBuzzer();
  }
  else{
    turnOffBuzzer();
  }
  
  delay(2000); 
  wdt_reset();
}
