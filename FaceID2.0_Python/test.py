from header import *
from main import *
lenet5 = torch.load("./NS/file2")
idfoto = []
cap = cv2.VideoCapture(0)
for i in range(30):
        cap.read()
for i in range(1):
        ret, frame = cap.read()
        k = str("./test.jpg")
        idfoto.append(k)
        cv2.imwrite(idfoto[i], frame)
        cap.release()
arr=np.empty((1,320,320,3))
img = Image.open((str("./test.jpg")))
resized_img = img.resize((320, 320), Image.ANTIALIAS)
arr[0, :, :, :] = resized_img
X_test= torch.from_numpy(arr)
X_test = X_test.float()
X_test = X_test / 255
#print(arr1.shape)
plt.imshow(X_test[0, :, :,:])
plt.show()

X_train=X_test.resize_(1,3,320,320)
test_preds = lenet5.forward(X_train)
print(test_preds.argmax(dim=1))
