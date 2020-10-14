#include <vector>
using namespace std;
vector<int> searchForRange(vector<int> array, int target);
void binarySearchVariation(vector<int> array, int target, int left, int right,
													vector<int> *finalRange, bool goLeft);

vector<int> searchForRange(vector<int> array, int target) {
  vector<int> finalRange = {-1, -1};
	binarySearchVariation(array, target, 0, array.size()-1, &finalRange, true);
	binarySearchVariation(array, target, 0, array.size()-1, &finalRange, false);
  return finalRange;
}

void binarySearchVariation(vector<int> array, int target, int left, int right,
													vector<int> *finalRange, bool goLeft){
	while (left <=right) {
		int middle = (left + right) /2;
		if(array[middle] < target){
			left = middle + 1;
		}else if (array[middle] > target){
			right = middle - 1;
		}else {
			if(goLeft){
				if(middle == 0 || array[middle - 1] != target){
					finalRange->at(0) = middle;
					return;
				} else{
					right = middle - 1;
				}
			// if we go right - searching for the right limit
			}else {
				if(middle == array.size()-1 || array[middle + 1] != target){
					finalRange->at(1) = middle;
					return;
				}else{
					left = middle + 1;
				}
			}
		}
	}
}