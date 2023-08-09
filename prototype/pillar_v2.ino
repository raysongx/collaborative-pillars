#include <math.h>
#include <CapacitiveSensor.h>

int sensorPin = A0;
int threshold = 500;
int relayOut = 3;

void setup() {
    Serial.begin(9600);
    pinMode(3, OUTPUT);
    for (int i = 0; i < 20; i++) {
        analogRead(sensorPin);
        delay(50);
    }
}

void loop() {             
    int reading = analogRead(sensorPin);
    // Serial.println(reading);

    if (reading > threshold){
        digitalWrite(relayOut, LOW);
        Serial.println("touched!");
    }
    else {
        digitalWrite(relayOut, HIGH);
        Serial.println("not touched!");
    }
    delay(50);            
}