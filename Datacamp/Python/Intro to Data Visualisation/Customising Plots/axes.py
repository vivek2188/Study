'''
In calling plt.axes([xlo, ylo, width, height]), a set of axes is created and made active with lower corner at coordinates (xlo, ylo) of the specified width and height. Note that these coordinates can be passed to plt.axes() in the form of a list or a tuple.
The coordinates and lengths are values between 0 and 1 representing lengths relative to the dimensions of the figure. After issuing a plt.axes() command, plots generated are put in that set of axes.

Create a set of plot axes with lower corner xlo and ylo of 0.05 and 0.05, width of 0.425, and height of 0.9 (in units relative to the figure dimension).
Note: Remember to pass these coordinates to plt.axes() in the form of a list: [xlo, ylo, width, height].
Plot the percentage of degrees awarded to women in Physical Sciences in blue in the active axes just created.
Create a set of plot axes with lower corner xlo and ylo of 0.525 and 0.05, width of 0.425, and height of 0.9 (in units relative to the figure dimension).
Plot the percentage of degrees awarded to women in Computer Science in red in the active axes just created.
'''
# Create plot axes for the first line plot
plt.axes([0.05,0.05,0.425,0.9])

# Plot in blue the % of degrees awarded to women in the Physical Sciences
plt.plot(year,physical_sciences, color='blue')

# Create plot axes for the second line plot
plt.axes([0.625,0.05,0.425,0.9])

# Plot in red the % of degrees awarded to women in Computer Science
plt.plot(year,computer_science,color='red')

# Display the plot
plt.show()