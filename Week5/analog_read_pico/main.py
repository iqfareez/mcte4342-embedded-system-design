import machine
import utime

pot = machine.ADC(27)  # ADC1

while True:
    value = pot.read_u16()  # 16-bit (max 65535)
    print("ADC: ", value)
    utime.sleep(.2)
