# Import cars data
import pandas as pd
cars = pd.read_csv('cars.csv', index_col = 0)

# Print out country column as Pandas Series
print(cars['country'])
print(type(cars['country']))

# Print out country column as Pandas DataFrame
print(cars[['country']])
print(type(cars['country']))

# Print out DataFrame with country and drives_right columns
x = cars[['country','drives_right']]
print(x)