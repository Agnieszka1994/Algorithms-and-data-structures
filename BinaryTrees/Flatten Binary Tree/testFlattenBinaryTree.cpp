#include "pch.h"
#include "FlattenBinaryTree.cpp"
#include <vector>
#include <queue>

BinaryTree::BinaryTree(int value) { this->value = value; }

BinaryTree* insertBinaryTree(BinaryTree* tree, vector<int> values);
vector<int> leftToRightToLeft(BinaryTree* tree);

TEST(SampleTestCase, SampleTest) {
    BinaryTree* root = new BinaryTree(1);
    insertBinaryTree(root, { 2, 3, 4, 5, 6 });
    root->left->right->left = new BinaryTree(7);
    root->left->right->right = new BinaryTree(8);
    BinaryTree* leftMostNode = flattenBinaryTree(root);
    vector<int> actual = leftToRightToLeft(leftMostNode);
    vector<int> expected = { 4, 2, 7, 5, 8, 1, 6, 3, 3, 6, 1, 8, 5, 7, 2, 4 };
    assert(expected == actual);
}

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

vector<int> leftToRightToLeft(BinaryTree* tree) {
    vector<int> nodes = {};
    BinaryTree* current = tree;
    while (current->right != NULL) {
        nodes.push_back(current->value);
        current = current->right;
    }
    nodes.push_back(current->value);
    while (current != NULL) {
        nodes.push_back(current->value);
        current = current->left;
    }
    return nodes;
}
