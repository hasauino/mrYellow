import serial
import time
ser=serial.Serial("/dev/ttyACM0")
ser.baudrate=9600

while True:
	ser.write('a')
	time.sleep(1)

