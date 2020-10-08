using namespace std;

bool isMonotonic(vector<int> array) {
	if (array.size() == 0 || array.size() == 1) {
		return true;
	}
	else{
		bool increasing = false;
		for (int i = 0; i < (array.size() - 1); i++){
			if(array[i] == array[i + 1]) 
				continue;
			else if(array[i] > array[i + 1]){
				increasing = false;
				break;
			}
			else if(array[i] < array[i + 1]){
				increasing = true;
				break;
			}	
		}
		
		 if (!increasing) {
		for (int i = 0; i < (array.size() - 1); i++) {
			if (array[i] < array[i + 1])
				return false;
		}
	}
	else if (increasing) {
		for (int i = 0; i < array.size() - 1; i++) {
			if (array[i] > array[i + 1])
				return false;
		}
	}
	
	return true;
	}
}
