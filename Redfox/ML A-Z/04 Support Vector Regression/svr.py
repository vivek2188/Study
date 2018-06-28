#Importing the libraries
import numpy as np
import pandas as pd
import matplotlib.pyplot as plt

#Importing the dataset
data = pd.read_csv('Position_Salaries.csv')
X = data.iloc[:,1:-1].values
y = data.iloc[:,-1].values
y = np.reshape(y,newshape=(len(y),1))

#Feature Scaling
from sklearn.preprocessing import StandardScaler
scl_x = StandardScaler()
X =  scl_x.fit_transform(X)
scl_y = StandardScaler()
y =  scl_y.fit_transform(y)
'''
    Feature Scaling is done because the SVR class does not apply it on its own.
'''
#Fitting the SVR Model to the dataset
from sklearn.svm import SVR
svr = SVR(kernel='rbf')
svr.fit(X,y)

#Predict the value for the X = 6.5
X_pred = 6.5
X_pred = scl_x.transform(np.array(X_pred))
y_pred = svr.predict(X_pred)
y_pred = np.round(scl_y.inverse_transform(y_pred),2)
print(y_pred)

#Visualising the SVR results
X_grid = np.arange(min(X)-1,max(X)+1,0.1)
X_grid = np.reshape(X_grid,newshape=(len(X_grid),1))
y_grid = svr.predict(X_grid)
y_grid = scl_y.inverse_transform(y_grid)
plt.scatter(scl_x.inverse_transform(X),scl_y.inverse_transform(y),color='red')
plt.plot(scl_x.inverse_transform(X_grid),y_grid,color='blue')
plt.xlabel('Position Level')
plt.ylabel('Salary')
plt.title('Support Vector Regression')
plt.show()