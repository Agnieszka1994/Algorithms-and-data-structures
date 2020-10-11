#include <vector>
using namespace std;
class TrieNode {
public:
    unordered_map<char, TrieNode*> children;
};

class SuffixTrie {
public:
    TrieNode* root;
    char endSymbol;

    SuffixTrie(string str) {
        this->root = new TrieNode();
        this->endSymbol = '*';
        this->populateSuffixTrieFrom(str);
    }

    void insertSubstring(int startIndex, string str) {
        TrieNode* currentNode = this->root;
        for (auto letter : str) {
            if (currentNode->children.find(letter) == currentNode->children.end()) {
                TrieNode* newNode = new TrieNode(); 
                currentNode->children.insert(pair<char, TrieNode*>(letter, newNode));
            }
            else {}
            currentNode = currentNode->children[letter];
        }
        currentNode->children.insert(pair<char, TrieNode*>(this->endSymbol, NULL));
    }

    void populateSuffixTrieFrom(string str) {

        for (int i = 0; i < str.length(); i++) {
            insertSubstring(i, str.substr(i, str.length() - i));

        }

    }

    bool contains(string str) {
        TrieNode* currentNode = this->root;
        for (auto letter : str) {
            if (currentNode->children.find(letter) == currentNode->children.end()) {
                return false;
            }
            else {
                currentNode = currentNode->children[letter];
            }
        }
        return true;
    }
};

vector<bool> multiStringSearch(string bigString, vector<string> smallStrings) {
    vector<bool> solution;
    unique_ptr<SuffixTrie> suffixTrie(new SuffixTrie(bigString));

    for (auto word : smallStrings) {
        solution.push_back(suffixTrie->contains(word));
    }
    return solution;
}