import tensorflow as tf
a=tf.Variable([[1,2],[3,4]], dtype=float)
b=tf.Variable([[1,2],[3,4]],dtype=float)
c=tf.equal(a,b)
print(c)