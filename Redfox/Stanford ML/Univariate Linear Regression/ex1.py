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
print("Plotting Data")
dataset = pd.read_csv("profit.csv")
X = dataset.iloc[:,0].values
y = dataset.iloc[:,1].values
m, = y.shape 
X = np.reshape(X,newshape=(m,1))
y = np.reshape(y,newshape=(m,1))
print("Training Size: ",m)
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
print('Expected cost value (approx) 54.24');
