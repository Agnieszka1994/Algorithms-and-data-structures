#include <vector>
using namespace std;

vector<vector<int>> getKnapsackItems(vector<vector<int>>, vector<vector<int>>, int);

vector<vector<int>> knapsackProblem(vector<vector<int>> items, int capacity) {
	vector<vector<int>> matrix(items.size() + 1,
		vector<int>(capacity + 1, 0));

	for (int i = 1; i < items.size() + 1; i++) {
		int currentWeight = items[i - 1][1];
		int currentValue = items[i - 1][0];
		for (int j = 0; j < capacity + 1; j++) {
			if (currentWeight > j) {
				matrix[i][j] = matrix[i - 1][j];
			}
			else {
				matrix[i][j] =
					max(matrix[i - 1][j],
						matrix[i - 1][j - currentWeight] + currentValue);
			}
		}
	}
	return getKnapsackItems(matrix, items, matrix[items.size()][capacity]);
}

vector<vector<int>> getKnapsackItems(vector<vector<int>> values, vector<vector<int>> items, int weight) {
	vector<vector<int>> solution = { {}, {} };
	int i = values.size() - 1;
	int j = values[0].size() - 1;
	while (i > 0) {
		if (values[i][j] == values[i - 1][j]) {
			i--;
		}
		else {
			solution[1].insert(solution[1].begin(), i - 1);
			j -= items[i - 1][1];
			i--;
		}
		if (j == 0) {
			break;
		}
	}
	solution[0].push_back(weight);
	return solution;
}
