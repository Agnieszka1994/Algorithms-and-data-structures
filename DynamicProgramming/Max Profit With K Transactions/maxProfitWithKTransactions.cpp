#include <vector>
using namespace std;

int maxProfitWithKTransactions(vector<int> prices, int k) {
	if (prices.empty()) {
		return 0;
	}

	vector<vector<int>> profits(k + 1, vector<int>(prices.size(), 0));
	for (int transaction = 1; transaction <= k; transaction++) {
		int currentMax{INT_MIN};
		for (int day = 1; day < prices.size(); day++) {
			currentMax = max(currentMax, profits[transaction - 1][day - 1] - prices[day - 1]);
			profits[transaction][day] = max(profits[transaction][day - 1], currentMax + prices[day]);
		}
	}
	return profits[k].back();
}