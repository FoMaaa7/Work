import cv2

def Foto_From_Webcam(quantity):
    idfoto = []
    cap = cv2.VideoCapture(0)
    for i in range(30):
        cap.read()
    for i in range(quantity):
        ret, frame = cap.read()
        k = str("./TEST/cam" + str(i + 1) + ".png")
        idfoto.append(k)
        cv2.imwrite(idfoto[i], frame)
    cap.release()