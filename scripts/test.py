import cv2
from subprocess import call
from time import time,sleep

face_cascade = cv2.CascadeClassifier('/home/pi/mrYellow/scripts/haarcascade_frontalface_default.xml')

cap=cv2.VideoCapture(0)
sleep(1.0)

def detectFaces(cap,cv2,face_cascade):
        ret,img=cap.read()
        img=cv2.resize(img,None,fx=0.5,fy=0.5,interpolation=cv2.INTER_CUBIC)
	gray = cv2.cvtColor(img, cv2.COLOR_BGR2GRAY)
	faces = face_cascade.detectMultiScale(gray, 1.3, 5)
        return len(faces)

while True:        
        if detectFaces(cap,cv2,face_cascade)>0:
                t0=time()
                call(['aplay','/home/pi/mrYellow/soundFiles/1.wav'])
                while ((time()-t0)<10):
                        detectFaces(cap,cv2,face_cascade)
                        print 'waiting'
        print 'done'



        

