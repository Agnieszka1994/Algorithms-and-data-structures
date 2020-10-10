using namespace std;

vector<vector<int>> getUnvisitedNodes(int i, int j, vector<vector<int>> matrix,
	vector<vector<int>> visited);
void nodeTraversal(int i, int j, vector<vector<int>> matrix,
	vector<vector<int>>* visited, vector<int>* sizes);

vector<int> riverSizes(vector<vector<int>> matrix) {
	vector<int> sizes{};
	vector<vector<int>> visited(matrix.size(), vector<int>(matrix[0].size(), false));

	for (int i = 0; i < matrix.size(); i++) {
		for (int j = 0; j < matrix[0].size(); j++) {
			if (visited[i][j]) {
				continue;
			}
			nodeTraversal(i, j, matrix, &visited, &sizes);
		}
	}
	return sizes;
}

void nodeTraversal(int i, int j, vector<vector<int>> matrix,
	vector<vector<int>>* visited, vector<int>* sizes) {

	int currentRiverSize{ 0 };
	vector<vector<int>> nodesToTraverse{ {i, j} };

	while (nodesToTraverse.size()) {
		vector<int> currentNode = nodesToTraverse.back();
		nodesToTraverse.pop_back();
		i = currentNode[0];
		j = currentNode[1];

		if (visited->at(i)[j]) {
			continue;
		}
		visited->at(i)[j] = true;
		if (matrix[i][j] == 0) {
			continue;
		}
		currentRiverSize++;
		vector<vector<int>> unvisitedNodes = getUnvisitedNodes(i, j, matrix, *visited);
		for (auto neighbor : unvisitedNodes) {
			nodesToTraverse.push_back(neighbor);
		}
	}
	if (currentRiverSize > 0) {
		sizes->push_back(currentRiverSize);
	}
}

vector<vector<int>> getUnvisitedNodes(int i, int j, vector<vector<int>> matrix,
	vector<vector<int>> visited) {

	vector<vector<int>> unvisitedNodes{};
	if (i > 0 && !visited[i - 1][j]) {
		unvisitedNodes.push_back({ i - 1, j });
	}
	if (i < matrix.size() - 1 && !visited[i + 1][j]) {
		unvisitedNodes.push_back({ i + 1, j });
	}
	if (j > 0 && !visited[i][j - 1]) {
		unvisitedNodes.push_back({ i, j - 1 });
	}
	if (j < matrix[0].size() - 1 && !visited[i][j + 1]) {
		unvisitedNodes.push_back({ i, j + 1 });
	}
	return unvisitedNodes;
}
