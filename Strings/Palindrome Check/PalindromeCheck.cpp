using namespace std;

bool isPalindrome(string str) {
  
	int last = str.length();
	for(int i = 0; i< str.length()/2; i++){
		if(str[i]!=str[last-1]){
			return false;
		}
		last--;
	}
  return true;
}