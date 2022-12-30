import board
import busio
import analogio
import time

pot = analogio.AnalogIn(board.A0)
uart = busio.UART(board.GP0, None, baudrate=115200) # UART transmit only

while True:
    value = pot.value  # 16-bit (max 65535)
    print("ADC: ", value)
    uart.write(bytearray(value))
    uart.write(bytearray(" \n".encode()))
    time.sleep(.1)
