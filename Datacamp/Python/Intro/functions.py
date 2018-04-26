#Functions
#Print function - print()
#Type conversion function - str() , int() , float() , bool()
#Other functions - type() , round() , len() , max() , min()      round
# Create variables var1 and var2
var1 = [1, 2, 3, 4]
var2 = True
# Print out type of var1
print('var1 is of: ',type(var1))
# Print out length of var1
print('Lenght of var1: ',len(var1))
# Convert var2 to an integer: out2
out2 = int(var2)
print('Out2 is: ',out2)
# sorted() function - reverse = False , key = None
# Create lists first and second
first = [11.25, 18.0, 20.0]
second = [10.75, 9.50]
# Paste together first and second: full
full = first + second
print(first)
# Sort full in descending order: full_sorted
full_sorted = sorted(full,reverse=True)
# Print out full_sorted
print(full_sorted)

#Methods

#String Method
#Strings - upper() lower() capitalize() count() index() len()
# string to experiment with: room
room = "poolhouse"
# Use upper() on room: room_up
room_up = room.upper()
room_down = room.lower()
room_capitalize = room.capitalize()
# Print out room and room_up
print('Strings: ',room,room_up,room_capitalize)
# Print out the number of o's in room
print('O\'s in Poolhouse: ',room.count('o'))

#List methods
# Create list areas
areas = [11.25, 18.0, 20.0, 10.75, 9.50]
# Print out the index of the element 20.0
print('Index of 20.0: ',areas.index(20.0))
# Print out how often 14.5 appears in areas
print('Count of 14.5',areas.count(14.5))
'''
Most list methods will change the list they're called on. Examples are:
    append(), that adds an element to the list it is called on,
    remove(), that removes the first element of a list that matches the input, and
    reverse(), that reverses the order of the elements in the list it is called on.
You'll be working on the list with the area of different parts of the house: areas.
'''
# Use append twice to add poolhouse and garage size
areas.append(24.5)
areas.append(15.45)
# Print out areas
print('New list: ',areas)
# Reverse the orders of the elements in areas
areas.reverse()
# Print out areas
print('Reversed list: ',areas)
