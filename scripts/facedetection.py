import numpy as np
import cv2
face_cascade = cv2.CascadeClassifier('haarcascade_frontalface_default.xml')
body_cascade = cv2.CascadeClassifier('haarcascade_fullbody.xml')
eye_cascade = cv2.CascadeClassifier('haarcascade_eye.xml')
upper_cascade = cv2.CascadeClassifier('haarcascade_upperbody.xml')


cap = cv2.VideoCapture(0)


while True:
	
	# Capture frame-by-frame
	ret, img = cap.read()


	#img = cv2.imread('Obama.jpg')
	gray = cv2.cvtColor(img, cv2.COLOR_BGR2GRAY)


	print img.dtype
	faces = face_cascade.detectMultiScale(gray, 1.3, 5)
	for (x,y,w,h) in faces:
		cv2.rectangle(img,(x,y),(x+w,y+h),(255,0,0),2)
		#roi_gray = gray[y:y+h, x:x+w]
		#roi_color = img[y:y+h, x:x+w]
	
	cv2.imshow('im',img)
	cv2.waitKey(1)
	#cv2.destroyAllWindows()
