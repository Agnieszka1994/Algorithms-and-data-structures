#include <vector>
using namespace std;

vector<int> bubbleSort(vector<int> array) {
	
    for (int i=1; i<array.size(); i++)
    {
        for (int j=array.size()-1; j>=1; j--)
        {
            if (array[j]<array[j-1])
            {
                int buffer;
                buffer=array[j-1];
                array[j-1]=array[j];
                array[j]=buffer;
            }
        }
    }
  return array;
}
