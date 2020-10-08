using namespace std;

vector<int> spiralTraverse(vector<vector<int>> array) {
		
	vector<int> solution = {};
  int startRow = 0;
	int endRow = array.size()-1;
	int startCol = 0;
	int endCol = array[0].size()-1;
	int totalSize = endRow * endCol;
	
	while(endCol>=startCol && endRow >= startRow){
		
		for(int i = startCol; i <= endCol; i++){
		solution.push_back(array[startRow][i]);
	}

	for(int i = startRow+1; i <= endRow; i++){
		solution.push_back(array[i][endCol]);
	}
	

	for(int i = endCol-1; i >= startCol; i--){
		if(startRow == endRow)
			break;
		solution.push_back(array[endRow][i]);
	}

	for(int i = endRow -1; i > startCol; i--){
		if(startCol == endCol)
			break;
		solution.push_back(array[i][startCol]);
	}
	startCol++;
	startRow++;
	endCol--;
	endRow--;
	}

	
  return solution;
}