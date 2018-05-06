import numpy as np
from sklearn.preprocessing import StandardScaler
def featureNormalize(X):
    X_norm = X 
    mean = np.mean(X,axis=0)    #Mean along Column
    sigma = np.std(X,axis=0)   #Standard Deviation along Column
    X_norm = (X-mean)/sigma
    '''
    Both does the same thing
    scl_x = StandardScaler()
    X_norm = scl_x.fit_transform(X)
    '''
    return X_norm , mean , sigma