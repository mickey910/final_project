#!/usr/bin/env python
# coding: utf-8

# In[1]:


import cv2
import matplotlib
import numpy

cap = cv2.VideoCapture(0)
width = cap.get(cv2.CAP_PROP_FRAME_WIDTH)
height = cap.get(cv2.CAP_PROP_FRAME_HEIGHT)
print("Image Size: %d x %d" % (width, height))

cap.set(cv2.CAP_PROP_FRAME_WIDTH, 720)
cap.set(cv2.CAP_PROP_FRAME_HEIGHT, 720)


while(True):
    ret, img = cap.read()
    cv2.imshow('frame',img)
    if cv2.waitKey(1) & 0xFF == ord('q'):
        cv2.imwrite('output.jpg', img)
        break

        cap.release()
cv2.destroyAllWindows()

