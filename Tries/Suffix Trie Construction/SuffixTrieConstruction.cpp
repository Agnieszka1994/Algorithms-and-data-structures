#include <unordered_map>
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
            else {}//do nothing
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
        return currentNode->children.find(this->endSymbol) != currentNode->children.end();
    }
};