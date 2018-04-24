#Lists
print('List')
fam = [2,3,4,5]
print(fam)
print('Type of fam: ',type(fam))
#List of lists
    # Age of member
print('List of lists')
fam2 = [['lily',6],
        ['Monica',35],
        ['Tim',36]]
print(fam2)
    #Compound List
print('Compound list')
a = 'my'
b = 'name'
c = 'is'
fam3 = [a,b,c,'christine']
print(fam3)
    #Area of the house : COMPOUND LIST
print('House')
hall = 11.25
kit = 18.0
liv = 20.0
bed = 10.75
bath = 9.50
areas = [hall , kit , liv , bed , bath]
print(areas)
    #Multiple type within the same list
print('Multitype var in list')
mulareas = ['hallway', hall,'kitchen', kit, "living room", liv,'bedroom', bed, 'bathroom', bath]
print(mulareas)
    #Subsetting the list
print('Second Element: ',mulareas[1])       #Indexing from left start with 0
print('Last element: ',mulareas[-1])        #Indexing from right start with -1
print('Area of living room: ',mulareas[5])
    #Performing calculations
eat_sleep_area = mulareas[3] + mulareas[7]
print('Eat Sleep Area: ',eat_sleep_area)
    #Slicing lists
downstairs = mulareas[0:6]          #mulareas[:6]
upstairs = mulareas[6:]             #mulareas[-4:-1]
print('Downstairs: ',downstairs)
print('Upstairs: ',upstairs)
    #Subsettting list of lists
x = [["a", "b", "c"],
     ["d", "e", "f"],
     ["g", "h", "i"]]
print(x[2][0])
print(x[1][0:2])
print('Age of Tim: ',fam2[-1][1])

#LIST MANIPULATION   Adding , removing , copying elements in lists etc.
    #Adding
areas1 = mulareas + ['pool',24.85]      # or can use append function
mulareas = mulareas + ['pool',24.85]
del(mulareas[10]);del(mulareas[10])
print(areas1)
print(mulareas)
    #List working
# Create list areas
areas2 = [11.25, 18.0, 20.0, 10.75, 9.50]
# Create areas_copy
areas_copy = areas2        #Both pointing to same container to avoid this situation
areas_copy2 = list(areas2) # Now both points to separate container, areas_copy2 contain the container with the values same as areas2 But no longer areas2 get influenced by areas_copy2
# Change areas_copy
areas_copy[0] = 5.0
areas_copy2[0] = 15.0
# Print areas
print(areas2)

'''
    Created the list , learnt about various operations which can be down using it .
'''
