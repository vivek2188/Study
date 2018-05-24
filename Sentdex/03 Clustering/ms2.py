import numpy as np
import pandas as pd
import matplotlib.pyplot as plt
from matplotlib import style
from sklearn.cluster import MeanShift
from sklearn import preprocessing , cross_validation

style.use('ggplot')

data = pd.read_excel('titanic.xls')
original_df = pd.DataFrame.copy(data)
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

clf = MeanShift()
clf.fit(X)

labels = clf.labels_
cluster_centers = clf.cluster_centers_
n_clusters = len(np.unique(labels))

original_df['cluster group'] = np.nan

for i in range(len(X)):
    original_df['cluster group'].iloc[i] = labels[i]

survival_rates = {}
for i in range(n_clusters):
    temp_df = original_df[original_df['cluster group']==float(i)]
    survival_cluster = temp_df[temp_df['survived']==1]
    survival_rate = len(survival_cluster)/len(temp_df)
    survival_rates[i] = survival_rate
print(survival_rates)
print(original_df[original_df['cluster group']==0].describe())