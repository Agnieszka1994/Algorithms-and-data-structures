#include <vector>
using namespace std;

bool isValidSubsequence(vector<int> array, vector<int> sequence){
	int position = 0;
	for (int i = 0; i < array.size(); i++)
		for (int j = position; j < sequence.size(); j++){
			if(array[i] == sequence[j]){
				position ++;
				break;	
			}
				
		}
	
	if(position == sequence.size()) 
		return true;
	else return false; 
	
}