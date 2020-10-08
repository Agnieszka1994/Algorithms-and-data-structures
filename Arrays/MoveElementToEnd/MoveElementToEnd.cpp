#include <vector>

using namespace std;

vector<int> moveElementToEnd(vector<int> array, int toMove) {
	
	int one = 0;
	int two = array.size() - 1;
	
	while(one<two){
		if(array[one] == toMove && array[two] != toMove){
			swap(array[one], array[two]);
			one++;
			two--;
		}
		else if(array[one] != toMove && array[two] == toMove ){
			one++;
			two--;
		}
		else if(array[one] != toMove && array[two] != toMove ){
			one++;
		}
		else{
			two--;
		}
		
	}

	return array;
}

