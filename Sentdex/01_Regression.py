#Importing the libraries
import numpy as np
import pandas as pd
import quandl
import matplotlib.pyplot as plt
import math
import pickle

#Preparing the data
df = quandl.get('WIKI/GOOGL')
df = df[['Adj. Open','Adj. High','Adj. Low','Adj. Close','Adj. Volume']]
df['HL_PCT'] = (df['Adj. High']-df['Adj. Close']) / df['Adj. Close'] * 100
df['PCT_change'] = (df['Adj. Open'] - df['Adj. Close']) / df['Adj. Close'] * 100
df = df[['Adj. Close' , 'HL_PCT' , 'PCT_change' , 'Adj. Volume']]

forecast_col = 'Adj. Close'
df.fillna(-99999,inplace=True)

forecast_out = int(math.ceil(0.01 * len(df)))
df['label'] = df[forecast_col].shift(-forecast_out)
df.dropna(inplace=True)

X = df.iloc[:,:-1].values
y = df.iloc[:,-1].values

#Feature Scaling
from sklearn.preprocessing import StandardScaler
scl_x = StandardScaler()
X = scl_x.fit_transform(X)

#Splitting the dataset into training and test set
from sklearn.cross_validation import train_test_split
X_train,X_test,y_train,y_test = train_test_split(X,y,test_size=0.2)

#Fitting the dataset to our Linear Model
'''
from sklearn.linear_model import LinearRegression
lr = LinearRegression(n_jobs=-1)
lr.fit(X_train,y_train)

with open('lr.pickle','wb') as file:
    pickle.dump(lr,file)
'''
pickle_in = open('lr.pickle','rb')
lr = pickle.load(pickle_in)
accuracy = lr.score(X_test,y_test)
y_pred = lr.predict(X_test)
print('Linear Regression: ',accuracy)

from sklearn.svm import SVR
svr = SVR(kernel='linear')
svr.fit(X_train,y_train)
accuracy = svr.score(X_test,y_test)
print('SVM: ',accuracy)
