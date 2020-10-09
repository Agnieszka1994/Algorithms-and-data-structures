#include "pch.h"
#include "BranchSums.cpp"
#include <vector>

class TestBinaryTree : public BinaryTree {
public:
    TestBinaryTree(int value) : BinaryTree(value) {};

    BinaryTree* insert(vector<int> values, int i = 0) {
        if (i >= values.size())
            return NULL;
        vector<BinaryTree*> queue = { this };
        while (queue.size() > 0) {
            BinaryTree* current = queue[0];
            queue.erase(queue.begin());
            if (current->left == NULL) {
                current->left = new BinaryTree(values[i]);
                break;
            }
            queue.push_back(current->left);
            if (current->right == NULL) {
                current->right = new BinaryTree(values[i]);
                break;
            }
            queue.push_back(current->right);
        }
        insert(values, i + 1);
        return this;
    }
};

TEST(SampleTestCase, SampleTest) {
    TestBinaryTree* tree = new TestBinaryTree(1);
    tree->insert({ 2, 3, 4, 5, 6, 7, 8, 9, 10 });
    vector<int> expected = { 15, 16, 18, 10, 11 };
    assert(branchSums(tree) == expected);
}

