import serial
import time
ser=serial.Serial("/dev/ttyACM0")
ser.baudrate=115200

while True:
        ser.write(chr(123))

	time.sleep(0.5)
	
