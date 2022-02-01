import torch
import random
import keras
import tensorflow as tf
import matplotlib.pyplot as plt
import numpy as np

random.seed(0)
np.random.seed(0)
torch.manual_seed(0)
torch.cuda.manual_seed(0)
torch.backends.cudnn.deterministic = True

mnist= keras.datasets.mnist
(x_train1, y_train1),(x_test1,y_test1)=mnist.load_data()
x_train=torch.Tensor(x_train1)
y_train=torch.Tensor(y_train1)
x_test=torch.Tensor(x_test1)
y_test=torch.Tensor(y_test1)

x_train=x_train/255
x_test=x_test/255

#plt.imshow(x_train[3, :, :])
#plt.show()

x_train=x_train.resize_(60000,1,28,28)
x_test=x_test.resize_(10000,1,28,28)
#out=((in+2*padding-k)/stride)+1
class CNN(torch.nn.Module):
    def __init__(self):
        super(CNN,self).__init__()

        self.conv1=torch.nn.Conv2d(in_channels=1, out_channels=5, padding='valid',kernel_size=(3,3))
        self.act1 = torch.nn.Tanh()
        self.pool1 = torch.nn.AvgPool2d(kernel_size=2)

        self.conv2 = torch.nn.Conv2d(in_channels=5, out_channels=10, padding='valid', kernel_size=(3, 3))
        self.act2 = torch.nn.Tanh()
        self.pool2 = torch.nn.AvgPool2d(kernel_size=2)

        self.conv3 = torch.nn.Conv2d(in_channels=10, out_channels=25, padding='valid', kernel_size=(3, 3))
        self.act3 = torch.nn.Tanh()
        self.pool3 = torch.nn.AvgPool2d(kernel_size=2)

        self.flatten = torch.nn.Linear(1 * 1 * 25, 64)

        self.drop=torch.nn.Dropout(0.25)

        self.fc1 = torch.nn.Linear(64, 32)
        self.act4 = torch.nn.Tanh()

        self.fc2 = torch.nn.Linear(32, 10)
        self.act5 = torch.nn.Softmax()

    def forward(self, x):

        x = self.conv1(x)
        x = self.act1(x)
        x = self.pool1(x)

        x = self.conv2(x)
        x = self.act2(x)
        x = self.pool2(x)

        x = self.conv3(x)
        x = self.act3(x)
        x = self.pool3(x)

        x = x.view(x.size(0), x.size(1) * x.size(2) * x.size(3))

        x = self.flatten(x)

        x=self.drop(x)

        x = self.fc1(x)
        x = self.act4(x)

        x = self.fc2(x)
        x = self.act5(x)

        return x

cnn=CNN()
loss=torch.nn.CrossEntropyLoss()
optimizer=torch.optim.Adam(cnn.parameters(),lr=1.0e-3)
batch_size = 100
test_accuracy_history = []
test_loss_history = []

for epoch in range(5):
    order = np.random.permutation(len(x_train))
    for start_index in range(0, len(x_train), batch_size):
        optimizer.zero_grad()

        batch_indexes = order[start_index:start_index + batch_size]

        x_batch = x_train[batch_indexes]
        y_batch = y_train[batch_indexes]
        y_batch = y_batch.type(torch.LongTensor)
        preds = cnn.forward(x_batch)
        loss_value = loss(preds, y_batch)
        loss_value.backward()
        optimizer.step()

    test_preds = cnn.forward(x_test)
    y_test = y_test.type(torch.LongTensor)

    test_loss_history.append(loss(test_preds, y_test))

    accuracy = (test_preds.argmax(dim=1) == y_test).float().mean()
    test_accuracy_history.append(accuracy)

    print(accuracy)

cnn.forward(x_test)
plt.plot(test_loss_history)
plt.show()