img = cv2.imread("contour_2.png",1)

img_gary=cv2.cvtColor(img,cv2.COLOR_BGR2GRAY)

ret, thresh = cv2.threshold(img_gary,127,255,0)

image ,contours ,hier =cv2.findContours(thresh, cv2.RETR_TREE,cv2.CHAIN_APPROX_SIMPLE)

img = cv2.drawContours(img ,contours, -1 , (0,0,255), 3)
