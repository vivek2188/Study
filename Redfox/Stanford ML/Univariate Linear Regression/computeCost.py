import numpy as np
def computeCost(X,y,theta):
    theta_t = np.transpose(theta)
    hypothesis = np.matmul(X,theta)
    squared_hy = (hypothesis-y)**2 
    J = np.mean(squared_hy)/2
    return(np.round(J,4))