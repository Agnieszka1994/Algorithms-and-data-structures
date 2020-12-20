#include <limits>
#include <vector>
#include <cmath>
#include <algorithm>
#include <string>
#include <unordered_map>

class Node
{
public:
	std::string id;
	int row;
	int column;
	int value;
	int distanceFromStart;
	int distanceToEnd;
	Node* cameFrom;

	Node(int row, int column, int value) :
		id{ std::to_string(row) + '-' + std::to_string(column) },
		row{ row }, 
		column{ column },
		value{ value },
		distanceFromStart{ std::numeric_limits<int>::max() },
		distanceToEnd{ std::numeric_limits<int>::max()  },
		cameFrom{nullptr}
	{}
};

class MinHeap
{
public:
	std::vector<Node *> heap;
	std::unordered_map<std::string, int> nodePositionsInHeap;

	MinHeap(std::vector<Node*> array)
	{
		for (int i = 0; i < array.size(); i++) {
			auto node = array[i];
			nodePositionsInHeap[node->id] = i;
		}
		heap = buildHeap(array);
	}

	std::vector<Node*> buildHeap(std::vector<Node*>& array)
	{
		int firstParentIdx = (array.size() - 2) / 2;
		for (int currentIdx = firstParentIdx + 1; currentIdx >= 0; currentIdx--) {
			siftDown(currentIdx, array.size() - 1, array);
		}
		return array;
	}

	bool isEmpty() {
		return heap.size() == 0;
	}

	void siftDown(int currentIdx, int endIdx, std::vector<Node *> &array)
	{
		int childOneIdx{ currentIdx * 2 + 1 };
		while (childOneIdx <= endIdx) {
			int childTwoIdx = currentIdx * 2 + 2 <= endIdx ? currentIdx * 2 + 2 : -1;
			int idxToSwap;
			if (childTwoIdx != -1 && array[childTwoIdx]->distanceToEnd < heap[childOneIdx]->distanceToEnd) {
				idxToSwap = childTwoIdx;
			}
			else {
				idxToSwap = childOneIdx;
			}
			if (array[idxToSwap]->distanceToEnd < 
					array[currentIdx]->distanceToEnd) {
				swap(currentIdx, idxToSwap);
				currentIdx = idxToSwap;
				childOneIdx = currentIdx * 2 + 1;
			}
			else {
				return;
			}
		}
	}

	void siftUp(int currentIdx) {
		int parentIdx{ (currentIdx - 1) / 2 };
		while (currentIdx > 0 && heap[currentIdx]->distanceToEnd 
			< heap[parentIdx]->distanceToEnd)
		{
			swap(currentIdx, parentIdx);
			currentIdx = parentIdx;
			parentIdx = (currentIdx - 1) / 2;
		}
	}

	Node* remove()
	{
		if (isEmpty()) {
			return nullptr;
		}

		swap(0, heap.size() - 1);
		auto node{ heap.back() };
		heap.pop_back();
		nodePositionsInHeap.erase(node->id);
		siftDown(0, heap.size() - 1, heap);
		return node;
	}

	void insert(Node* node)
	{
		heap.push_back(node);
		nodePositionsInHeap[node->id] = heap.size() - 1;
		siftUp(heap.size() - 1);
	}

	void swap(int i, int j)
	{
		nodePositionsInHeap[heap[i]->id] = j;
		nodePositionsInHeap[heap[j]->id] = i;
		auto temp{ heap[i] };
		heap[i] = heap[j];
		heap[j] = temp;
	}

	bool containsNode(Node* node) {
		return nodePositionsInHeap.find(node->id) != nodePositionsInHeap.end();
	}

	void update(Node* node) {
		siftUp(nodePositionsInHeap[node->id]);
	}
};

std::vector<std::vector<int>> reconstructPath(Node* endNode);
std::vector<Node*> getNeighbors(Node* node, std::vector<std::vector<Node*>>& nodes);
std::vector<std::vector<Node*>> initializeNodes(std::vector<std::vector<int>> graph);
int calculateDistance(Node* currentNode, Node* endNode);

std::vector<std::vector<int>> aStarAlgorithm
(int startRow, int startCol, int endRow, int endCol, std::vector<std::vector<int>> graph)
{
	auto nodes{ initializeNodes(graph) };
	auto startNode{ nodes[startRow][startCol] };
	auto endNode{ nodes[endRow][endCol] };

	startNode->distanceFromStart = 0;
	startNode->distanceToEnd = calculateDistance(startNode, endNode);

	MinHeap nodesToVisit(std::vector<Node *>{startNode});

	while (!nodesToVisit.isEmpty())
	{
		auto currentMinDistanceNode{ nodesToVisit.remove() };

		if (currentMinDistanceNode == endNode) {
			break;
		}

		auto neighbors{ getNeighbors(currentMinDistanceNode, nodes) };

		for (auto neighbor : neighbors) {
			if (neighbor->value == 1) {
				continue;
			}

			int tentativeDistanceToNeighbor{ currentMinDistanceNode->distanceFromStart + 1 };

			if (tentativeDistanceToNeighbor >= neighbor->distanceFromStart) {
				continue;
			}

			neighbor->cameFrom = currentMinDistanceNode;
			neighbor->distanceFromStart = tentativeDistanceToNeighbor;
			neighbor->distanceToEnd = 
				tentativeDistanceToNeighbor + calculateDistance(neighbor, endNode);

			if (!nodesToVisit.containsNode(neighbor)) {
				nodesToVisit.insert(neighbor);
			}
			else {
				nodesToVisit.update(neighbor);
			}
		}
	}
	return reconstructPath(endNode);
}

std::vector<std::vector<Node*>> initializeNodes(std::vector<std::vector<int>> graph)
{
	std::vector<std::vector<Node*>> nodes;

	for (int i = 0; i < graph.size(); i++) {
		nodes.push_back(std::vector<Node*>{});
		for (int j = 0; j < graph[i].size(); j++) {
			nodes[i].push_back(new Node(i, j, graph[i][j]));
		}
	}
	return nodes;
}

int calculateDistance(Node* currentNode, Node* endNode)
{
	int currentRow{ currentNode->row };
	int currentCol{ currentNode->column };
	int endRow{ endNode->row };
	int endCol{ endNode->column };

	return abs(currentRow - endRow) + abs(currentCol - endCol);
}

//get Neightboring Nodes
std::vector<Node*> getNeighbors(Node* node, std::vector<std::vector<Node*>>& nodes)
{
	std::vector<Node*> neighbors;

	int numRows = nodes.size();
	int numCols = nodes[0].size();

	int row{ node->row };
	int column{ node->column };

	if (row < numRows - 1) {
		// DOWN 
		neighbors.push_back(nodes[row + 1][column]);
	}

	if (row > 0) {
		// UP
		neighbors.push_back(nodes[row - 1][column]);
	}

	if (column < numCols - 1) {
		// RIGHT
		neighbors.push_back(nodes[row][column + 1]);
	}

	if (column > 0) {
		// LEFT
		neighbors.push_back(nodes[row][column - 1]);
	}
	return neighbors;
}

std::vector<std::vector<int>> reconstructPath(Node* endNode)
{
	if (endNode->cameFrom == nullptr)
	{
		return std::vector<std::vector<int>>{};
	}

	Node* currentNode{ endNode };
	std::vector<std::vector<int>> path;

	while (currentNode != nullptr)
	{
		path.push_back(std::vector<int>{ currentNode->row, currentNode->column });
		currentNode = currentNode->cameFrom;
	}
	std::reverse(path.begin(), path.end());
	return path;
}

