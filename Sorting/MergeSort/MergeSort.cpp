#include <vector>
using namespace std;

void mergeSortHelper(vector<int> *, int, int, vector<int> *);
void doMerge(vector<int> *, int, int, int, vector<int> *);

vector<int> mergeSort(vector<int> array) {
  if(array.size() <= 1){
		return array;
	}
	vector<int> helperArray = array;
	mergeSortHelper(&array, 0, array.size()-1, &helperArray);

  return array;
}


void mergeSortHelper(vector<int> *array, int leftPtr, int rightPtr, vector<int> *helperArray){
	if(leftPtr == rightPtr)
		return;
	
	int middlePtr = (leftPtr + rightPtr)/2;
	mergeSortHelper(helperArray, leftPtr, middlePtr, array);
	mergeSortHelper(helperArray, middlePtr+1, rightPtr, array);
	doMerge(array, leftPtr, middlePtr, rightPtr, helperArray);
}

void doMerge(vector<int> *array, int leftPtr, int middlePtr, int rightPtr, vector<int> *helperArray){
	int i = leftPtr;
	int j = leftPtr;
	int k = middlePtr + 1; 
	
	while(j <=middlePtr && k <= rightPtr){
		if(helperArray->at(j) <= helperArray->at(k)){
			array->at(i++) = helperArray->at(j++);
		}else{
			array->at(i++) = helperArray->at(k++);
		}
	}
	while(j <=middlePtr){
		array->at(i++) = helperArray->at(j++);
	}
	while(k <= rightPtr){
		array->at(i++) = helperArray->at(k++);
	}
}
