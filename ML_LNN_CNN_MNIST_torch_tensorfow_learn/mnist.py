import tensorflow as tf
import matplotlib.pyplot as plt
tf.random.set_seed(0)
mnist= tf.keras.datasets.mnist
(x_train, y_train),(x_test,y_test)=mnist.load_data()
print(x_train.shape)
print(y_train)
plt.imshow(x_train[1, :, :])
plt.show()
x_train=x_train/255
x_test=x_test/255
model=tf.keras.models.Sequential([
 tf.keras.layers.Flatten(input_shape=(28,28)), #в линию 28*28=700
 tf.keras.layers.Dense(128, activation='relu'),
 tf.keras.layers.Dense(10,activation='softmax')
])
x_train = x_train.reshape((60000, 28, 28, 1))
x_test = x_test.reshape((10000, 28, 28, 1))
model1=tf.keras.models.Sequential([
    tf.keras.layers.Conv2D(32, kernel_size=(3,3), padding='valid', activation='tanh', input_shape=(28,28,1)),
    tf.keras.layers.AvgPool2D(pool_size= (2,2)),
    tf.keras.layers.Conv2D(64,kernel_size=(3,3), padding='valid', activation='tanh'),
    tf.keras.layers.AvgPool2D(pool_size= (2,2)),
    tf.keras.layers.Conv2D(128,kernel_size=(3,3), padding='valid', activation='tanh'),
    tf.keras.layers.Flatten(),
    tf.keras.layers.Dropout(0.25),
    tf.keras.layers.Dense(64,activation='tanh'),
    tf.keras.layers.Dense(32,activation='tanh'),
    tf.keras.layers.Dense(10,activation='softmax')
])
model1.compile(optimizer='adam',
              loss='sparse_categorical_crossentropy',
              metrics=['accuracy'])
model_history = model1.fit(x_train,y_train,epochs=5, batch_size=600)
plt.figure()
plt.subplot(211)
plt.plot(model_history.history['accuracy'])
plt.subplot(212)
plt.plot(model_history.history['loss'])
plt.show()
test_loss, test_acc = model1.evaluate(x_test, y_test)
print('Test accuracy:', test_acc)