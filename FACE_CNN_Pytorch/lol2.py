import numpy as np
import torch
import cv2
from PIL import Image, ImageGrab
frames = np.empty((30, 480, 640,3))
for k in range(30):
    img = Image.open(str("./TEST/cam" + str(k + 1) + ".png"))
    frames[k,:,:,:] = img
print(frames)
Frames=torch.from_numpy(frames)
Frames=Frames.float()
Frames=Frames/255
print(Frames)
import matplotlib.pyplot as plt #создание графиков и чертежей
plt.imshow(Frames[20,:,:,:]) #выведем нулевую картинку из тензора
plt.show() #показать картинку
#####


