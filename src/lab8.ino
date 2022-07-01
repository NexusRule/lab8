SYSTEM_MODE(MANUAL);
SYSTEM_THREAD(ENABLED);
#include <Wire.h>
#include "SparkFun_VCNL4040_Arduino_Library.h"
VCNL4040 proximitySensor;

void setup()
{
    Serial.begin(9600);

    pinMode(D8, OUTPUT);
    pinMode(D7, OUTPUT);
    pinMode(D6, OUTPUT);

    Wire.begin();
    while (proximitySensor.begin() == false)
  {
    Serial.println("Device not found. Please check wiring.");
  }
}

void loop()
{
    int proxValue = proximitySensor.getProximity();

    Serial.print(proxValue);
    Serial.println();

    if (proxValue >= 75)
    {
        digitalWrite(D8, HIGH);
        digitalWrite(D7, LOW);
        digitalWrite(D6, LOW);
        Serial.write("RED ON");
    }
    else if (proxValue >= 10)
    {
        digitalWrite(D7, HIGH);
        digitalWrite(D6, LOW);
        digitalWrite(D8, LOW);
        Serial.write("YELLOW ON");
    }
    else if (proxValue <= 10)
    {
        digitalWrite(D6, HIGH);
        digitalWrite(D7, LOW);
        digitalWrite(D8, LOW);
        Serial.write("GREEN ON");
    }
    else
    {
        digitalWrite(D6, LOW);
        digitalWrite(D5, LOW);
        digitalWrite(D4, LOW);
        Serial.write("NONE ON");
    }
}
