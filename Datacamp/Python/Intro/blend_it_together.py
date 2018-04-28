# heights and positions are available as lists
# Import numpy
import numpy as np

# Convert positions and heights to numpy arrays: np_positions, np_heights
np_positions = np.array(positions)
np_heights = np.array(heights)
# Heights of the goalkeepers: gk_heights
goalk = (np_positions=='GK')
gk_heights = np.array(np_heights[goalk])
# Heights of the other players: other_heights
others = (np_positions!='GK')
other_heights = np.array(np_heights[others])
# Print out the median height of goalkeepers. Replace 'None'
print("Median height of goalkeepers: " + str(np.median(gk_heights)))
# Print out the median height of other players. Replace 'None'
print("Median height of other players: " + str(np.median(other_heights)))
