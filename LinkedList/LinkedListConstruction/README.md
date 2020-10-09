# Doubly Linked List

This file contains the implementation of a DoublyLinkedList class.
It contains head and tail, both of which point to either a linked list Node or NULL.
Each Node has an integer value as well as 'prev' node and a 'next' node.

The class support the following methods: 
- Setting the head adn the tail of the linked list
- Inserting nodes before and after other nodes and at given position (the head position is 1)
The input nodes can be either new Nodes or nodes that are already in the linked list. In such cases the methods will be moving the nodes within the linked list.
- removing given nodes and nodes with given values
- searching for nodes with given values 



# Sample Usage

We are given the following list and 3 stand-alone nodes: 
1 <-> 2 <-> 3 <-> 4 <-> 5   //  7, 8, 9

setHead(4) - set the existing node with value 4 as the head
setTail(7) - set the new node with value 7 as the tail
insertBefore(7,3) - move the existing node with value 3 before the existing node with value 7
insertAfter(3,9) - insert a new node with value 9 after the existing node with value 3
insertAtPosition(1,8) - insert a new node with value 8 in position 1
removeNodesWithValue(3) - remove all nodes with value 3
remove(2) - remove the existing node with value 2
containsNodeWithValue(5) : true


# Space and Time complexity

O(1) time | O(1) space:
setHead  
setTail 
insertBefore 
insertAfter 
remove

O(p)time | O(1)space - where p is input position
insertAtPosition

O(n)time | O(1)space - where n is the number of nodes in the linked list
removeNodesWithValue
containsNodeWithValuee
