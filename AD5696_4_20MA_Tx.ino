/// https://store.ncd.io/product/ad5696-4-channel-4-20ma-16-bit-current-loop-transmitter-with-iot-interface/
///https://store.ncd.io/?fwp_product_type=adapters&fwp_platform=arduino
#include <Wire.h>
void setup()
{
  Serial.begin (9600);
  Wire.begin();
}

    
void loop()
{
/// at DAC vlaue 415 the current output will be around 4mA and 
///at DAC vlaue 2100 the current output will be around 20mA 
/// you can change these values to tune the 4-20mA output
 for (int i=415; i <= 2100; i++)
  {
  Wire.beginTransmission(0x0c );
  Wire.write(0x31); ///// channel one
 // Wire.write(0x32); ///// channel two
//  Wire.write(0x33); ///// channel three
//  Wire.write(0x34); ///// channel four
  Wire.write(i >> 4);        // 8 MSB
  Wire.write((i & 15) << 4); //4 LSB
  delay(20);
  Serial.print("4-20mA current trnasmitter output ");
  Serial.println(i*0.0096);
  Serial.print("\n");
  Wire.endTransmission();
  }
}
