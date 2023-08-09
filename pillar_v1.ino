#include <math.h>
#include <CapacitiveSensor.h>

int capL = 5;
int capR = 10;
int relayOut = 3;
CapacitiveSensor cs = CapacitiveSensor(capL,capR);

void setup() {
    Serial.begin(9600);
    pinMode(3, OUTPUT);
    cs.set_CS_AutocaL_Millis(0xFFFFFFFF);
}

void loop() {             
    long start = millis();
    long total =  cs.capacitiveSensor(30);
    // Serial.print(millis() - start);
    // Serial.print("\t");

    Serial.println(total);
    if (total < 1000){
        digitalWrite(relayOut, LOW);
    }
    else {
        digitalWrite(relayOut, HIGH);
    }
    delay(50);            
}