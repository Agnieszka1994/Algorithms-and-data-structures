#include <unordered_map>
#include <vector>
using namespace std;

bool hasSquareOfZeros(vector<vector<int>>, int, int, int, int, unordered_map<string, bool>&);
bool isItSquareOfZeros(vector<vector<int>>& matrix, int r1, int c1, int r2, int c2);

bool squareOfZeroes(vector<vector<int>> matrix) {
	unordered_map<string, bool> cache;
	int lastIdx = matrix.size() - 1;
	return hasSquareOfZeros(matrix, 0, 0, lastIdx, lastIdx, cache);
}

bool hasSquareOfZeros(vector<vector<int>> matrix, int r1, int c1, int r2, int c2, unordered_map<string, bool>& cache) {
	if (r1 >= r2 || c1 >= c2)
		return false;

	string key = to_string(r1) + "-" + to_string(c1) + "-" + to_string(r2) + "-" + to_string(c2);

	if (cache.find(key) != cache.end())
		return cache[key];

	cache[key] = 
		isItSquareOfZeros(matrix, r1, c1, r2, c2) ||
		hasSquareOfZeros(matrix, r1 + 1, c1 + 1, r2 - 1, c2 - 1, cache) ||
		hasSquareOfZeros(matrix, r1, c1 + 1, r2 - 1, c2, cache) ||
		hasSquareOfZeros(matrix, r1 + 1, c1, r2, c2 - 1, cache) ||
		hasSquareOfZeros(matrix, r1 + 1, c1 + 1, r2, c2, cache) ||
		hasSquareOfZeros(matrix, r1, c1, r2 - 1, c2 - 1, cache);

	return cache[key];
}

bool isItSquareOfZeros(vector<vector<int>>& matrix, int r1, int c1, int r2, int c2) {

	for (int row = r1; row < r2 + 1; row++) {
		if (matrix[row][c1] != 0 || matrix[row][c2] != 0)
			return false;
	}
	for (int col = c1; col < c2 + 1; col++) {
		if (matrix[r1][col] != 0 || matrix[r2][col] != 0)
			return false;
	}
	return true;
}