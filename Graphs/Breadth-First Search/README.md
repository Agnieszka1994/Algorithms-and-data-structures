# Breadth-First Search

This method is implemented within a `Node` class. 
A Node class has a 'name' and 'children' nodes, which form a tree like structure.  \
The `breadthFirstSearch` method taked in an empty array, traverse the tree using the Breadth-First Search approach (navigating the tree from left to right), stores all of the nodes's names in the input array and returns it.

# Sample Input
```javascript
graph = [
"graph": {
    "nodes": [
      {"children": ["B", "C", "D"], "id": "A", "value": "A"},
      {"children": ["E", "F"], "id": "B", "value": "B"},
      {"children": [], "id": "C", "value": "C"},
      {"children": ["G", "H"], "id": "D", "value": "D"},
      {"children": [], "id": "E", "value": "E"},\
      {"children": ["I", "J"], "id": "F", "value": "F"},
      {"children": ["K"], "id": "G", "value": "G"},
      {"children": [], "id": "H", "value": "H"},
      {"children": [], "id": "I", "value": "I"},
      {"children": [], "id": "J", "value": "J"},
      {"children": [], "id": "K", "value": "K"}
    ],
    "startNode": "A"\
  }
]
```
  
# Sample Output
```javascript
["A", "B", "C", "D", "E", "F", "G", "H", "I", "J", "K"]
```
# Space and Time complexity
O(v+e) time | O(v) space - where v is the number of vertices of the input graph and e is the number of edges of the input graph
