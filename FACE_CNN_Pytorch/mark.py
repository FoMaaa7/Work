import torch  # для нейросети
import random  # библиотека с рандомными функциями
import numpy as np
from PIL import Image, ImageGrab
import numpy as np
import cv2

# стопорим рандом
random.seed(0)
np.random.seed(0)
torch.manual_seed(0)
torch.cuda.manual_seed(0)
torch.backends.cudnn.deterministic = True


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


#way = str("./TEST/cam" + str(k + 1) + ".png")
#way = str("./TEST/cam" + str(k + 1) + ".png")
qntt = 30
# Foto_From_Webcam(qntt)

arr = np.empty((qntt, 240, 320, 3))
for k in range(qntt):
    img = Image.open(str("./TEST/cam" + str(k + 1) + ".png"))
    resized_img = img.resize((320, 240), Image.ANTIALIAS)
    arr[k, :, :, :] = resized_img

X_test = torch.from_numpy(arr)
X_test = X_test.float()
X_test = X_test / 255

y_test = np.ones(qntt)
y_test = torch.from_numpy(y_test)
y_test = y_test.int()

arr1 = np.empty((50, 240, 320, 3))
for k in range(50):
    img = Image.open((str("./TRAIN/original images/TRAIN(" + str(k + 1) + ").jpg")))
    resized_img = img.resize((320, 240), Image.ANTIALIAS)
    arr1[k, :, :, :] = resized_img

device = torch.device('cuda:0' if torch.cuda.is_available() else 'cpu')
X_train = torch.from_numpy(arr1)

X_train = X_train.float()
X_train = X_train / 255
X_train = X_train  # .to(device)
print(X_train)
import matplotlib.pyplot as plt  # создание графиков и чертежей

plt.imshow(X_test[0, :, :, :])  # выведем нулевую картинку из тензора
plt.show()  # показать картинку
