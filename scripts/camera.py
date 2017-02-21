import cv2
from picamera.array import PiRGBArray
from picamera import PiCamera
import time
from subprocess import call

face_cascade = cv2.CascadeClassifier('haarcascade_frontalface_default.xml')

camera=PiCamera()
res=(320,240)
camera.resolution=res
camera.framerate=10
raw=PiRGBArray(camera,size=res)

time.sleep(1.0)

for frame in camera.capture_continuous(raw,format="bgr",use_video_port=True):
        
        img=frame.array
	gray = cv2.cvtColor(img, cv2.COLOR_BGR2GRAY)
	faces = face_cascade.detectMultiScale(gray, 1.3, 5)
        print len(faces)
        if len(faces)>0:
            #call(['espeak','hi,there. My name is Mr yellow'])
            call(['aplay','/usr/share/sounds/alsa/Front_Center.wav'])
            time.sleep(0.5)
            #call(['espeak','nice to meet you'])
            call(['aplay','/usr/share/sounds/alsa/Noise.wav'])
            time.sleep(5)
        raw.truncate(0)
