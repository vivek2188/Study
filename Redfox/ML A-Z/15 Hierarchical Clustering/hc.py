#Importing the libraries
import numpy as np
import pandas as pd
import matplotlib.pyplot as plt

#Importing the dataset
data = pd.read_csv('mall.csv')
X = data.iloc[:,[3,4]].values

#Using dendrograms to find the optimal number of clusters
import scipy.cluster.hierarchy as sch
dendrogram = sch.dendrogram(sch.linkage(X,method='ward'))
plt.title('Dendrogram')
plt.xlabel('Customer')
plt.ylabel('Euclidean Distances')
plt.show()

#Fitting Hierarchical Clustering to our dataset
from sklearn.cluster import AgglomerativeClustering
hc = AgglomerativeClustering(n_clusters=5,affinity='euclidean',linkage='ward')
y_hc = hc.fit_predict(X)

#Visualising the clusters
plt.scatter(X[y_hc==0,0],X[y_hc==0,1],color='red',s=100,label='Careful')
plt.scatter(X[y_hc==1,0],X[y_hc==1,1],color='blue',s=100,label='Standard')
plt.scatter(X[y_hc==2,0],X[y_hc==2,1],color='green',s=100,label='Target')
plt.scatter(X[y_hc==3,0],X[y_hc==3,1],color='yellow',s=100,label='Careless')
plt.scatter(X[y_hc==4,0],X[y_hc==4,1],color='cyan',s=100, label='Sensible')
plt.title('Cluster of Clusters')
plt.xlabel('Annual Income (k$)')
plt.ylabel('Spending Score (1-100)')
plt.legend()
plt.show()