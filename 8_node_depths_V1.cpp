#include <iostream>

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


int Helper(BinaryTree *node, int dpeth);

int nodeDepths(BinaryTree *root) {
  // Time: O(n) 遍历tree里面所有node, 找到depth sum
  // Space: O(h), where h is the height of the tree, 每次stack会先跑完node->left, stack堆积的总数为height
  
  return Helper(root, 0);
} // nodeDepths


int Helper(BinaryTree *node, int depth) {
  
  // base case 
  if(!node)
    return 0;

  return depth + Helper(node->left, depth + 1) + Helper(node->right, depth + 1);
} // Helper