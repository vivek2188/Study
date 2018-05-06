import numpy as np
from numpy.linalg import pinv 

def normalEqn(X,y):
    X_trans = np.transpose(X)
    X1 = np.matmul(X_trans,X)
    Y = np.matmul(X_trans,y)
    X = np.matmul(pinv(X1),Y)
    return X