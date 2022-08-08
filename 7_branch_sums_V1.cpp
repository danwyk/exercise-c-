#include <vector>
#include <iostream>

using namespace std;

// This is the class of the input root. Do not edit it.
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

void Helper(BinaryTree *root, int currentSum, vector<int> &sumList);

vector<int> branchSums(BinaryTree *root) {
    // Write your code here.
    // O(n) time | O(n) space, where n is the numver of nodes in the Binary Tree
    
    vector<int> sumList;

    Helper(root, 0, sumList);
    return sumList;
}

// Depth First Search
void Helper(BinaryTree *root, int currentSum, vector<int> &sumList) {

    currentSum += root->value;

    if(!root->left && !root->right) {
        sumList.push_back(currentSum);
        return;
    }

    if(root->left)
      Helper(root->left, currentSum, sumList);
    if(root->right)
      Helper(root->right, currentSum, sumList);
}
