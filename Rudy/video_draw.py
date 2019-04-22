import numpy as np
import cv2
cap = cv2.VideoCapture(0)
while(True):
    ret, frame = cap.read()
    gray = cv2.cvtColor(frame, 0)
    cv2.line(gray,(450,200),(450,470),(255,0,0),5)
    cv2.line(gray,(540,200),(540,470),(255,0,0),5)
    cv2.line(gray,(360,290),(630,290),(255,0,0),5)
    cv2.line(gray,(360,380),(630,380),(255,0,0),5)
    cv2.rectangle(gray,(360,200),(630,470),(255,0,0),5)
    cv2.imshow('frame',gray)
    if cv2.waitKey(1) & 0xFF == ord('q'):
        break
cap.release()
cv2.destroyAllWindows()
