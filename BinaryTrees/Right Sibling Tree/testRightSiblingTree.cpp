#include "pch.h"
#include "RightSiblingTree.cpp"
#include <queue>

BinaryTree::BinaryTree(int value) { this->value = value; }

BinaryTree* insertBinaryTree(BinaryTree* tree, vector<int> values);
vector<int> getDfsOrder(BinaryTree* tree);

TEST(SampleTestCase, SampleTest) {
    BinaryTree* root = new BinaryTree(1);
    insertBinaryTree(root, { 2, 3, 4, 5, 6, 7, 8, 9 });
    root->left->right->right = new BinaryTree(10);
    root->right->left->left = new BinaryTree(11);
    root->right->right->left = new BinaryTree(12);
    root->right->right->right = new BinaryTree(13);
    root->right->left->left->left = new BinaryTree(14);
    BinaryTree* mutatedRoot = rightSiblingTree(root);
    vector<int> actual = getDfsOrder(mutatedRoot);
    vector<int> expected = { 1,  2,  4, 8, 9,  5,  6, 11, 14, 7,
                                12, 13, 3, 6, 11, 14, 7, 12, 13 };
    assert(expected == actual);  
};

BinaryTree* insertBinaryTree(BinaryTree* tree, vector<int> values) {
    if (values.size() == 0)
        return tree;

    queue<BinaryTree*> nodesQueue({ tree });
    while (nodesQueue.size() > 0) {
        BinaryTree* current = nodesQueue.front();
        nodesQueue.pop();
        if (current->left == NULL) {
            current->left = new BinaryTree(values[0]);
            break;
        }
        nodesQueue.push(current->left);
        if (current->right == NULL) {
            current->right = new BinaryTree(values[0]);
            break;
        }
        nodesQueue.push(current->right);
    }
    values.erase(values.begin());
    return insertBinaryTree(tree, values);
}

vector<int> getDfsOrder(BinaryTree* tree) {
    vector<int> values = { tree->value };
    if (tree->left != NULL) {
        auto sub = getDfsOrder(tree->left);
        values.insert(values.end(), sub.begin(), sub.end());
    }
    if (tree->right != NULL) {
        auto sub = getDfsOrder(tree->right);
        values.insert(values.end(), sub.begin(), sub.end());
    }
    return values;
}