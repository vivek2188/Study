'''
Number of Instances: 699 (as of 15 July 1992)
Number of Attributes: 10 plus the class attribute

Attribute Information: (class attribute has been moved to last column)

   #  Attribute                     Domain
   -- -----------------------------------------
   1. Sample code number            id number
   2. Clump Thickness               1 - 10
   3. Uniformity of Cell Size       1 - 10
   4. Uniformity of Cell Shape      1 - 10
   5. Marginal Adhesion             1 - 10
   6. Single Epithelial Cell Size   1 - 10
   7. Bare Nuclei                   1 - 10
   8. Bland Chromatin               1 - 10
   9. Normal Nucleoli               1 - 10
  10. Mitoses                       1 - 10
  11. Class:                        (2 for benign, 4 for malignant)

Missing attribute values: 16
   There are 16 instances in Groups 1 to 6 that contain a single missing
   (i.e., unavailable) attribute value, now denoted by "?".

Class distribution:
   Benign: 458 (65.5%)
   Malignant: 241 (34.5%)
'''

#Importing the libraries
import numpy as np
import pandas as pd
import matplotlib.pyplot as plt

#Importing the dataset
data = pd.read_csv('breast-cancer-wisconsin.data.txt')
data.replace('?','NaN',inplace=True)
X = data.iloc[:,1:].values
y = data.iloc[:,-1].values

#Resolving the issue of missing data in the dataset
from sklearn.preprocessing import Imputer
imputer = Imputer(missing_values='NaN',strategy='mean',axis=0)
imputer = imputer.fit(X[:,:6])
X[:,:6] = imputer.transform(X[:,:6])
X = X.astype(float)

#Splitting the dataset into Training and Test dataset
from sklearn.cross_validation import train_test_split
X_train,X_test,y_train,y_test = train_test_split(X,y,test_size=0.2)

#Fitting the dataset to the KNN Model - Libraries Version
from sklearn.neighbors import KNeighborsClassifier
knn = KNeighborsClassifier()
knn.fit(X_train,y_train)

#Predicting the results
y_pred = knn.predict(X_test)
accuracy = knn.score(X_test,y_test)
print('Accuracy (KNN scikit-learn):',accuracy)

#Own Function
#K Nearest Neighbors
class kNearestNeighbors:

    def __init__(self):
        self.n_neighbors = 3
    def fit(self,X_train,y_train,n_neighbors):
        self.n_neighbors = n_neighbors
        self.X = X_train
        self.y = y_train
    def predict(self,X_test):
        y_pred = np.zeros((len(X_test),))
        for i in range(len(X_test)):
            x_pred = X_test[i]
            Xn = self.X[:self.n_neighbors,:]
            yn = self.y[:self.n_neighbors]
            for index,x in enumerate(self.X[self.n_neighbors:,:]):
                dist = np.linalg.norm(x_pred-x)
                d = [np.linalg.norm(x_pred-x1) for x1 in Xn]
                max_val = np.max(d)
                if(dist <= max_val):
                    d = list(d)
                    indx = d.index(max_val)
                    Xn[indx] = x
                    yn[indx] = y[index]
                    d[indx] = dist
            class_2 = np.count_nonzero(yn==2)
            class_4 = np.count_nonzero(yn==4)
            if(class_2 > class_4):
                y_pred[i] = 2
            else:
                y_pred[i] = 4
        return y_pred

knn_own = kNearestNeighbors()
knn_own.fit(X_train,y_train,n_neighbors=5)
y_pred = knn_own.predict(X_test)
accuracy = 1 - len(y_test[y_pred!=y_test])/ len(y_test)
print('Accuracy of the own Algorithm: ',accuracy)
