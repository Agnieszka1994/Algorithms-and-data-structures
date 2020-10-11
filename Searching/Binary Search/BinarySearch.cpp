#include <vector>
using namespace std;
int binarySearch(vector<int> array, int target);
int search (vector<int> array, int target, int left, int right);

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
