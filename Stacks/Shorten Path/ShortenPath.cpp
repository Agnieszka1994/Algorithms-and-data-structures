#include <sstream>
using namespace std;
bool isImportantToken(string token);

string shortenPath(string path) {

	bool startsWithSlash = path[0] == '/';
	string curentToken;
	stringstream tokenStream(path);

	vector<string> splitTokens{};
	vector<string> filteredTokens{};
	vector<string> shortenPath{};

	while (getline(tokenStream, curentToken, '/')) {
		splitTokens.push_back(curentToken);
	}

	copy_if(splitTokens.begin(), splitTokens.end(), back_inserter(filteredTokens), isImportantToken);

	if (startsWithSlash)
		shortenPath.push_back("");

	for (auto token : filteredTokens) {
		if (token == "..") {
			if (shortenPath.size() == 0 || shortenPath.back() == "..") {
				shortenPath.push_back(token);
			} else if (shortenPath.back() != "") {
				shortenPath.pop_back();
			}
		}else {
			shortenPath.push_back(token);
		}
	}
	
	if(shortenPath.size() == 1 && shortenPath.front() == ""){
		return "/";
	}
	stringstream result; 
	for(int i = 0 ; i < shortenPath.size(); i++){
		if(i!=0) result << "/";
		 result << shortenPath[i];
	}
	return result.str();
}

bool isImportantToken(string token) { return token != "." && token.length(); };
