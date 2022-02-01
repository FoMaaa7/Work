import torch  # для нейросети
import random  # библиотека с рандомными функциями
import numpy as np
from PIL import Image, ImageGrab
import numpy as np
from Function import Foto_From_Webcam
import matplotlib.pyplot as plt  # создание графиков и чертежей
import sys
import cv2
from pynput import mouse
from python import on_click
# стопорим рандом

random.seed(0)
np.random.seed(0)
torch.manual_seed(0)
torch.cuda.manual_seed(0)
torch.backends.cudnn.deterministic = True

#way = str("./TEST/cam" + str(k + 1) + ".png")
#way = str("./TEST/cam" + str(k + 1) + ".png")
qntt = 100
#Foto_From_Webcam(200)

arr = np.empty((qntt, 320, 320, 3))
for k in range(qntt):
    img = Image.open(str("./TEST/cam" + str(k + 1) + ".png"))
    resized_img = img.resize((320, 320), Image.ANTIALIAS)
    arr[k, :, :, :] = resized_img
#print(arr.shape)
print(sys.getsizeof(arr[0,1,0,0]))
X_test = torch.from_numpy(arr)
#print(sys.getsizeof(X_test))
X_test = X_test.float()
print(sys.getsizeof(X_test))
X_test = X_test / 255
plt.imshow(X_test[0, :, :,:])

plt.show()
X_test=X_test.resize_(qntt,3,320,320)
#print(sys.getsizeof(X_test))


y_test = np.ones(qntt)
y_test = torch.from_numpy(y_test)
y_test = y_test.int()

n=100
arr1 = np.empty((n, 320, 320, 3))
for k in range(int(n/2)):
    img = Image.open((str("./TRAIN/TRAIN" + str(k + 1) + ".jpg")))
    resized_img = img.resize((320, 320), Image.ANTIALIAS)
    arr1[k*2-1, :, :, :] = resized_img
    img1 = Image.open((str("./TRAIN/TRAIN" + str(k + 1) + ".png")))
    resized_img1 = img1.resize((320, 320), Image.ANTIALIAS)
    arr1[k*2, :, :, :] = resized_img1

#device = torch.device('cuda:0' if torch.cuda.is_available() else 'cpu')
X_train = torch.from_numpy(arr1)



X_train = X_train.float()
X_train = X_train / 255
X_train=X_train.resize_(n,3,320,320)
#print(X_train)
y_train=np.ones(n)
for i in range(int(n/2)):
    y_train[i*2]=0
y_train = torch.from_numpy(y_train)
y_train = y_train.int()
print(y_train)

print(y_train[1])

class LeNet5(torch.nn.Module):
    def __init__(self):
        super(LeNet5, self).__init__()
        '''
        3 6
        6 16
        16 32
        '''
        self.conv1 = torch.nn.Conv2d(in_channels=3, out_channels=5, kernel_size=5, padding=2)
        self.act1 = torch.nn.Tanh()
        self.pool1 = torch.nn.AvgPool2d(kernel_size=8, stride=4)

        self.conv2 = torch.nn.Conv2d(in_channels=5, out_channels=10, kernel_size=5, padding=2)
        self.act2 = torch.nn.Tanh()
        self.pool2 = torch.nn.AvgPool2d(kernel_size=8, stride=4)

        self.conv3=torch.nn.Conv2d(in_channels=10, out_channels=25, kernel_size=5,padding=2)
        self.act3 = torch.nn.Tanh()
        self.pool3 = torch.nn.AvgPool2d(kernel_size=6, stride=3)


        self.fc1 = torch.nn.Linear(5 * 5 * 25, 120) #30 хуже 20 похоже 15 чуть хуже
        self.act3 = torch.nn.Tanh()

        self.fc2 = torch.nn.Linear(120, 84)
        self.act4 = torch.nn.Tanh()

        self.fc3 = torch.nn.Linear(84, 32)
        self.act5=torch.nn.Tanh()

        self.fc4=torch.nn.Linear(32,2)
        self.act6=torch.nn.Tanh()


    def forward(self, x):
        #print(x.shape)
        x = self.conv1(x)
        x = self.act1(x)
        x = self.pool1(x)
        #print(x.shape)
        x = self.conv2(x)
        x = self.act2(x)
        x = self.pool2(x)
        #print(x.shape)
        x = self.conv3(x)
        x = self.act3(x)
        x = self.pool3(x)

        #print(x.shape)
        x = x.view(x.size(0), x.size(1) * x.size(2) * x.size(3))

        x = self.fc1(x)
        x = self.act3(x)
        x = self.fc2(x)
        x = self.act4(x)
        x = self.fc3(x)
        x=self.act5(x)
        x=self.fc4(x)
        x=self.act6(x)
        #print(x.shape)
        return x


lenet5 = LeNet5()
device = torch.device('cuda:0' if torch.cuda.is_available() else 'cpu')
lenet5 = lenet5.to(device)
loss = torch.nn.CrossEntropyLoss()
optimizer = torch.optim.Adam(lenet5.parameters(), lr=1.0e-3) #0.001 самый лучший вариант
batch_size = 10

test_accuracy_history = []
test_loss_history = []

X_test = X_test.to(device)
y_test = y_test.to(device)

for epoch in range(1):
    order = np.random.permutation(len(X_train))
    for start_index in range(0, len(X_train), batch_size):
        optimizer.zero_grad()

        batch_indexes = order[start_index:start_index + batch_size]

        X_batch = X_train[batch_indexes].to(device)
        y_batch = y_train[batch_indexes].to(device)
        y_batch = y_batch.type(torch.LongTensor)
        preds = lenet5.forward(X_batch)
        #print(preds.shape)
        #print(y_batch.shape)
        #print(y_batch.reshape(batch_size,1))
        loss_value = loss(preds, y_batch)
        loss_value.backward()

        optimizer.step()

    test_preds = lenet5.forward(X_train)
    #print(test_preds)
    y_train = y_train.type(torch.LongTensor)

    test_loss_history.append(loss(test_preds, y_train))
    #print(test_loss_history)
    #print(y_train)
    #print(test_preds.argmax(dim=1))
    accuracy = (test_preds.argmax(dim=1) == y_train).float().mean()
    test_accuracy_history.append(accuracy)

    print(accuracy)

lenet5.forward(X_test)
plt.plot(test_loss_history)
plt.show()
print(optimizer)
#print(lenet5.__dict__)
#print()
idfoto = []
cap = cv2.VideoCapture(0)
for i in range(30):
    cap.read()
with mouse.Listener(on_click=on_click) as listener:
    listener.join()