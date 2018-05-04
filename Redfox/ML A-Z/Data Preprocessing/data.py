#Importing the libraries
import numpy as np
import pandas as pd
import matplotlib.pyplot as plt 

#Importing the dataset
dataset = pd.read_csv("Data.csv")
X = dataset.iloc[:,:-1].values
y = dataset.iloc[:,-1].values

#Taking care of Missing Data
from sklearn.preprocessing import Imputer
'''
strategy tells which methodology to use to resolve the missing data - mean , median , most_frequent
axis if 0 then impute about columns else if 1 then impute about rows.
'''
imputer = Imputer(missing_values="NaN",strategy="mean",axis=0)
imputer = imputer.fit(X[:,1:])
X[:,1:] = imputer.transform(X[:,1:])

#Encoding Categorical Data
'''
Categorical Encoding is needed to convert the strings into integer values. It makes it helpful to carry your the calculations.
'''
from sklearn.preprocessing import LabelEncoder , OneHotEncoder

labelencoder_X = LabelEncoder()
X[:,0] = labelencoder_X.fit_transform(X[:,0])

#Dummy Encoding
#First perform label encoding and then one hot encoding
onehotencoder = OneHotEncoder(categorical_features = [0])
X = onehotencoder.fit_transform(X).toarray()
print(X.shape)      # (10,5)

lbl_y = LabelEncoder()
y = lbl_y.fit_transform(y)

#Splitting the dataset into Training and Test set
from sklearn.cross_validation import train_test_split
X_train , X_test ,y_train , y_test = train_test_split(X,y,test_size = 0.2,random_state = 0)

#Feature Scaling
'''
1st Method : Standardisation
        x = (x-mean)/std
2nd Method : Normalisation
        x = (x-min)/(max-min)
'''
from sklearn.preprocessing import StandardScaler
sc_x = StandardScaler()
X_train[:,3:] = sc_x.fit_transform(X_train[:,3:])
X_test[:,3:] = sc_x.transform(X_test[:,3:])
print("Training Set:")
print(X_train)
print("Test Set:")
print(X_test)