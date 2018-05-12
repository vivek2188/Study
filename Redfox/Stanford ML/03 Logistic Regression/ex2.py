#Logistic Regression

#Initialisation
#Importing the libraries
import numpy as np
import pandas as pd
import matplotlib.pyplot as plt
import math

#Importing th dataset
data = pd.read_csv('ex2data1.txt')
X = data.iloc[:,:2].values
y = data.iloc[:,-1].values

#Part 1 : Plotting
X_true = (y == 1)
X_false = (y == 0)
X_true = X[X_true,:]
X_false = X[X_false,:]
plt.scatter(X_true[:,0],X_true[:,1],marker='+',color='black',label='Admitted')
plt.scatter(X_false[:,0],X_false[:,1],marker='o',color='yellow',label='Not Admitted')
plt.title('Scatter Plot of Training Data')
plt.xlabel('Exam 1 score')
plt.ylabel('Exam 2 score')
plt.legend(loc='upper right')
plt.show()

#Part 2 : Compute Cost and Gradient
m,n = X.shape

#Adding Intercept
X = np.append(arr=np.ones((m,1)).astype(int),values=X,axis=1)    #1 for column

#Initialising fitting parameter
theta = np.zeros(shape=(n+1,1)).astype(int)

# Compute and Display Initial Cost and Gradient
from costfunction import costFunction
cost , grad = costFunction(theta,X,y)

print('Cost at initial theta: ',cost)
print('Expected cost (approx): 0.693')
print('Gradient at initial theta: ',grad)
print('Expected gradients (approx): [-0.100 -12.0092 -11.2628]')

#Compute and display cost and gradient with non-zero theta
test_theta = [[-24],[0.2],[0.2]]
cost , grad = costFunction(test_theta,X,y)

print('Cost at test theta: ',cost)
print('Expected cost (approx): 0.218')
print('Gradient at initial theta: ',grad)
print('Expected gradients (approx): [0.043 2.566 2.647]')

#Part 3 : Optimizing the parameters
from optimize import grad
#Initialise the parameters
alpha = 0.001
iter = 200000
theta , cost = grad(X,y,theta,alpha,iter)

print('Cost at theta found by Grad: ',cost)
print('Theta: ')
print(theta)
h1 = np.matmul(X,theta) >= 0
y1 = np.reshape(y,newshape=(len(y),1))
h1 = (h1!=y1)
cnt = 0   
for x in h1:
    if x == True:
        cnt = cnt +1
print('Accuracy: ',(len(y)-cnt)/len(y) * 100)

#Predict for the student with score 45 and 85 in both the exams
X_pred = [[1 , 45 , 85]]
hypothesis =  np.matmul(X_pred,theta)
hypothesis[0,0] = 1 / (1 + pow(math.e,-hypothesis[0,0]) )
print('For a student with scores 45 and 85, we predict an admission probability is ', hypothesis)