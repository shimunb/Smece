#include <RH_ASK.h>
#include <SPI.h> // Not actualy used but needed to compile
#define led 13
int b=0;
RH_ASK driver;


void setup()
{   
    
    pinMode(led, OUTPUT);
    Serial.begin(9600);  // Debugging only
    if (!driver.init())
         Serial.println("init failed");
    Serial.println("dela11");
    digitalWrite(led, HIGH);
    delay(500);
}

void loop()
{
    uint8_t buf[1];
    uint8_t buflen = sizeof(buf);
    if (driver.recv(buf, &buflen)) // Non-blocking
    {
      int i;
      // Message with a good checksum received, dump it.
      Serial.print("Message: ");
      Serial.println((char*)buf);
      digitalWrite(led, HIGH);
      delay(200);
      Serial.println("ledica??");
    }
    digitalWrite(led, LOW);
    
}
