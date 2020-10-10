using namespace std;

class BST {
public:
    int value;
    BST* left;
    BST* right;

    BST(int value) {
        this->value = value;
        left = NULL;
        right = NULL;
    }

    void insert(int value) {
        if (value < this->value) {
            if (left == NULL) {
                left = new BST(value);
            }
            else {
                left->insert(value);
            }
        }
        else {
            if (right == NULL) {
                right = new BST(value);
            }
            else {
                right->insert(value);
            }
        }
    }
};
BST* constructBST(vector<int> array, int left, int right, BST* rootnode);

BST* minHeightBst(vector<int> array) {
    return constructBST(array, 0, array.size() - 1, nullptr);
}

BST* constructBST(vector<int> array, int left, int right, BST* rootnode) {
    if (left > right) return nullptr;

    int middle = (left + right) / 2;

    if (rootnode == nullptr) {
        rootnode = new BST(array[middle]);
    }
    else {
        rootnode->insert(array[middle]);
    }
    constructBST(array, left, middle - 1, rootnode);
    constructBST(array, middle + 1, right, rootnode);
    return rootnode;
}