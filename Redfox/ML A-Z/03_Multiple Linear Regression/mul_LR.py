#Importing the libraries
import numpy as np
import pandas as pd
import matplotlib.pyplot as plt

#Importing the dataset
dataset = pd.read_csv("50_Startups.csv")
X = dataset.iloc[:,:-1].values
y = dataset.iloc[:,-1].values

#Categorical Labelling
from sklearn.preprocessing import LabelEncoder,OneHotEncoder
lbl_x = LabelEncoder()
X[:,3] = lbl_x.fit_transform(X[:,3])
onehotencoder = OneHotEncoder(categorical_features=[3])
X = onehotencoder.fit_transform(X).toarray()

#Avoiding the dummy variable trap
X = X[:,1:]

#Splitting into Training and Test Set
from sklearn.cross_validation import train_test_split
X_train,X_test,y_train,y_test = train_test_split(X,y,test_size=0.20,random_state=0)

#Fitting Multiple Linear Regression Model to the training set
from sklearn.linear_model import LinearRegression
regressor = LinearRegression()
regressor.fit(X_train,y_train)

#Predicting the Test Set results
y_pred = regressor.predict(X_test)

#Building the Optimal Model using Backward Elimination
import statsmodels.formula.api as sm
X = np.append(arr=np.ones((50,1)).astype(int),values=X,axis=1) # 1 for column
X_opt = X[:,[0,1,2,3,4,5]]
regressor_ols = sm.OLS(endog=y,exog=X_opt).fit()    #Ordinary Least Squares
regressor_ols.summary()
X_opt = X[:,[0,1,3,4,5]]
regressor_ols = sm.OLS(endog=y,exog=X_opt).fit()    
regressor_ols.summary()
X_opt = X[:,[0,3,4,5]]
regressor_ols = sm.OLS(endog=y,exog=X_opt).fit()
regressor_ols.summary()
X_opt = X[:,[0,3,5]]
regressor_ols = sm.OLS(endog=y,exog=X_opt).fit() 
regressor_ols.summary()
X_opt = X[:,[0,3]]
regressor_ols = sm.OLS(endog=y,exog=X_opt).fit()  
regressor_ols.summary()

y_pred = regressor.predict(X_opt)