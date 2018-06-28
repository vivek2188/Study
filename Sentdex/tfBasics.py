import numpy as np
import tensorflow as tf

x1 = tf.constant(5)
x2 = tf.constant(6)

result = tf.multiply(x1,x2)
print(result)      #Session not started

#sess = tf.Session()
#print(sess.run(result))
#sess.close()

with tf.Session() as sess:    #Session started
    output = sess.run(result)
print(result)       #Session ended
print(output)       #Session ended but no longer a Tensor object.
