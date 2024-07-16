'''
import numpy as np
from sklearn.cluster import KMeans
import pandas as pd


# ASP algorithm
def adaptive_swarm_particles(data, n_particles, max_iter):
    particles = []
    for i in range(n_particles):
        particle = {
            'position': np.random.uniform(np.min(data, axis=0), np.max(data, axis=0), size=data.shape[1]),
            'velocity': np.zeros(data.shape[1]),
            'best_position': None,
            'best_score': float('inf')
        }
        particles.append(particle)

    for i in range(max_iter):
        for particle in particles:
            # update velocity and position
            particle['velocity'] = 0.5 * particle['velocity'] + 0.5 * (particle['best_position'] - particle['position']) + np.random.rand(data.shape[1])
            particle['position'] += particle['velocity']

            # update best position and score
            score = kmeans_score(particle['position'], data)
            if score < particle['best_score']:
                particle['best_position'] = particle['position']
                particle['best_score'] = score

    # return the particle with the best score
    return min(particles, key=lambda x: x['best_score'])

# k-means algorithm
def kmeans(data, n_clusters):
    kmeans = KMeans(n_clusters=n_clusters)
    kmeans.fit(data)
    return kmeans.cluster_centers_

# function to calculate the score of a particle using k-means
def kmeans_score(particle, data):
    centers = kmeans(data, len(particle))
    distances = np.linalg.norm(centers - particle, axis=1)
    return np.sum(distances)

# main function
def customer_segmentation(data, n_particles, max_iter):
    # use ASP to find the best set of cluster centers
    best_particle = adaptive_swarm_particles(data, n_particles, max_iter)
    cluster_centers = best_particle['best_position']
    kmeans = KMeans(n_clusters=len(cluster_centers))
    kmeans.cluster_centers_ = cluster_centers
    kmeans.fit(data)
    return kmeans.labels_

#test the function with your own dataset
data = np.random.rand(100, 2)
labels = customer_segmentation(data, n_particles=10, max_iter=100)
print(labels)
'''

import numpy as np
from sklearn.cluster import MeanShift 
from sklearn.datasets import make_blobs



X, _ = make_blobs(n_samples=500, n_features=2, centers=[[4,4],[-2,-1],[2,-3],[1,1]], cluster_std=0.9)



import matplotlib.pyplot as plt 
plt.scatter(X[:,0],X[:,1],marker='o') 
plt.show()



ms = MeanShift()
ms.fit(X)
labels = ms.labels_
cluster_centers = ms.cluster_centers_


print(labels) 
print(cluster_centers)



n_clusters_ = len(np.unique(labels))

colors = 10*['r.','g.','b.','c.','k.','y.','m.']

for i in range(len(X)):
    plt.plot(X[i][0], X[i][1], colors[labels[i]], markersize = 10)

plt.scatter(cluster_centers[:,0],cluster_centers[:,1],marker="x",s=150,linewidths=5,zorder=10)

plt.show()