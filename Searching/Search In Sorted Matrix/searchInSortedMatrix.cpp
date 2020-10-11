#include <vector>
using namespace std;
int binarySearch(vector<int> array, int target);
int search (vector<int> array, int target, int left, int right);

vector<int> searchInSortedMatrix(vector<vector<int>> matrix, int target) {
  vector<int> indecies{-1, -1};
	for(int j = 0; j < matrix.size(); j++){
		 if(search(matrix[j], target, 0, matrix[j].size()-1) != -1){
			 indecies[0] = j;
			 indecies[1] = search(matrix[j], target, 0, matrix[j].size()-1);
			 break;
		 }
	}
	return indecies;
}

int binarySearch(vector<int> array, int target) {
	return search(array, target, 0, array.size()-1);
}

int search (vector<int> array, int target, int left, int right){
	if (left > right){
		return -1;
	}
	int middle = (left + right) / 2;
	if(array[middle] == target){
		return middle;
	}
	else if(array[middle] > target){
		return search(array, target, left, middle-1);
	}
	else{
		return search(array, target, middle+1, right);
	}
}