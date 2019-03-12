import numpy as np
import cv2

img=np.zeros((512,512,3), np.uint8)

cv2.line(img,(0,0),(511,511),(0,0,255),10)

cv2.rectangle(img,(384,0),(510,128),(0,255,0),3)

cv2.circle(img,(63,63), 63, (0,165,256), -1)

cv2.ellipse(img,(256,256),(100,50),0,0,244,255,-1)

pts=np.array([[10,5],[20,30],[70,20],[50,10]], np.int32)

pts=pts.reshape((-1,1,2))

font=cv2.FONT_HERSHEY_SIMPLEX

cv2.putText(img,'Funny',(30,450), font, 5,(144,238,144),5)

winname = 'example'
cv2.namedWindow(winname)
cv2.imshow(winname, img)
cv2.waitKey(0)
cv2.destroyWindow(winname)
