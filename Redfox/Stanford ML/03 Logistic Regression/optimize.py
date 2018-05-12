import numpy as np
from costfunction import costFunction
import math

def grad(X,y,theta,alpha,iter):
    y = np.reshape(y,newshape=((len(y)),1))
    m,n = X.shape
    for j in range(iter):
        hypothesis =  np.matmul(X,theta)
        for i in range(m):
            hypothesis[i,0] = 1 / (1 + pow(math.e,-hypothesis[i,0]) )
        grad =  np.matmul(np.transpose(X),hypothesis-y) * (alpha/m)  
        temp = theta - grad
        theta = temp 
    J_history,grad = costFunction(theta,X,y)
    return theta , J_history