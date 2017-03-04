from multiprocessing import Process, Queue
from time import time,sleep
import numpy as np
import cv2
from subprocess import call
import serial
from copy import copy

def detectFaces(cap,cv2,face_cascade):
        ret,img=cap.read()
        img=cv2.resize(img,None,fx=0.5,fy=0.5,interpolation=cv2.INTER_CUBIC)
        gray = cv2.cvtColor(img, cv2.COLOR_BGR2GRAY)
        faces = face_cascade.detectMultiScale(gray, 1.3, 5)
        return [faces,img]

def face_detection(q):
    face_cascade = cv2.CascadeClassifier('haarcascade_frontalface_default.xml')
    cap=cv2.VideoCapture(0)
    sleep(1.0)

    while True:
            retfunc=detectFaces(cap,cv2,face_cascade)
            num_faces=len(retfunc[0])
            if q.full():
                q.get()
            q.put(num_faces)
            if num_faces>0:
                    t0=time()
                    call(['aplay','/home/pi/mrYellow/soundFiles/ar_marhaban.wav'])
                    while ((time()-t0)<10):
                            detectFaces(cap,cv2,face_cascade)





def arduino_bluetooth(q):
    ser=serial.Serial("/dev/ttyS0")
    ser.baudrate=9600

    ser_arduino=serial.Serial("/dev/ttyACM0")
    ser_arduino.baudrate=9600
    
    buttons=['0']
    face=0
    while True:
        if ser.in_waiting:
            if ser.read(1)=='=':
                buttons=[]
                a=0
                while a !='#':
                    if ser.in_waiting:
                        a=ser.read(1)
                        buttons.append(copy(a))
                del buttons[-1]
        if not q.empty():
            if q.get()>0:
                face=1
            else:
                face=0
        if face==1:
            buttons.append('f')
        
        print list(set(buttons))
        ser_arduino.write(chr(123))
        ser_arduino.write(chr(55))
        for b in buttons:
                ser_arduino.write(b)










if __name__ == '__main__':
	q = Queue(maxsize=10)
	p1 = Process(target=face_detection, args=(q,))
	p2 = Process(target=arduino_bluetooth, args=(q,))
	p1.start()
	p2.start()

