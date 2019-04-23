#!/usr/bin/env python

'''
Camshift tracker
================

This is a demo that shows mean-shift based tracking
You select a color objects such as your face and it tracks it.
This reads from video camera (0 by default, or the camera number the user enters)

http://www.robinhewitt.'F'/research/track/camshift.html

Usage:
------
    camshift.py [<video source>]

    To initialize tracking, select the object with mouse

Keys:
-----
    ESC   - exit
    b     - toggle back-projected probability visualization
'''

# Python 2/3 'X'patibility
from __future__ import print_function
import serial
import sys
PY3 = sys.version_info[0] == 3

if PY3:
    xrange = range

import numpy as np
import cv2 as cv

# local module
import video
from video import presets



class SendData():
    def __init__(self, portx = "COM7", bps = 9600, timex = 0):
        self.ser = serial.Serial(portx, bps, timeout=timex)
        
        Arm7Numpy = np.float32([[-45, 200.0], [-175.0, 195.0], [-145, 290]])
        CameraNumpy = np.float32([[0, 200], [300, 200], [200, 0]])
        M = cv.getAffineTransform(CameraNumpy, Arm7Numpy)
        MMatrx = np.matrix(M)

        self.Mend = np.vstack((MMatrx, np.matrix('0 0 1')))






    def Move(self, x, y, z = 70):

        string = '%d;%d;1' % (x, y)
        MXY = np.matrix(string)
        HandXY = self.Mend*MXY

        print(HandXY)
        xx = HandXY[0, 0]
        yy = HandXY[1, 0]
        data = 'F' + str(xx) + '/' + str(yy) + '/' + str(z) + 'L'
        print(data)
        self.ser.write(data.encode("utf-8"))


    def read(self):
        return self.ser.read()
        # self.ser.read() == b'1'


SendAPP = SendData(portx = "COM7", bps = 9600, timex = 0)





drawing = False # 鼠标左键是不是按下
mode = False # True,激活绘制正方形. False 激活绘制曲线；使用m键切换
ix,iy = -1,-1
img = 0 
keypt = np.zeros((4,2));
keyptp = np.float32([[0,0],[300,0],[300,300],[0,300]])




# 以下为进行相机坐标与真实左边的对应




# mouse callback function
reselect = True
perspflag = False
j=-1;
def draw_circle(event,x,y,flags,param):
    global ix,iy,drawing,mode,j,reselect,keypt,perspflag
 
    if event == cv.EVENT_LBUTTONDOWN:
        j+=1
        if j==4:
            j=0
            reselect=False
            keypt = np.zeros((4,2));
        if j==0:
            reselect = True
        drawing = True
        ix,iy = x,y
        keypt[j] =x,y
    elif event == cv.EVENT_MOUSEMOVE:
        if drawing == True:
            if mode == True:
                cv.rectangle(img,(ix,iy),(x,y),(0,255,0),-1)
            else:
                cv.circle(img,(x,y),5,(0,0,255),-1)
 
    elif event == cv.EVENT_LBUTTONUP:
        if j ==3:
            perspflag=True
        drawing = False
        if mode == True:
            cv.rectangle(img,(ix,iy),(x,y),(0,255,0),-1)
        else:
            cv.circle(img,(x,y),5,(0,0,255),-1)

def sendToHand(event,x,y,flags,param):
    global ix,iy,drawing,mode,j,reselect,keypt,perspflag
 
    if event == cv.EVENT_LBUTTONDOWN:
        print(x,y)

        # xx = int(xx)
        # yy = int(yy)

        SendAPP.Move(x = x, y = y)

    # elif event == cv.EVENT_MOUSEMOVE:
    #     print("mouse move")
        

cv.namedWindow('image')
cap=cv.VideoCapture(1)
ret ,img = cap.read()
cv.setMouseCallback('image',draw_circle)
while(1):
    if reselect == True:
        for i in range(4):
            cv.circle(img,(int(keypt[i][0]),int(keypt[i][1])),5,(0,0,255),-1)
    if perspflag == True:
        M = cv.getPerspectiveTransform(np.float32(keypt),keyptp)
        dst = cv.warpPerspective(img,M,(300,300))
        cv.imshow('haha',dst)
        #reselect == True
    cv.imshow('image',img)
    k = cv.waitKey(1) & 0xFF
    if k == ord('m'):
        mode = not mode
    elif k == 27:
        break
    ret ,img = cap.read()


cap.release() 
cv.destroyAllWindows()


# 指哪打哪 

cv.namedWindow('sendToHand')
cap=cv.VideoCapture(1)
ret ,img = cap.read()
cv.setMouseCallback('sendToHand',sendToHand)
while(1):

    M = cv.getPerspectiveTransform(np.float32(keypt),keyptp)
    dst = cv.warpPerspective(img,M,(300,300))
    cv.imshow('sendToHand',dst)
        #reselect == True
    k = cv.waitKey(1) & 0xFF
    if k == ord('m'):
        mode = not mode
    elif k == 27:
        break
    ret ,img = cap.read()


cap.release() 
cv.destroyAllWindows()















