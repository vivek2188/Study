import numpy as np
from random import shuffle

def softmax_loss_naive(W, X, y, reg):
  """
  Softmax loss function, naive implementation (with loops)

  Inputs have dimension D, there are C classes, and we operate on minibatches
  of N examples.

  Inputs:
  - W: A numpy array of shape (D, C) containing weights.
  - X: A numpy array of shape (N, D) containing a minibatch of data.
  - y: A numpy array of shape (N,) containing training labels; y[i] = c means
    that X[i] has label c, where 0 <= c < C.
  - reg: (float) regularization strength

  Returns a tuple of:
  - loss as single float
  - gradient with respect to weights W; an array of same shape as W
  """
  # Initialize the loss and gradient to zero.
  loss = 0.0
  dW = np.zeros_like(W)

  #############################################################################
  # TODO: Compute the softmax loss and its gradient using explicit loops.     #
  # Store the loss in loss and the gradient in dW. If you are not careful     #
  # here, it is easy to run into numeric instability. Don't forget the        #
  # regularization!                                                           #
  #############################################################################
  c = W.shape[1]
  num_train, n_features = X.shape
  #Compute Softmax
  Z = np.dot(X,W).T
  Z = np.exp(Z)
  Z = Z / np.sum(Z,axis=0).reshape((1,num_train))
  #Without Regularisation
  dZ = np.zeros_like(Z)
  for indx in range(num_train):
    yi = y[indx]
    loss += - np.log(Z[yi,indx])
    dZ[:,indx] += Z[:,indx]
    dZ[yi,indx] -= 1
  dW = np.dot(dZ,X).T
  loss = loss / num_train
  dW /= num_train
  #Regularisation
  loss += 0.5 * reg * np.sum(np.square(W))
  dW += reg * W
  #############################################################################
  #                          END OF YOUR CODE                                 #
  #############################################################################

  return loss, dW


def softmax_loss_vectorized(W, X, y, reg):
  """
  Softmax loss function, vectorized version.

  Inputs and outputs are the same as softmax_loss_naive.
  """
  # Initialize the loss and gradient to zero.
  loss = 0.0
  dW = np.zeros_like(W)

  #############################################################################
  # TODO: Compute the softmax loss and its gradient using no explicit loops.  #
  # Store the loss in loss and the gradient in dW. If you are not careful     #
  # here, it is easy to run into numeric instability. Don't forget the        #
  # regularization!                                                           #
  #############################################################################
  c = W.shape[1]
  num_train, n_features = X.shape
  #Compute Softmax
  Z = np.dot(X,W).T
  Z = np.exp(Z)
  Z = Z / np.sum(Z,axis=0).reshape((1,num_train))
  #Without Regularisation
  dZ = np.zeros_like(Z)
  #Compute Loss and dZ
  loss =  - np.sum(np.log(Z[y,np.arange(num_train)]))
  dZ += Z
  dZ[y,np.arange(num_train)] -= 1
  dW = np.dot(dZ,X).T
  loss = loss / num_train
  dW /= num_train
  #Regularisation
  loss += 0.5 * reg * np.sum(np.square(W))
  dW += reg * W
  #############################################################################
  #                          END OF YOUR CODE                                 #
  #############################################################################

  return loss, dW

