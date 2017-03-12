from multiprocessing import Process, Queue
from time import time,sleep
import numpy as np
import cv2
from subprocess import call,Popen
import serial
from copy import copy


def detectFaces(cap,cv2,face_cascade):
        ret,img=cap.read()
        img=cv2.resize(img,None,fx=0.5,fy=0.5,interpolation=cv2.INTER_CUBIC)
        gray = cv2.cvtColor(img, cv2.COLOR_BGR2GRAY)
        faces = face_cascade.detectMultiScale(gray, 1.3, 5)
        return [faces,img]

def face_detection(q):
    face_cascade = cv2.CascadeClassifier('/home/pi/mrYellow/scripts/haarcascade_frontalface_default.xml')
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
                    call(['aplay','/home/pi/mrYellow/soundFiles/4.wav'])
                    while ((time()-t0)<10):
                            detectFaces(cap,cv2,face_cascade)





def arduino_bluetooth(q):
    ser=serial.Serial("/dev/ttyS0",9600)
    sleep(1)
    ser_arduino=serial.Serial("/dev/ttyACM0",115200)
    sleep(1)  
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
            print buttons
            
            ser_arduino.write(chr(123))
            ser_arduino.write(chr(55))
            ser_arduino.write(chr(len(set(buttons))))
            for b in set(buttons):
                    ser_arduino.write(b)

            if ('5' in buttons) and ('1' in buttons):
                    call(['aplay','/home/pi/mrYellow/soundFiles/1.wav'])
                    ser.read(ser.in_waiting)
                    buttons=['0']
                    print ser.in_waiting

            if ('5' in buttons) and ('2' in buttons):
                    call(['aplay','/home/pi/mrYellow/soundFiles/2.wav'])
                    ser.read(ser.in_waiting)
                    buttons=['0']
                    print ser.in_waiting
                    
            if ('5' in buttons) and ('3' in buttons):
                    call(['aplay','/home/pi/mrYellow/soundFiles/3.wav'])
                    ser.read(ser.in_waiting)
                    buttons=['0']
                    print ser.in_waiting                  
                    

            if ('5' in buttons) and ('4' in buttons):
                    call(['aplay','/home/pi/mrYellow/soundFiles/4.wav'])
                    ser.read(ser.in_waiting)
                    buttons=['0']
                    print ser.in_waiting  



            if ('5' in buttons) and ('7' in buttons):
                    call(['aplay','/home/pi/mrYellow/soundFiles/5.wav'])
                    ser.read(ser.in_waiting)
                    buttons=['0']
                    print ser.in_waiting 
        


            if ('5' in buttons) and ('8' in buttons):
                    call(['aplay','/home/pi/mrYellow/soundFiles/6.wav'])
                    ser.read(ser.in_waiting)
                    buttons=['0']
                    print ser.in_waiting 


            if ('5' in buttons) and ('9' in buttons):
                    call(['aplay','/home/pi/mrYellow/soundFiles/7.wav'])
                    ser.read(ser.in_waiting)
                    buttons=['0']
                    print ser.in_waiting

            if ('5' in buttons) and ('A' in buttons):
                    call(['aplay','/home/pi/mrYellow/soundFiles/8.wav'])
                    ser.read(ser.in_waiting)
                    buttons=['0']
                    print ser.in_waiting 





if __name__ == '__main__':
	q = Queue(maxsize=10)
	p1 = Process(target=face_detection, args=(q,))
	p2 = Process(target=arduino_bluetooth, args=(q,))
	p1.start()
	p2.start()

