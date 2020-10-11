using namespace std;
vector <int> getLongestPalindrome(string str, int left, int right);

string longestPalindromicSubstring(string str) {

	vector <int> currentLongest{ 0,1 }; //startIdx and (endIdx +1)

	auto longer = [](string str1, string str2) { return str1.length() > str2.length(); };
	for (int i = 1; i < str.length(); i++) {
		vector <int> odd = getLongestPalindrome(str, i - 1, i + 1);
		vector <int> even = getLongestPalindrome(str, i - 1, i);
		vector <int> longest = odd[1]- odd[0] > even[1] - even[0] ? odd: even;
		currentLongest = currentLongest[1] - currentLongest[0] > longest[1] - longest[0] ? 
			currentLongest: longest;
	}

	return str.substr(currentLongest[0], currentLongest[1] - currentLongest[0]);
}

vector <int> getLongestPalindrome(string str, int left, int right) {
	while (left >= 0 && right < str.length()) {
		if (str[left] != str[right])
			break;
		left--;
		right++; 
	}
	return vector <int>{left+1, right}; //startIdx and (endIdx +1)
}