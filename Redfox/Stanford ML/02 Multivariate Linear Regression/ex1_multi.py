#Importing the libraries
import numpy as np
import pandas as pd
import matplotlib.pyplot as plt

#Importing the dataset
dataset = pd.read_csv("ex1_data2.csv")
X = dataset.iloc[:,:-1].values
y = dataset.iloc[:,-1].values
m = len(y)
y = np.reshape(y,newshape=(m,1))
print(X.shape,y.shape)

# Part 1 : Feature Normalisation
# Print out some data points
from featureNormalize import featureNormalize
print('First 10 examples from dataset: ')
print(dataset.iloc[:10,:].values)
print('Normalising Features.')
X,mean,sigma = featureNormalize(X)

#Adding Intercept Column
X = np.append(arr=np.ones((m,1)).astype(int),values=X,axis=1) # 1 for Column
print('After Normalizing: First 5 examples from dataset')
print(X[:5,:])

# Part 2: Gradient Descent
from gradientDescentMulti import *
print('Running Gradient Descent.')
alpha = 0.03
iterations = 1000
m1,n = X.shape 
theta = np.zeros((n,1)).astype(int)
theta , J_history = gradientDescentMulti(X,y,theta,alpha,iterations)

#Plotting the Convergence Graph
plt.plot(J_history[:,0],J_history[:,1],color="blue")
plt.title('Convergence Graph')
plt.xlabel('Number of iterations')
plt.ylabel('Cost function')
plt.show()

# Display Gradient Descent Result
print('Theta computed from Gradient Descent: ',theta)

#Estimate the price of a 1650 sq-ft , 3 br house 
X_pred = [[1650,3]]
X_pred = (X_pred-mean)/sigma
X_pred = np.append(arr=[[1]],values=X_pred,axis=1)
y_pred = np.matmul(X_pred,theta)
print('Predicted price of a 1650 sq-ft, 3 br house: ',np.round(y_pred[0,0],2))

'''
    After varying the values of alpha and iterations , the following conclusion is drawn :
        (0.001,40000) ~ (0.003,20000) ~ (0.01,5000) ~ (0.03,1000)
'''
# Solving with Normal Equation
print('Running Normal Equation')
from normalEqn import *
theta = normalEqn(X,y)
print('Theta computed from Normal Equation(using Gradient Descent): ',theta)

#Estimate the price of a 1650 sq-ft , 3 br house 
y_pred = np.matmul(X_pred,theta)
print('Predicted price of a 1650 sq-ft, 3 br house(using Normal Equation): ',np.round(y_pred[0,0],2))