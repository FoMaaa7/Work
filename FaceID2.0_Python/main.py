from header import *
from classNS import LeNet5

qntt = 100
n=51
arr1 = np.empty((255, 320, 320, 3))
for k in range(51):
    for i in range (5):
       img = Image.open((str("./original images/"+str(k)+"("+str(i+1)+")"+".jpg")))
       resized_img = img.resize((320, 320), Image.ANTIALIAS)
       #print(k)
       arr1[k*5+i, :, :, :] = resized_img
#print(arr1.getsizeof())
X_train = torch.from_numpy(arr1)
print(X_train.shape)
X_train = X_train.float()
X_train = X_train / 255
#print(arr1.shape)
plt.imshow(X_train[254, :, :,:])
plt.show()

X_train=X_train.resize_(255,3,320,320)
#print(X_train)
y_train=np.zeros(255)
for i in range(51):
    for k in range(5):
       y_train[i*5+k]=i
y_train = torch.from_numpy(y_train)
y_train = y_train.int()
#y_train=y_train.resize(180,1)
print(y_train.shape)


#lenet5 = LeNet5()
lenet5 = torch.load("./NS/file2")
device = torch.device('cuda:0' if torch.cuda.is_available() else 'cpu')
lenet5 = lenet5.to(device)
loss = torch.nn.CrossEntropyLoss()
optimizer = torch.optim.Adam(lenet5.parameters(), lr=1.0e-3) #0.001 самый лучший вариант
batch_size = 10

test_accuracy_history = []
test_loss_history = []
#print(X_train.shape)
#X_test = X_test.to(device)
#y_test = y_test.to(device)
#print(X_train.getsizeof)
#print(X_train.shape())
for epoch in range(5):
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

#lenet5.forward(X_test)
plt.plot(test_loss_history)
plt.show()
#print(optimizer)
torch.save(lenet5, "./NS/file2")
#print(lenet5.__dict__)
#print()

