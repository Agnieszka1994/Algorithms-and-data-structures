#include <vector>
#include <unordered_map>
#include <algorithm>
#include <climits>
#include <set>
using namespace std;

int getMinSpaceX(string PI, set<string> numbersTable, unordered_map<int, int>* cache, int index);

int numbersInPi(string pi, vector<string> numbers) {
	set<string> numbersTable;
	for (auto number : numbers) {
		numbersTable.insert(number);
	}
	unordered_map<int, int> cache;
	for (int i = 0; i < pi.length(); i++) {
		getMinSpaceX(pi, numbersTable, &cache, i);
	}
	return cache.at(0) == INT_MAX ? -1: cache.at(0);
}

int getMinSpaceX(string pi, set<string> numbersTable, unordered_map<int, int>* cache, int index) {
	if (index == pi.length())
		return -1;

	if (cache->find(index) != cache->end())
		return cache->at(index);
	int minSpaces = INT_MAX;

	for (int i = index; i < pi.length(); i++) {
		string prefix = pi.substr(index, i + 1 - index);
		if (numbersTable.find(prefix) != numbersTable.end()) {
			int minSpacesInSuffix = getMinSpaceX(pi, numbersTable, cache, i + 1);
			//int overflow
			if(minSpacesInSuffix == INT_MAX){
				minSpaces = min(minSpaces, minSpacesInSuffix);
			}else{
				minSpaces = min(minSpaces, minSpacesInSuffix + 1);
			}
		}
	}
	cache->insert({index, minSpaces});
	return cache->at(index);
}