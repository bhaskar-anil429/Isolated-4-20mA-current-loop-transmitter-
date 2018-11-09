//////////// not tested on hardware yet!!!!!!!!!!!!!
#include <Wire.h>
byte address_mux = 0x70;
byte address_MCP4725 = 0x60;

void setup()
{
  Serial.begin (9600); ////////////////serial port
  Wire.begin();        /////////////// i2c enable
}

int set_port ( int port_value)
{
  Wire.beginTransmission(address_mux );
  byte port = port_value|8;
  Wire.write(port); 
  Wire.endTransmission();
  Serial.print (port, DEC);
  Serial.print("\n");
}

/// at DAC vlaue 290 the current output will be around 4mA and 
///at DAC vlaue 1500 the current output will be around 20mA 
/// you can change these values to tune the 4-20mA output

int set_volt ( int raw_value)
{
  Wire.beginTransmission(address_MCP4725 );
  Wire.write(64); 
  Wire.write(raw_value >> 4);        // 8 MSB
  Wire.write((raw_value & 15) << 4); //4 LSB
  Wire.endTransmission();
  Serial.print (raw_value, DEC);
  Serial.print("\n");
}

void loop()
{
  set_port(0); //////////// set port value over here///port value will go from 0-7
  set_volt(290);/////////// set dac output over here
}

