#Importing the libraries
import numpy as np
import time

#Arrays 
a = np.random.rand(50000)     # 50000 Elements
b = np.random.rand(50000)     # 50000 Elements

#Vectorised Implementation
start = time.time()
vect_out = np.dot(a,b)
end = time.time()
print("Vectorised Output " + str(vect_out))
print("     Time Taken: " + str((end-start)*1000) + str("ms"))

#For loop Implementation
loop_out = 0
start = time.time()
for i in range(50000):
    loop_out += a[i] * b[i]
end = time.time()
print("Loop Output " + str(loop_out))
print("     Time Taken: " + str((end-start)*1000) + str("ms"))

#Time taken by the "For Loop" Implementation is about 11 times more than the "Vectorised Implementation".