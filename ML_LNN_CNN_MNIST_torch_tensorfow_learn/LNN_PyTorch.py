import torch
import random
import keras
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
class LNN(torch.nn.Module):
    def __init__(self):
        super(LNN, self).__init__()

        self.ln1=torch.nn.Linear(28*28*1,128)
        self.act1= torch.nn.ReLU()

        self.ln2=torch.nn.Linear(128,64)
        self.act2=torch.nn.ReLU()

        self.ln3=torch.nn.Linear(64,10)
        self.act3=torch.nn.Softmax()

    def forward(self,x):
        x = x.view(x.size(0), x.size(1) * x.size(2) * x.size(3))

        x=self.ln1(x)
        x=self.act1(x)

        x = self.ln2(x)
        x = self.act2(x)

        x = self.ln3(x)
        x = self.act3(x)

        return x

lnn=LNN()
loss=torch.nn.CrossEntropyLoss()
optimizer=torch.optim.Adam(lnn.parameters(),lr=1.0e-3)
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
        preds = lnn.forward(x_batch)
        loss_value = loss(preds, y_batch)
        loss_value.backward()
        optimizer.step()

    test_preds = lnn.forward(x_test)
    y_test = y_test.type(torch.LongTensor)

    test_loss_history.append(loss(test_preds, y_test))

    accuracy = (test_preds.argmax(dim=1) == y_test).float().mean()
    test_accuracy_history.append(accuracy)

    print(accuracy)

lnn.forward(x_test)
plt.plot(test_loss_history)
plt.show()