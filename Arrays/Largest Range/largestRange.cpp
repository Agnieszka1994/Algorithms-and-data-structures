#include <vector>
#include <unordered_map>
using namespace std;

vector<int> largestRange(vector<int> array) {
	vector<int> largestRange = {};
	int maxLength = 0;
	unordered_map<int, bool> numbers = {};
	//insert all values to the hash table and assign true
	for (int number : array) {
		numbers[number] = true;
	}
	for (int number : array) {
		//check if the number was already used 
		if (!numbers[number]) {
			continue;
		}
		//if not - mark number as used
		numbers[number] = false;
		int currentLen = 1;
		int leftNum = number - 1;
		int rightNum = number + 1;
		while (numbers.find(leftNum) != numbers.end()) {
			numbers[leftNum] = false;
			currentLen++;
			leftNum--;
		}
		while (numbers.find(rightNum) != numbers.end()) {
			numbers[rightNum] = false;
			currentLen++;
			rightNum++;
		}
		if (currentLen > maxLength) {
			maxLength = currentLen;
			largestRange = { leftNum + 1, rightNum - 1 };
		}
	}
	return largestRange;
}