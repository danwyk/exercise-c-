#include <vector>

using namespace std;

class BinaryTree {
    public:
        int value;
        BinaryTree *left;
        BinaryTree *right;

        BinaryTree(int value) {
            this->value = value;
            left = nullptr;
            right = nullptr;
        }
};


void calculateBranchSums(BinaryTree *node, int runningSum, vector<int> &sums);

// O(n) time | O(n) space, where n is the numver of nodes in the Binary Tree
vector<int> branchSums(BinaryTree *root) {
    vector<int> sums;
    calculateBranchSums(root, 0, sums);
    return sums;
}


void alculateBranchSums(BinaryTree *node, int runningSum, vector<int> &sums) {
    if(node == nullptr)
        return;
    int newRunningSum = runningSum + node->value;
    if(node->left == nullptr && node->right == nullptr) {
        sums.push_back(newRunningSum);
        return;
    }

    calculateBranchSums(node->left, newRunningSum, sums);
    calculateBranchSums(node->right, newRunningSum, sums);
}