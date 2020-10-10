#include <vector>
using namespace std;

int numberOfWaysToMakeChange(int n, vector<int> denoms) {
	vector<int> waysOfChange(n + 1, 0);
	waysOfChange[0] = 1;

	for (int j = 0; j < denoms.size(); j++) {
		for (int i = 1; i < n+1; i++) {
			if (denoms[j] <= i) {
				waysOfChange[i] += waysOfChange[i - denoms[j]];
			}
		}
	}
	return waysOfChange[n];
}