import numpy as np

def gradientDescent(X,y,theta,alpha,iterations):
    m,m1 = y.shape
    temp = np.ones(theta.shape) - 1
    for iter in range(iterations):
        hypothesis = np.matmul(X,theta) - y
        for j in range(2):
            X1 = X[:,j]
            X1 = np.reshape(X1,newshape=(m,1))
            h1 = hypothesis * X1
            mn = np.mean(h1)
            temp[j,0] = theta[j,0] - alpha * mn
        theta = temp
    theta = np.round(theta,4)
    return theta