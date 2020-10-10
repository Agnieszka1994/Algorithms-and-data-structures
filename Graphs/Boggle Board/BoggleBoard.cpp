#include <vector>
#include <unordered_set>
#include <unordered_map>
using namespace std;

class TrieNode {
public:
	unordered_map<char, TrieNode*> children;
	string word = "";
};

class Trie {
public:
	TrieNode* root;
	char endSymbol;

	Trie();
	void add(string str);
};

void explore(int, int, vector<vector<char>>, TrieNode*, 
			vector<vector<bool>>*, unordered_set<string>*);

vector<vector<int>> getNeighbors(int, int, vector<vector<char>>);

vector<string> boggleBoard(vector<vector<char>> board, vector<string> words) {
	Trie trie;
	for (auto word : words) {
		trie.add(word);
	}
	unordered_set<string> finalWords;
	vector<vector<bool>> visited(board.size(), vector<bool>(board[0].size(), false));

	for (int i = 0; i < board.size(); i++) {
		for (int j = 0; j < board[0].size(); j++) {
			explore(i, j, board, trie.root, &visited, &finalWords);
		}
	}
	vector<string> finalArray;
	for (auto word : finalWords) {
		finalArray.push_back(word);
	}
	return finalArray;
}

Trie::Trie() {
	this->root = new TrieNode();
	this->endSymbol = '*';
}

void Trie::add(string str) {
	TrieNode* node = this->root;
	for (auto letter : str) {
		if (node->children.find(letter) == node->children.end()) {
			TrieNode* newNode = new TrieNode();
			node->children.insert({ letter, newNode });
		}
		node = node->children[letter];
	}
	node->children.insert({this->endSymbol, nullptr});
	node->word = str;
}
void explore(int i, int j, vector<vector<char>> board, TrieNode* node,
			vector<vector<bool>>* visited, unordered_set<string>* finalWords) {
	if (visited->at(i)[j]) {
		return; //it the letter was already visited - return
	}
	char letter = board[i][j];
	if (node->children.find(letter) == node->children.end()) {
		return; //it the letter is not in the Trie - return
	}
	visited->at(i)[j] = true; //if found, mark the current letter as visited
	node = node->children[letter]; //go to the next letter in the Trie
	if (node->children.find('*') != node->children.end()) {
		finalWords->insert(node->word); //if endSymbol was found, add the word to the list
	}
	vector<vector<int>> neighbors = getNeighbors(i, j, board); //if endSymbol not found - explore all the neighbors
	for (auto neighbor : neighbors) {
		explore(neighbor[0], neighbor[1], board, node, visited, finalWords);
	}
	visited->at(i)[j] = false;
}
vector<vector<int>> getNeighbors(int i, int j, vector<vector<char>> board) {
	vector<vector<int>> neighbors;
	if (i > 0 && j > 0) {
		neighbors.push_back({ i - 1, j - 1 });
	}
	if (i > 0 && j < board[0].size() - 1) {
		neighbors.push_back({ i - 1, j + 1 });
	}
	if (i < board.size() -1 && j < board[0].size() -1) {
		neighbors.push_back({ i + 1, j + 1 });
	}
	if (i < board.size() - 1 && j > 0) {
		neighbors.push_back({ i + 1, j - 1 });
	}
	if (i > 0) {
		neighbors.push_back({ i - 1, j});
	}
	if (i < board.size() - 1) {
		neighbors.push_back({ i + 1, j});
	}
	if (j > 0) {
		neighbors.push_back({ i, j - 1 });
	}
	if (j < board[0].size() - 1) {
		neighbors.push_back({ i, j + 1 });
	}
	return neighbors;
}