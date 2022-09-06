
我的第一個 real-time (即時) AI 程式, 數字辨識, 使用 MNIST 資料庫. (提供檔案下載)

https://www.youtube.com/watch?v=CsJH1wvgJ28

--------------------

檔案可以在此下載:  https://drive.google.com/drive/folders/1o7u9yEnRE4FmPDbUwwGV2bu0lX_lDHeI?usp=sharing

檔案名字: AI_01_Real_Time_Number_Inference
註: 在 related_codes 檔案夾內, 有一個測試 camera 的程式, 請先確認找得到 camera. 

--------------------

要執行這個程式, 先開啟 Anaconda, 選擇左側的 Environments, 然後依序安裝 Tensorflow, Keras, opencv. 步驟如下:  https://www.youtube.com/watch?v=30ebXTxUTz0&index=6&list=PLYgGtiVoYLPcLDi-vW02DnSqmD6e6m6lL

--------------------

還需要一個camera, 因為我使用桌機, 所以要外接. 有 USB 聯接線的攝影機, 應該就可以了. 我是用 Logitech WebCam C310.

--------------------

為何安裝 opencv, 程式裡卻要 import cv2?

From: https://pypi.org/project/opencv-python/
Q: Why the package and import are different (opencv-python vs. cv2)?

A: It's easier for users to understand opencv-python than cv2 and it makes it easier to find the package with search engines. cv2 (old interface in old OpenCV versions was named as cv) is the name that OpenCV developers chose when they created the binding generators. This is kept as the import name to be consistent with different kind of tutorials around the internet. Changing the import name or behaviour would be also confusing to experienced users who are accustomed to the import cv2.
