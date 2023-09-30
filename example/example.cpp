#include <Arduino.h>
#include <HardwareSerial.h>
#include <FSR_Lib.h>

FSR FSR_sample = FSR(10, 3300, 14); // GPIO14番を使用，10kΩ抵抗をプルアップ抵抗として使用し，3.3Vの電圧を印加しています．

HardwareSerial Debug_Serial(0); // Use USB

void setup()
{
    Debug_Serial.begin(115200);
    FSR_sample.Calibration();
}

void loop()
{
    Debug_Serial.print("圧力[gf]：");
    Debug_Serial.println(FSR_sample.Force());
    wait(1000);
}