#Importing the libraries
import numpy as np
import pandas as pd
import matplotlib.pyplot as plt
from matplotlib import style

style.use('ggplot')

#Importing the dataset
data = pd.read_csv('Ads_CTR_Optimisation.csv')
n_users,n_ads = data.shape

#Thompson Sampling Algorithm
import random 
random.seed(1)
n_reward_1 = [0] * n_ads
n_reward_0 = [0] * n_ads
ads_selected = []
total_reward = 0
for round in range(0,n_users):
    max_random = 0
    indx = 0
    for ad in range(0,n_ads):
        random_beta = random.betavariate(n_reward_1[ad]+1,n_reward_0[ad]+1)
        if max_random < random_beta:
            max_random = random_beta
            indx = ad
    ads_selected.append(indx)
    if data.values[round,indx]:
        n_reward_1[indx] += 1
    else:
        n_reward_0[indx] += 1
    total_reward += data.values[round,indx]

print('Total reward:',total_reward)

#Visualising the results
plt.hist(ads_selected)
plt.title('Histogram of ads selection')
plt.xlabel('Ads')
plt.ylabel('Number of times each ad selected')
plt.xlim(0,9)
plt.show()