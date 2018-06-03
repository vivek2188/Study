#Importing the libraries
import numpy as np
import pandas as pd
import matplotlib.pyplot as plt
from matplotlib import style

style.use('ggplot')

#Importing the dataset
data = pd.read_csv('Ads_CTR_Optimisation.csv')
n_users,n_ads = data.shape

#UCB Algorithm
from math import sqrt , log
n_selections = [0] * n_ads
sum_reward = [0] * n_ads
ads_selected = []
total_reward = 0
for round in range(0,n_users):
    max_upper_bound = 0
    indx = None
    for ad in range(0,n_ads):
        if n_selections[ad] > 0:
            average_reward = sum_reward[ad] / n_selections[ad]
            delta = sqrt(1.5 * log(round+1) / n_selections[ad])
            upper_bound = average_reward + delta
        else:
            upper_bound = 1e400
        if max_upper_bound < upper_bound:
            max_upper_bound = upper_bound
            indx = ad
    ads_selected.append(indx)
    n_selections[indx] += 1
    sum_reward[indx] += data.values[round,indx]
    total_reward += data.values[round,indx]

print('Total reward:',total_reward)
print('-------------------------------')
print(sum_reward)

#Visualising the results
plt.hist(ads_selected)
plt.title('Histogram of ads selection')
plt.xlabel('Ads')
plt.ylabel('Number of times each ad selected')
plt.xlim(0,9)
plt.show()