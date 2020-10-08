#include <vector>
using namespace std;
bool boundsExceeded(int, int, int, int);

vector<int> zigzagTraverse(vector<vector<int>> array) {
	vector<int> zigzag{};
	int height = array.size() - 1;
	int width = array[0].size() - 1;

	int row{ 0 }, column{ 0 };
	bool goingDown = true;

	while (!boundsExceeded(row, column, height, width)) {
		zigzag.push_back(array[row][column]);
		if (goingDown) {
			if (column == 0 || row == height) {
				goingDown = false;
				if (row == height) {
					column++;
				}
				else
					row++;
			}
			else {
					row++;
					column--;
				}
			}
			else {
				if (column == width || row == 0){
					goingDown = true;
					if (column == width)
						row++;
					else 
						column++;
				}else {
					row--;
					column++;
				}
			}
		}
		return zigzag;
	}

bool boundsExceeded(int row, int column, int height, int width) {
	return row < 0 || row > height || column < 0 || column > width;
}