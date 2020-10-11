#include <vector>
using namespace std;

vector<int> sort(vector<int> array);

vector<int> findThreeLargestNumbers(vector<int> array) {
    vector<int> sortedArray(3, INT_MIN);

    for (auto element : array) {
        if (element > sortedArray[0]) {
            sortedArray[0] = element;
        }
        else if (element > sortedArray[1]) {
            sortedArray[1] = element;
        }
        else if (element > sortedArray[2]) {
            sortedArray[2] = element;
        }
        sortedArray = sort(sortedArray);
    }
    return sortedArray;
}

vector<int> sort(vector<int> array) {

    for (int i = 1; i < array.size(); i++)
    {
        for (int j = array.size() - 1; j >= 1; j--)
        {
            if (array[j] < array[j - 1])
            {
                int buffer;
                buffer = array[j - 1];
                array[j - 1] = array[j];
                array[j] = buffer;
            }
        }
    }
    return array;
}