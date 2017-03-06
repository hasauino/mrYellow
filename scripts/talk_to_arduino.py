import serial
import time
ser=serial.Serial("/dev/ttyACM0",115200)
time.sleep(1)


while True:
        ser.write('a')

	time.sleep(0.5)
	
