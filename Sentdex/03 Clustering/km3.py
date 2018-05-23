import numpy as np
import pandas as pd
import matplotlib.pyplot as plt
from matplotlib import style

style.use('ggplot')

X = np.array([[1,2],[1.5,1.8],[5,8],[8,8],[1,0.6],[9,11]])

#plt.scatter(X[:,0],X[:,1],s=150)
#plt.show()

colors = 10*['red','blue','green','k','magenta']

class kmeans:
    def __init__(self,k=2,tol=0.0001,max_iter=300):
        self.k = k
        self.max_iter = max_iter
        self.tol = tol
    
    def fit(self,data):
        self.centroids = {}
        
        for i in range(self.k):
            self.centroids[i] = data[i]
        
        for i in range(self.max_iter):
            self.classifications = {}
            
            for j in range(self.k):
                self.classifications[j] = []
            for featureset in data:
                distances = [np.linalg.norm(featureset-self.centroids[centroid]) for centroid in self.centroids]
                classification = distances.index(min(distances))
                self.classifications[classification].append(featureset)
            prev_centroids = dict(self.centroids)
            
            for classification in self.classifications:
                self.centroids[classification] = np.average(self.classifications[classification],axis=0)
            optimized = True
            
            for i in range(self.k):
                original_centroids = prev_centroids[i]
                current_centroids = self.centroids[i]
                if np.sum((current_centroids-original_centroids)/original_centroids*100.0) > self.tol:
                    optimized = False
            if optimized:
                print('Optimized')
                break
    
    def predict(self,data):
        distances = [np.linalg.norm(data-self.centroids[centroid]) for centroid in self.centroids]
        classification = distances.index(min(distances))
        #print(distances)
        return classification
    
clf = kmeans()
clf.fit(X)
print(clf.centroids)

for centroid in clf.centroids:
    plt.scatter(clf.centroids[centroid][0],clf.centroids[centroid][1],marker='o',color='k',s=150,linewidth=5)
for classification in clf.classifications:
    color = colors[classification]
    for featureset in clf.classifications[classification]:
        plt.scatter(featureset[0],featureset[1],marker='x',s=150,linewidth=5,color=color)
unknowns = np.array([[1,3],[0,3],[8,9],[5,4],[6,4]])
for unknown in unknowns:
    classification = clf.predict(unknown)
    plt.scatter(unknown[0],unknown[1],marker='*',s=150,linewidth=5,color=colors[classification])
plt.show()

