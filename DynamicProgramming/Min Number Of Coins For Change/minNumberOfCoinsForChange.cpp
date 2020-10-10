#include <vector>
using namespace std;

int minNumberOfCoinsForChange(int n, vector<int> denoms) {
  vector<int> numberOfCoins (n+1, INT_MAX);
	numberOfCoins[0] = 0;
	int toCompare = 0;
	 for(auto denom: denoms){
		 for(int i = 0; i< numberOfCoins.size(); i++){
			 if(denom <= i){
				 if(numberOfCoins[i - denom] == INT_MAX){
					 toCompare = numberOfCoins[i - denom];
				 }else{
					 toCompare = numberOfCoins[i - denom] + 1;
				 }
				 numberOfCoins[i] = min(numberOfCoins[i], toCompare);
			 }
		 }
	 }
	return numberOfCoins[n] != INT_MAX ? numberOfCoins[n] : -1;
}