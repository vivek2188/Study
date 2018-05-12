import numpy as np
import math
from math import log

def costFunction(theta,X,y):
    y = np.reshape(y,newshape=((len(y)),1))
    m = len(y)
    hypothesis =  np.matmul(X,theta)
    for i in range(m):
        hypothesis[i,0] = 1 / (1 + pow(math.e,-hypothesis[i,0]) )
    lh = np.zeros(hypothesis.shape)
    lh1 = np.zeros(hypothesis.shape)
    for i in range(m):
        lh[i,0] = log(hypothesis[i,0])
        lh1[i,0] = log(1-hypothesis[i,0])
    grad = np.round( np.matmul(np.transpose(X),hypothesis-y) / m , 4)
    grad = np.transpose(grad)
    J = -(np.matmul(np.transpose(y),lh) + np.matmul(np.transpose(1-y) , lh1) )/m
    return J,grad