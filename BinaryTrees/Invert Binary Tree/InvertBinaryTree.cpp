#include <vector>
#include <queue>
using namespace std;

class BinaryTree {
public:
    int value;
    BinaryTree* left;
    BinaryTree* right;

    BinaryTree(int value);
    void insert(vector<int> values, int i = 0);
    void invertedInsert(vector<int> values, int i = 0);
};
void swapChildNodes(BinaryTree* tree);

void invertBinaryTree(BinaryTree* tree) {
    queue< BinaryTree*> toBeTraversed;
    toBeTraversed.push(tree);
    BinaryTree* current = nullptr;
    while (!toBeTraversed.empty())
    {
        current = toBeTraversed.front();
        toBeTraversed.pop();
        if (current == NULL) continue;
        swapChildNodes(current);
        toBeTraversed.push(current->left);
        toBeTraversed.push(current->right);
    }
}

void swapChildNodes(BinaryTree* tree) {
    BinaryTree* buffer = tree->left;
    tree->left = tree->right;
    tree->right = buffer;
}