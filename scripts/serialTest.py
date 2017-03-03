import serial
import time
ser=serial.Serial("/dev/ttyS0")
ser.baudrate=9600

while True:
    p=raw_input('enter comd: ')
    ser.write(p)
    time.sleep(2)
    while ser.in_waiting:
        print ser.read(1)

