#Importing the libraries
import numpy as np
import pandas as pd
import matplotlib.pyplot as plt

#Importing the dataset 
data = pd.read_csv('Position_Salaries.csv')
X = data.iloc[:,1:-1].values
y = data.iloc[:,-1].values
y = np.reshape(y,newshape=(len(y),1))

#Fitting the Random Forest Regression to the dataset
from sklearn.ensemble import RandomForestRegressor
rfr = RandomForestRegressor(n_estimators=300,random_state=0)
rfr.fit(X,y)

#Predict the result for X = 6.5
y_pred = rfr.predict(np.array(6.5))
print(y_pred)

#Visualising the Random Forest Results
X_grid = np.arange(min(X),max(X),0.01)
X_grid = np.reshape(X_grid,newshape=(len(X_grid),1))
y_grid = rfr.predict(X_grid)
plt.scatter(X,y,color='red')
plt.plot(X_grid,y_grid,color='blue')
plt.title('Random Forest Regression')
plt.xlabel('Position Level')
plt.ylabel('Salary')
plt.show()

'''
    Ensemble Learning.
'''