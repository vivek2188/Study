import numpy as np
import pandas as pd
import matplotlib.pyplot as plt
from matplotlib import style
from sklearn.cluster import KMeans
from sklearn import preprocessing , cross_validation

style.use('ggplot')

data = pd.read_excel('titanic.xls')
#print(data.head())
#print('----------------------------------------------------------')
data.drop(['body','name'],axis=1,inplace=True)
data.convert_objects(convert_numeric=True)
data.fillna(0,inplace=True)
print('Dataset Size: ',data.values.shape)
#print(data.head())

def categorisation(data):
    columns = data.columns.values
    
    #I have two replace all the strings in a given column with a specific integers.
    for column in columns:
        # converter will hold an integer to every different string within that column.
        converter = {}
        def convert_to_int(val):
            return converter[val]
        if data[column].dtype!=np.int64 and data[column].dtype!=np.float64:
            unique_elements = set(data[column].values)
            x = 0
            for unique in unique_elements:
                if unique not in converter:
                    converter[unique] = x
                    x = x + 1
            data[column] =  np.array([convert_to_int(x) for x in data[column]])
    return data

data = categorisation(data)
#print('----------------------------------------------------------')
#print(data.head())

y = data['survived'].values
data.drop(['survived','boat','sex'],1,inplace=True)
X = data.values.astype(float)
X = preprocessing.scale(X)
# 2 Clusters mainly for survived and not survived
clf = KMeans(n_clusters=2)
clf.fit(X)

correct = 0
for i in range(len(X)):
    predict_me = np.array(X[i].astype(float))
    predict_me = predict_me.reshape(-1,len(predict_me))
    predict = clf.predict(predict_me)
    if predict[0] == y[i]:
        correct += 1

print('Accuracy: ',correct/len(X)*100)