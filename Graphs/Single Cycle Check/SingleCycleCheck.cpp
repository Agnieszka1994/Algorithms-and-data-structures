#include <vector>
using namespace std;
int getNextIndex(int currentIdx, vector<int> array);
bool hasSingleCycle(vector<int> array) {
    int currentIdx = 0;
    int counter = 0;
    while (counter < array.size()) {
        if (currentIdx == 0 && counter > 0)
            return false;
        counter++;
        currentIdx = getNextIndex(currentIdx, array);
    }
    return currentIdx == 0;
}

int getNextIndex(int currentIdx, vector<int> array) {
    int nextIdx = (currentIdx + array[currentIdx]) % (int)array.size();
    return nextIdx >= 0 ? nextIdx : nextIdx + array.size();
}