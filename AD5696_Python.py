import smbus
import time

# Get I2C bus
bus = smbus.SMBus(1)

#       0x8000(32768)   Selected all DAC channels
# 0x0c --- i2c address
# 0x31 -- DAC cahnnel one
while True:
    for i in range(0,32768):
        data1 = (i>>4)
        data2 = (i&15)<<4
        data = [data1, data2]
        bus.write_i2c_block_data(0x0c, 0x31, data)
        time.sleep(0.01)
        print "Writing on DAC %d DAC value " %i
        i = i+1
