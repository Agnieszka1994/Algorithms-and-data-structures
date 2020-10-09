# Apartment Hunting

This function takes in a list of contiguous blocks on a specific street and a list of required buildings and returns the location (index) of the block that is the most optimal. 
The block list contains information at every block about all of the buildings that are present and absent at the block in question. The function pick an apartment such that to minimize the farthest distance between the selected apartment and any of the required buildings.

### Sample input
blocks = [\
{\
"gym", false,\
"school", true,\
"store", false,\
},\
{\
"gym", true,\
"school", false,\
"store", false,\
},\
{\
"gym", true,\
"school", true,\
"store", false,\
},\
{\
"gym", false,\
"school", true,\
"store", false,\
},\
{\
"gym", false,\
"school", true,\
"store", true,\
}, \
]

requirements = ["gym", "school", "store"]

### Sample output

3 - the farthest distance between the selected apartment and any of the required buildings is 1. 

### Space and Time complexity
O(br) Time | O(br) Space - where b is the number of blocks and r is the number of requirements.