#include <vector>
using namespace std;

int getNthFib(int n) {
  vector<int> lastTwo = {0,1};
	int counter = 3;
	while(counter <= n){
		int next = lastTwo[0] + lastTwo[1];
		lastTwo[0] = lastTwo[1];
		lastTwo[1] = next;
		counter++;
	}
  return n > 1 ? lastTwo[1] : lastTwo[0];
}