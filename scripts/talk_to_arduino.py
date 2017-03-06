import serial
import time
ser=serial.Serial()
ser.port="/dev/ttyACM0"
ser.baudrate=115200

while True:
        ser.open()
        ser.write(chr(123))
	ser.write(chr(55))
	ser.write('a')
	ser.write('b')
	ser.close()
	time.sleep(0.5)
	
