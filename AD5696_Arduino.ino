/// https://store.ncd.io/product/ad5696-16-bit-4-channel-digital-to-analog-converter-i2c-mini-module/
///https://store.ncd.io/?fwp_product_type=adapters&fwp_platform=arduino
#include <Wire.h>
void setup()
{
  Serial.begin (9600);
  Wire.begin();
}

    
void loop()
{
///i value can chnaged to generate the dac output voltgae
 for (int i=0; i <= 65536; i++)
  {
  Wire.beginTransmission(0x0c );
  Wire.write(0x31); ///// channel one
  //Wire.write(0x32); ///// channel two
  //Wire.write(0x34); ///// channel three
  //Wire.write(0x38); ///// channel four
  Wire.write(i >> 8)& 0xFF;        // 8 MSB
  Wire.write(i & 0xFF); //8 LSB
  delay(20);
  Serial.print("DAC digital Value ");
  Serial.println(i);
  Serial.print("\n");
  Wire.endTransmission();
  }
}
