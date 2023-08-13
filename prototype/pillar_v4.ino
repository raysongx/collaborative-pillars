#include <math.h>
#include <CapacitiveSensor.h>

int sensorPin = A0; // Input
int threshold = 500;
int relayOut = 3; // Relay Pin
int timer = 0; // Timer
int autoTime = 200; // Auto Time
int autoRunning = 5000; // Auto Runing Time

void setup() {
    Serial.begin(9600);
    pinMode(3, OUTPUT);
    // Sensor Testing
    for (int i = 0; i < 10; i++) {
        analogRead(sensorPin);
        delay(50);
    }
}

void loop() {             
    int reading = analogRead(sensorPin);
    timer += 1;
    Serial.println(timer);
    if (reading > threshold && timer >= autoTime){
        // Auto Running
        digitalWrite(relayOut, HIGH);
        Serial.println("self touched!");
        delay(autoRunning);
        timer = 0;
    } else if (reading > threshold) {
        // Relay Off
        digitalWrite(relayOut, LOW);
        Serial.println("not touched!");
    } else {
        // Input Running
        digitalWrite(relayOut, HIGH);
        Serial.println("touched!");
        timer = 0;
    }
    // Serial.print(reading);
    delay(50);            
}