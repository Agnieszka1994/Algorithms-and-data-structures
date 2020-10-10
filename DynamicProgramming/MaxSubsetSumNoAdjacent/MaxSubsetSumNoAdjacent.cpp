#include <vector>
using namespace std;

int maxSubsetSumNoAdjacent(vector<int> array) {
	if(array.size()==0){
		return 0;
	}else if(array.size()==1){
		return array[0];
	}
	vector<int> sums = array;
	sums[1] = max (array[0], array[1]);

	for (int i = 2; i < array.size(); i++) {
		sums[i] = max(sums[i - 1], sums[i - 2] + array[i]);
	}
	int maxSum = sums[array.size() -1];
	return maxSum;
}