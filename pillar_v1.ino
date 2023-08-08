#include <math.h>
#include <CapacitiveSensor.h>

int capL = 3;
int capR = 5;
int relayOut = 10;
CapacitiveSensor cs_3_5 = CapacitiveSensor(capL,capR);

void setup() {
    Serial.begin(9600);
    pinMode(10, OUTPUT);
    cs_3_5.set_CS_AutocaL_Millis(0xFFFFFFFF);
}

void loop() {             
    long start = millis();
    long total =  cs_3_5.capacitiveSensor(30);
    Serial.print(millis() - start);
    Serial.print("\t");

    Serial.print(total);
    Serial.print("\t");
    if (total >= 150){
        digitalWrite(relayOut, LOW);
    }
    else {
        digitalWrite(relayOut, HIGH);
    }
    delay(100);            
}