#include <vector>
using namespace std;

struct Item {
	int arrayIdx;
	int number;
};

Item getMinValue(vector<Item> items);

vector<int> mergeSortedArrays(vector<vector<int>> arrays) {
	vector<int> sortedList;
	vector<int> elementIdxs(arrays.size(), 0);

	while (true) {
		vector<Item> smallestItems;
		for (int arrayIdx = 0; arrayIdx < arrays.size(); arrayIdx++) {
			vector<int> currentArray = arrays[arrayIdx];
			int elementIdx = elementIdxs[arrayIdx];
			if (elementIdx == currentArray.size())
				continue;
			smallestItems.push_back(Item{ arrayIdx, currentArray[elementIdx] });
		}
		if (smallestItems.size() == 0)
			break;
		Item nextItem = getMinValue(smallestItems);
		sortedList.push_back(nextItem.number);
		elementIdxs[nextItem.arrayIdx]++;
	}
	return sortedList;
}

Item getMinValue(vector<Item> items) {
	int minValInx = 0;
	for (int i = 1; i < items.size(); i++) {
		if (items[i].number < items[minValInx].number) {
			minValInx = i;
		}
	}
	return items[minValInx];
}