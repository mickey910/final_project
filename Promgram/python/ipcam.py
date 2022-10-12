# -*- coding: utf-8 -*-
"""
Spyder Editor

This is a temporary script file.
"""
import cv2
import numpy as n

cap = cv2.VideoCapture("http://admin:admin@192.168.1.116:8081/video")#kitty

while cap.isOpened():
    ret, frame = cap.read()
    
    cv2.imshow('frame', frame)
    
    if cv2.waitKey(1) & 0xFF == ord('q'):  
        break 
    if cv2.waitKey(1)==27:
        break
   
cap.release()
cv2.destroyAllWindows()
