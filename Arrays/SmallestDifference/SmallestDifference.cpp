#include <vector>
using namespace std;

vector<int> smallestDifference(vector<int> arrayOne, vector<int> arrayTwo) {

	int potentialDif = abs(arrayOne[0] - arrayTwo[0]);
	int one = 0;
	int two = 0;
	
	for (int i = 0; i < arrayOne.size(); i++) {
		for (int j = 0; j < arrayTwo.size(); j++)
			if (abs(arrayOne[i] - arrayTwo[j]) < potentialDif) {
				potentialDif = abs(arrayOne[i] - arrayTwo[j]);
				one = arrayOne[i];
				two = arrayTwo[j];
		}
	}


	return { one , two };
}
