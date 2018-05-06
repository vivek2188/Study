import numpy as np
from computeCost import *

def gradientDescentMulti(X,y,theta,alpha,iterations):
    m,n = X.shape
    X_trans = np.transpose(X)
    J_history = []
    for iters in range(iterations):
        hypothesis = np.matmul(X,theta) - y
        h1 = np.matmul(X_trans,hypothesis)
        temp = theta - (alpha / m) *  h1
        theta = temp
        J = computeCost(X,y,theta)
        J_history.append([J,iters])
    J_history = np.array(J_history)
    return theta , J_history