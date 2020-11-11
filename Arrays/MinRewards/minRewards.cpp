#include <numeric>
#include <vector>
using namespace std;

int minRewards(vector<int> scores) {
	vector<int> rewards(scores.size(), 1);
	int sum{ 0 };
	for (int i = 1; i < scores.size(); i++) {
		if (scores[i] > scores[i - 1])
			rewards[i] = rewards[i - 1] + 1;
	}
	for (int i = scores.size() - 1; i > 0; i--) {
		if (scores[i - 1] > scores[i])
			rewards[i - 1] = max(rewards[i] + 1, rewards[i - 1]);
	}
	return accumulate(rewards.begin(), rewards.end(), 0);
}