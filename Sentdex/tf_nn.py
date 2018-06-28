import tensorflow as tf
import numpy as np
from tensorflow.examples.tutorials.mnist import input_data

mnist = input_data.read_data_sets("/tmp/data",one_hot=True) #one_hot -> Output is vector of 10 elements (0 or 1)
#Neurons in hidden layers
h1 = 500
h2 = 500
h3 = 500

n_class = 10      # Number of classes 0-9
batch_size = 128

X = tf.placeholder('float',[None,784])
y = tf.placeholder('float',[None,10])

def neural_network_model(data):
    hlayer1 = {'w1':tf.Variable(tf.random_normal([784,h1])),
               'b1':tf.Variable(tf.random_normal([1,h1]))}
    hlayer2 = {'w2':tf.Variable(tf.random_normal([h1,h2])),
               'b2':tf.Variable(tf.random_normal([1,h2]))}
    hlayer3 = {'w3':tf.Variable(tf.random_normal([h2,h3])),
               'b3':tf.Variable(tf.random_normal([1,h3]))}
    output = {'w4':tf.Variable(tf.random_normal([h3,n_class])),
                'b4':tf.Variable(tf.random_normal([1,n_class]))}

    l1 = tf.add(tf.matmul(data,hlayer1['w1']),hlayer1['b1'])
    a1 = tf.nn.relu(l1)
    l2 = tf.add(tf.matmul(a1,hlayer2['w2']),hlayer2['b2'])
    a2 = tf.nn.relu(l2)
    l3 = tf.add(tf.matmul(a2,hlayer3['w3']),hlayer3['b3'])
    a3 = tf.nn.relu(l3)
    l4 = tf.add(tf.matmul(a3,output['w4']),output['b4'])

    return l4

def train_nn(X):
    prediction = neural_network_model(X)
    cost = tf.reduce_mean(tf.nn.softmax_cross_entropy_with_logits(logits=prediction,labels=y))
    optimizer = tf.train.AdamOptimizer(learning_rate=0.001).minimize(cost)

    n_epoch = 20

    with tf.Session() as sess:
        sess.run(tf.initialize_all_variables())

        for epoch in range(n_epoch):
            epoch_loss = 0
            for i in range(int(mnist.train.num_examples/batch_size)):
                epoch_X, epoch_y = mnist.train.next_batch(batch_size)
                _, c = sess.run([optimizer,cost],feed_dict={X:epoch_X,y:epoch_y})
                epoch_loss += c
            print('Epoch '+str(epoch)+' Done!')
            print('Epoch Loss: '+str(epoch_loss))
            print('-------------------')

        correct = tf.equal(tf.argmax(prediction,1),tf.argmax(y,1))
        accuracy = tf.reduce_mean(tf.cast(correct,'float'))
        print('Accuracy: '+str(accuracy.eval({X:mnist.test.images,y:mnist.test.labels})))

train_nn(X)
