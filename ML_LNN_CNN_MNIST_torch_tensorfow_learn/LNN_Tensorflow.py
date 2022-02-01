import tensorflow as tf
import matplotlib.pyplot as plt

tf.random.set_seed(0)

mnist= tf.keras.datasets.mnist
(x_train, y_train),(x_test,y_test)=mnist.load_data()
print(x_train.shape)
print(y_train)

#plt.imshow(x_train[1, :, :])
#plt.show()

x_train=x_train/255
x_test=x_test/255

x_train = x_train.reshape((60000, 28, 28, 1))
x_test = x_test.reshape((10000, 28, 28, 1))

LNN=tf.keras.models.Sequential([
 tf.keras.layers.Flatten(input_shape=(28,28)), #в линию 28*28=7..
 tf.keras.layers.Dense(128, activation='relu'),
 tf.keras.layers.Dense(64,activation='relu'),
 tf.keras.layers.Dense(10,activation='softmax')
])

LNN.compile(
    optimizer='Adam',
    loss='sparse_categorical_crossentropy',
    metrics=['accuracy'])

LNN_history=LNN.fit(x_train,y_train, epochs=5, batch_size=600)

plt.plot(LNN_history.history['loss'])
plt.show()

test_loss, test_acc=LNN.evaluate(x_test,y_test)
print(test_acc)