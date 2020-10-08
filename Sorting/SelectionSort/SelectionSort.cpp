#include <vector>
using namespace std;

vector<int> selectionSort(vector<int> array) {
  if(array.empty()){
		return{};
	}
	int startIndex{0};
	while(startIndex < array.size()-1){
		int smallestIndex = startIndex;
		for(int i = startIndex; i<array.size(); i++){
			if(array[smallestIndex]>array[i]){
				smallestIndex = i;
			}
			
		}
		swap(array[smallestIndex], array[startIndex]);
		startIndex++;
	}
  return array;
}