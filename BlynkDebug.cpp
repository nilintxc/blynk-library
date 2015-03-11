/**
 * @file       BlynkDebug.cpp
 * @author     Volodymyr Shymanskyy
 * @date       Jan 2015
 * @brief      Debug utilities for Arduino
 */

#include <Blynk/BlynkDebug.h>
#include <Arduino.h>

size_t BlynkFreeRam()
{
    extern int __heap_start, *__brkval;
    int v;
    return (int) &v - (__brkval == 0 ? (int) &__heap_start : (int) __brkval);
}

void BlynkReset()
{
    void(*resetFunc)(void) = 0;
    resetFunc();
}

void BlynkFatal()
{
    pinMode(LED_BUILTIN, OUTPUT);
    const int rate = 250;
    int i = 10000/rate;
    while (i-- > 0) {
        digitalWrite(LED_BUILTIN, !digitalRead(LED_BUILTIN));
        delay(rate);
    }
    BLYNK_LOG("Resetting");
    delay(100);
    BlynkReset();
}
