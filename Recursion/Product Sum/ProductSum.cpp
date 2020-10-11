#include <any>
#include <vector>

using namespace std;

int sumArray(int depth, vector<any> array);

int productSum(vector<any> array) {

    return sumArray(1, array);
}

int sumArray(int depth, vector<any> array) {
    int sum = 0;
    for (auto element : array) {
        if (element.type() == typeid(vector<any>)) {

            sum += sumArray(depth + 1, any_cast<vector<any>>(element));
        }
        else {
            sum += any_cast<int>(element);
        }
    }
    return sum * depth;
}