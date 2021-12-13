#define BLYNK_PRINT Serial
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
#include <Servo.h>

Servo servo;
int m;
int gateStart = 0;
int gateEnd = 95;
int gateOpenTime = 200;

char auth[] = "xxxxxxx";
char ssid[] = "xxxxxxx";
char pass[] = "xxxxxxx";

void setup()
{
  Serial.begin(9600);
  Blynk.begin(auth, ssid, pass);
  servo.attach(15); // NodeMcu D8 Pin 
}

void loop()
{
  Blynk.run();
}

BLYNK_WRITE(V3)
{
  servo.write(gateEnd);
  delay(gateOpenTime);
  servo.write(gateStart);
}

BLYNK_WRITE(V0)
{
  m = param.asInt();
}


BLYNK_WRITE(V1)
{
  for(int i=0;i<=m;i++)
  {
    servo.write(gateEnd);
    delay(gateOpenTime);
    servo.write(gateStart);
  }
}

BLYNK_WRITE(V2) 
{
  int pinData = param.asInt();
  if(pinData == 1)
  {
    servo.write(gateEnd);
    delay(gateOpenTime);
    servo.write(gateStart); 
  }
}
