# Import cars data
import pandas as pd
cars = pd.read_csv('cars.csv', index_col = 0)

# Convert code to a one-liner
'''
dr = cars['drives_right']
sel = cars[dr]
'''
sel = cars[cars.loc[:,"drives_right"]]

# Print sel
print(sel)