# Basic statistics function - mean , median , corrcoef , std , sum , sort
# np.round(np.random.normal(mean,std,#samples),2)
# np.column_stack(a,b)

# np_baseball is available
# Import numpy
import numpy as np
# Create np_height from np_baseball
np_height = np_baseball[:,0]
# Print out the mean of np_height
mean_height = np.mean(np_height)
print(mean_height)
# Print out the median of np_height
median_height = np.median(np_height)
print(median_height)
