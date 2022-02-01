import torch  # для нейросети
import random  # библиотека с рандомными функциями
import numpy as np
from PIL import Image, ImageGrab
import numpy as np
#from Function import Foto_From_Webcam
import matplotlib.pyplot as plt  # создание графиков и чертежей
import sys
import cv2

random.seed(0)
np.random.seed(0)
torch.manual_seed(0)
torch.cuda.manual_seed(0)
torch.backends.cudnn.deterministic = True

