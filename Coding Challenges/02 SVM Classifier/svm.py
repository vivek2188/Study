#Importing the libraries
import numpy as np
import pandas as pd
import matplotlib.pyplot as plt
from sklearn.datasets.samples_generator import make_blobs
from matplotlib import style

style.use('ggplot')
colors = ['c','r','b','k','y','g']
#Points 
X,y = make_blobs(n_samples=30,n_features=2,centers=2,cluster_std=1,random_state=0)
X_neg = X[y==0]
X_pos = X[y==1]
#X = np.array([[1,7],[2,8],[3,8],[5,1],[6,-1],[7,3]])
#y = np.array([0,0,0,1,1,1])

#SVM Class
class SupportVectorClassifier:
    def __init__(self,visualisation=True):
        self.visualisation = visualisation
    
    def fit(self,X,y,alpha=0.001,n_iters=10000):
        n_samples,n_features = X.shape
        #Data Preparation
        self.data = np.append(arr=X,values=np.reshape(y,newshape=(len(y),1)),axis=1)
        
        #Required Parameters Initialisation
        self.alpha = alpha
        self.n_iters = n_iters
        self.w = np.zeros(shape=(1,n_features)) 
        self.b = 0
        '''
            For predicting the value for some vector u , following conditions are identified : 
            '+' samples :  w.u + b >= 0
            '-' samples :  w.u + b < 0
            
            For '+' samples : w.x_pos + b >= 1    ---(1)
            For '-' samples : w.x_neg + b <= -1   ---(2)
            
            Combining the two equations : 
                y * (w.x + b) >= 1
                y * (w.x + b) - 1 >= 0
                
            Mis-classification : y * (w.x + b) - 1 < 0
            
            w = w - alpha * gradient
            gradient w.r.t w(k) : 2 * lambda * w(k)                  - For Correct Classified Sample
                                  2 * lambda * w(k) - y[i] * x[i,k]  - For Mis-classification Sample i     
        '''
        #Optimization 
        for i in range(0,self.n_iters):
            #Lets call w.x as hypo
            hypo = np.array([np.dot(self.w,x) for x in X])
            #Updated value of b
            self.b = - (np.max(hypo[y==0,:]) + np.min(hypo[y==1,:])) / 2
            
            f = hypo + self.b
            y_r = [1 if yi==1 else -1 for yi in y]
            f = np.array([y_r[i] * f1 for i,f1 in enumerate(f)]) - 1
            
            gradient = np.zeros(self.w.shape)
            for k in range(n_features):
                for l in range(n_samples):
                    if 0 >= 2-f[l]:          #Correctly Classified Class
                        gradient[0,k] += 2 * self.w[0,k] / self.n_iters
                    else:
                        gradient[0,k] += 2 * self.w[0,k] / self.n_iters - y_r[l] * X[l,k]
            self.w = self.w - alpha * gradient
        self.classifications = np.array([np.dot(self.w,x) for x in X]) + self.b 
        self.classifications = np.array([1 if w>=0 else 0 for w in self.classifications])
        #Printing out the results
        print(self.w,self.b)
        print('--------------------------------------------------------------------')
        print(self.classifications)
        print(y)
        if self.visualisation:
            self.visualise(X,y)
    
    def visualise(self,X,y):
        X_neg = X[y==0]
        X_pos = X[y==1]
        plt.scatter(X_neg[:,0],X_neg[:,1],marker='*',color='r',linewidth=5)
        plt.scatter(X_pos[:,0],X_pos[:,1],marker='*',color='c',linewidth=5)
        
        def hyperplane(x,w,b,v):
            return (-w[0,0]*x-b+v)/w[0,1]
        datarange = np.min(X[:,0])*0.9 , np.max(X[:,0])*1.1
        hyp_x_min = datarange[0]
        hyp_x_max = datarange[1]
        psv1 = hyperplane(hyp_x_min,self.w,self.b,1)
        psv2 = hyperplane(hyp_x_max,self.w,self.b,1)
        plt.plot([hyp_x_min,hyp_x_max],[psv1,psv2],'k')

        nsv1 = hyperplane(hyp_x_min,self.w,self.b,-1)
        nsv2 = hyperplane(hyp_x_max,self.w,self.b,-1)
        plt.plot([hyp_x_min,hyp_x_max],[nsv1,nsv2],'g')

        dsv1 = hyperplane(hyp_x_min,self.w,self.b,0)
        dsv2 = hyperplane(hyp_x_max,self.w,self.b,0)
        plt.plot([hyp_x_min,hyp_x_max],[dsv1,dsv2],'y--')
        plt.show()
    
    def predict(self,data):
        classifications = np.array([np.dot(self.w,x) for x in data]) + self.b 
        classifications = np.array([1 if w>=0 else 0 for w in classifications])
        return classifications
        
svc = SupportVectorClassifier()
svc.fit(X,y)