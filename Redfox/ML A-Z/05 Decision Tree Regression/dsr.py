#Importing the libraries
import numpy as np
import pandas as pd
import matplotlib.pyplot as plt

#Importing the dataset
data = pd.read_csv('Position_Salaries.csv')
X = data.iloc[:,1:-1].values
y = data.iloc[:,-1].values
y = np.reshape(y,newshape=(len(y),1))

#Fitting the Decision Tree Model to the dataset
from sklearn.tree import DecisionTreeRegressor
dsr = DecisionTreeRegressor(random_state=0)
dsr.fit(X,y)

#Predict the result for 6.5
y_pred = dsr.predict(np.array(6.5))
print(y_pred)

#Visualising the Decision Tree results
X_grid = np.arange(min(X),max(X),0.01)
X_grid = np.reshape(X_grid,newshape=(len(X_grid),1))
y_grid = dsr.predict(X_grid)
plt.scatter(X,y,color='red')
plt.plot(X_grid,y_grid,color='blue')
plt.title('Decision Tree Regression Model')
plt.xlabel('Position Label')
plt.ylabel('Salary')
plt.show()

'''
    Information Entropy!
    Splits the dataset into numerous groups.
'''