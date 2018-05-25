#Importing the libraries
import numpy as np
import pandas as pd
import matplotlib.pyplot as plt
from matplotlib import style

style.use('ggplot')

#Importing the dataset
data = pd.read_csv('salary.csv')
X = data.iloc[:,:-1].values
y = data.iloc[:,-1].values.astype(float)

#Adding the intercept column
X_raw = np.array(X)
X = np.append(arr=np.ones((len(X),1)),values=X,axis=1).astype(float)

#Simple Linear Regression
class LinearRegression:
    def __init__(self):
        self.cost_value = []
    
    def fit(self,X,y,alpha=0.0001,n_iters=100000):
        n_samples,n_features = X.shape
        self.theta = np.zeros((1,n_features))
        self.alpha = alpha
        self.n_iters = n_iters
        
        #Theta Optimization
        for iter in range(0,self.n_iters):
            #Hypothesis -  y = m*x + b 
            hypothesis = np.matmul(self.theta,np.transpose(X))
            cost_fun = hypothesis - y
            loss = np.sum(cost_fun**2) / n_samples
            self.cost_value.append(loss)
            gradient = np.matmul(cost_fun,X)
            self.theta = self.theta - (self.alpha/n_samples) * gradient
            
    def predict(self,X):
        return np.matmul(self.theta,np.transpose(X))

lr = LinearRegression()
lr.fit(X,y)

#Visualising the results
plt.scatter(X_raw,y,marker='o',s=35)
plt.plot(X_raw,np.matmul(X,np.transpose(lr.theta)))
plt.xlim(0,12)
plt.xlabel('Year of Experience')
plt.ylabel('Salary')
plt.show()

#Error Function PLot
plt.plot([i for i in range(lr.n_iters)],lr.cost_value)
plt.xlabel('Number of iterations')
plt.ylabel('Cost Value')
plt.title('Error Function Plot')
plt.show()