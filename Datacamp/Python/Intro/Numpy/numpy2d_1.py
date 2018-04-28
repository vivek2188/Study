#2-d numpy array
# let an array be numpy_2d . Then numpy_2d.shape returns its dimension in form of tuple.
# numpy_2d[a,b] and numpy_2d[a][b] gives the same element

# Create baseball, a list of lists
baseball = [[180, 78.4],
            [215, 102.7],
            [210, 98.5],
            [188, 75.2]]
# Import numpy
import numpy as np
# Create a 2D numpy array from baseball: np_baseball
np_baseball = np.array(baseball)
# Print out the type of np_baseball
print(type(np_baseball))
# Print out the shape of np_baseball
print(np_baseball.shape)
