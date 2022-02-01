import tensorflow.compat.v1 as tf
import numpy as np
#подключение версии 1, тк быстродействие выше
#tf.compat.v1.disable_v2_behavior()
#обязательно создать граф и сессию
graph=tf.Graph()
session=tf.InteractiveSession(graph=graph)
# x-заполнитель, создается на лету
# W- var random; h- var 0
x=tf.placeholder(shape=[1,10],dtype=tf.float32, name='x')
W=tf.Variable(tf.random_uniform(shape=[10,5], minval=-0.1,maxval=0.1, dtype=tf.float32), name='W')
b=tf.Variable(tf.zeros(shape=[5],dtype=tf.float32), name='b')
h=tf.nn.sigmoid(tf.matmul(x,W)+b)
#запускаем инициализацию переменных
tf.global_variables_initializer().run()
# запускаем сессию
h_ev=session.run(h, feed_dict={x: np.random.rand (1,10)})
print(h_ev)
session.close()
#############
session1=tf.InteractiveSession(graph=graph)
x=tf.constant(value=[[0.1,0.2,0.3,0.4,0.5,0.1,0.2,0.3,0.4,0.5]],dtype=tf.float32, name='x')
h1=tf.nn.sigmoid(tf.matmul(x,W)+b)
tf.global_variables_initializer().run()
h_eval=session1.run(h1)
session1.close()
print(h_eval)
#####
session2=tf.InteractiveSession(graph=graph)
a=tf.Variable(np.array([[1,2],[3,4]]),name='a')
c=tf.Variable(np.array([[1,2],[3,4]]),name='a')
g=a*c
tf.global_variables_initializer().run()
l=session2.run(g)
print(l)
session2.close()