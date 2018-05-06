import numpy as np

def computeCost(X,y,theta):
    m = len(y)
    hypothesis = np.matmul(X,theta) - y
    J = np.matmul(np.transpose(hypothesis),hypothesis)
    J = J / (2*m)
    return J[0,0]