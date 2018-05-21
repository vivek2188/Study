#Importing the libraries
import numpy as np 
import pandas as pd
import matplotlib.pyplot as plt

#Importing the dataset
data = pd.read_csv('mall.csv')
X = data.iloc[:,[3,4]].values

#Using the elbow method to find the optimal number of clusters
from sklearn.cluster import KMeans
wcss = []
for i in range(1,11):
    kmeans = KMeans(n_clusters=i,init='k-means++',max_iter=300,n_init=10,random_state=0)
    kmeans.fit(X)
    wcss.append(kmeans.inertia_)
plt.plot(range(1,11),wcss)
plt.title('The Elbow Method')
plt.xlabel('Number of clusters')
plt.ylabel('WCSS')
plt.show()

#Applying K-means to mall dataset
km = KMeans(n_clusters=5,init='k-means++',max_iter=300,n_init=10,random_state=0)
y_kmeans = km.fit_predict(X)
#print(y_kmeans)

#Visualising the clusters
plt.scatter(X[y_kmeans==0,0],X[y_kmeans==0,1],color='red',s=100,label='Careful')
plt.scatter(X[y_kmeans==1,0],X[y_kmeans==1,1],color='blue',s=100,label='Standard')
plt.scatter(X[y_kmeans==2,0],X[y_kmeans==2,1],color='green',s=100,label='Target')
plt.scatter(X[y_kmeans==3,0],X[y_kmeans==3,1],color='yellow',s=100,label='Careless')
plt.scatter(X[y_kmeans==4,0],X[y_kmeans==4,1],color='cyan',s=100, label='Sensible')
plt.scatter(km.cluster_centers_[:,0],km.cluster_centers_[:,1],color='k',s=100,label='Centroids')
plt.title('Cluster of Clusters')
plt.xlabel('Annual Income (k$)')
plt.ylabel('Spending SCore (1-100)')
plt.legend()
plt.show()