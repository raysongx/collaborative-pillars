#include <math.h>
#include <CapacitiveSensor.h>

int sensorPin = A0;
int threshold = 500;
int relayOut = 3;
int timer = 0;

void setup() {
    Serial.begin(9600);
    pinMode(3, OUTPUT);
    for (int i = 0; i < 10; i++) {
        analogRead(sensorPin);
        delay(50);
    }
}

void loop() {             
    int reading = analogRead(sensorPin);
    timer += 1;
    Serial.println(timer);
    if (reading > threshold && timer >= 100){
        digitalWrite(relayOut, HIGH);
        Serial.println("self touched!");
        delay(2000);
        timer = 0;
    } else if (reading > threshold) {
        digitalWrite(relayOut, LOW);
        Serial.println("not touched!");
    } else {
        digitalWrite(relayOut, HIGH);
        Serial.println("touched!");
        timer = 0;
    }
    // Serial.print(reading);
    delay(100);            
}