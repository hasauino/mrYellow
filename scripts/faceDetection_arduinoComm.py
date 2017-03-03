from multiprocessing import Process, Queue
from time import time,sleep
import numpy as np
import cv2
from subprocess import call


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
            q.put(num_faces)
            faces = retfunc[0]
            img=retfunc[1]
            for (x,y,w,h) in faces:
                    cv2.rectangle(img,(x,y),(x+w,y+h),(255,0,0),2)
                    #roi_gray = gray[y:y+h, x:x+w]
                    #roi_color = img[y:y+h, x:x+w]
            
            cv2.imshow('im',img)
            cv2.waitKey(25)
            if num_faces>0:
                    t0=time()
                    call(['aplay','/home/pi/mrYellow/soundFiles/1.wav'])
                    while ((time()-t0)<5):
                            detectFaces(cap,cv2,face_cascade)
#                            print 'waiting'
#            print 'done'

def node2(q):
	rec=0
	t0=time()
	while True: 
		if not q.empty():
			rec=q.get()
		
		
		if((time()-t0)>2):
                    print time()
                    t0=time()





if __name__ == '__main__':
	q = Queue(maxsize=1)
	p1 = Process(target=face_detection, args=(q,))
	p2 = Process(target=node2, args=(q,))
	p1.start()
	p2.start()

