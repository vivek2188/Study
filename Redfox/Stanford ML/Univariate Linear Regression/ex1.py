import numpy as np
import pandas as pd
import matplotlib.pyplot as plt

# Part 1 - Warmup Exercise
from warmup import warmup
print("Running WarmUp Exercise:")
print(" 5x5 Identity Matrix: ")
warmup()

# Part 2 - Plotting the Training Data
from plotdata import plotdata
print("\nPlotting Data")
dataset = pd.read_csv("profit.csv")
X = dataset.iloc[:,0].values
y = dataset.iloc[:,1].values
m, = y.shape 
X = np.reshape(X,newshape=(m,1))
y = np.reshape(y,newshape=(m,1))
X1 = X
print("Training Size: ",m,'\n')
plotdata(X,y)

#Part 3 - Cost Function and Gradient Descent
from computeCost import computeCost
X = np.append(arr=np.ones((m,1)).astype(int),values=X,axis=1) #1 for Column and 0 for Row
theta = np.array([[0],[0]])
#Variables for Gradient Descent
iterations = 1500
alpha = 0.01

print("Testing the cost function")
#Compute and Display Initial Cost
J = computeCost(X,y,theta)
print("For theta = 0,0 : Cost Computed = ",J)
print('Expected cost value (approx) 32.07')

#Further testing of the Cost Function
J = computeCost(X, y, [[-1],[2]]);
print('With theta = -1,2 : Cost computed = ', J);
print('Expected cost value (approx) 54.24\n');

print("Reading Gradient Descent")
#Run Gradient Descent 
from gradientDescent import gradientDescent
theta = gradientDescent(X,y,theta,alpha,iterations)
print("Theta found by gradient descent: ",theta[0,0],theta[1,0])
print("Expected theta values (approx): -3.6303 1.1664")

# Predict values for population sizes of 35,000 and 70,000
pred1 = np.array([1,35000])
pred1 = np.reshape(pred1,newshape=(1,2))
y_pred1 = np.matmul(pred1,theta)
print("For Population of 35000, Profit is ",y_pred1[0,0])

pred2 = np.array([1,70000])
pred2 = np.reshape(pred2,newshape=(1,2))
y_pred2 = np.matmul(pred2,theta)
print("For Population of 70000, Profit is ",y_pred2[0,0])

#Part 4: Visualising the results
y_pred = np.matmul(X,theta)
plt.scatter(X1,y,color='red',s=15,marker='x')
plt.plot(X1,y_pred,color="blue")
plt.xlabel('Population of City in 10,000s')     
plt.ylabel('Profit in $10,000s')
plt.title('Scatter Plot of Training data')
plt.show()