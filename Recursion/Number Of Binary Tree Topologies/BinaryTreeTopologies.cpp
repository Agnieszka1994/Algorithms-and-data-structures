#include <unordered_map>
using namespace std;

int binaryTreeHelper(int, unordered_map<int, int>*);

int numberOfBinaryTreeTopologies(int n) {
	unordered_map<int, int> cache{ { 0, 1 } };
	return binaryTreeHelper(n, &cache);
}

int binaryTreeHelper(int n, unordered_map<int, int>* cache) {
	if (cache->find(n) != cache->end()) {
		return cache->at(n);
	}
	int treeCount = 0;
	for (int leftTreeSize = 0; leftTreeSize < n; leftTreeSize++) {
		int rightTreeSize = n - 1 - leftTreeSize;
		int leftTreesCount = binaryTreeHelper(leftTreeSize, cache);
		int rightTreesCount = binaryTreeHelper(rightTreeSize, cache);
		treeCount += leftTreesCount * rightTreesCount;
	}
	cache->insert({ n, treeCount });
	return treeCount;
}