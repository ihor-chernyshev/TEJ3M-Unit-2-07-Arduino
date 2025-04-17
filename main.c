// Created by Ihor Chernyshev
// Created on March 2025
// This program controls servo through distance sensor

#include <Servo.h>

Servo servo;

const int portNumber = 8;
const int TRIG_PIN = 9;
const int ECHO_PIN = 10;
float duration;
float distance;

void setup() {
    servo.attach(portNumber);
    servo.write(0);
    delay(500);
    pinMode(TRIG_PIN, OUTPUT);
    pinMode(ECHO_PIN, INPUT);
    Serial.begin(9600); 
}

void loop() {
    delay(500);
    digitalWrite(TRIG_PIN, LOW);
    delayMicroseconds(2);
    digitalWrite(TRIG_PIN, HIGH);
    delayMicroseconds(10);
    digitalWrite(TRIG_PIN, LOW);
    duration = pulseIn(ECHO_PIN, HIGH); 
    distance = (duration*.0343)/2;
    if (distance < 50) {
        servo.write(180);
        delay(500);
        servo.write(0);
    }
}
