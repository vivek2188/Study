#Polynomial Regression

#Importing the libraries
import numpy as np
import pandas as pd
import matplotlib.pyplot as plt

#Importing the dataset
dataset = pd.read_csv('Position_Salaries.csv')
X = dataset.iloc[:,1:2].values
y = dataset.iloc[:,2:3].values

#Fitting Linear Regression to the dataset
from sklearn.linear_model import LinearRegression
lr = LinearRegression()
lr.fit(X,y)

#Fitting Polynomial Regression to the dataset
from sklearn.preprocessing import PolynomialFeatures
polyreg = PolynomialFeatures(degree=4)
X_poly = polyreg.fit_transform(X)
print('Transformed Matrix:')
print(np.round(X_poly,2))
plr = LinearRegression()
plr.fit(X_poly,y)

#Visualising the Linear Regression results
plt.scatter(X,y,color='green',marker='+')
plt.plot(X,lr.predict(X),color='blue')
plt.xlabel('Position Level')
plt.ylabel('Salary')
plt.title('Truth or Bluff(Linear Regression)')
plt.show()

#Visualising the Polynomial Regression results
X_grid = np.arange(min(X),max(X),0.1)
X_grid = X_grid.reshape((len(X_grid),1))
plt.scatter(X,y,color='green',marker='+')
plt.plot(X_grid,plr.predict(polyreg.fit_transform(X_grid)),color='blue')
plt.xlabel('Position Level')
plt.ylabel('Salary')
plt.title('Truth or Bluff(Polynomial Regression)')
plt.show()

#Predicting a new result with Linear Regression
y = lr.predict(6.5)
print('Linear Regression: ',np.round(y,2))

#Predicting a new result with Polynomial Regression
y = plr.predict(polyreg.fit_transform(6.5))
print('Polynomial Regression: ',np.round(y,2))