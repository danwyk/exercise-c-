#include <iostream>
#include <queue>

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

struct Depth {
  BinaryTree *node;
  int depth;
};

int nodeDepths(BinaryTree *root) {

  // Time: O(n) 遍历tree里面所有node, 找到depth sum
  // Space: O(h), where h is the height of the tree, 每次stack会先跑完node->left, stack堆积的总数为height
  
  int depthSum = 0;
  Depth *currentOne;
  queue<Depth> candidate;

  candidate.push({root, 0});

  // Breadth First Search
  while(!candidate.empty()) {

    // Setup the current node
    currentOne = &candidate.front();
    candidate.pop();
    depthSum += currentOne->depth;

  
    if(currentOne->node->left)
      candidate.push({currentOne->node->left, currentOne->depth + 1});

    if(currentOne->node->right)
      candidate.push({currentOne->node->right, currentOne->depth + 1});

  } // while
 
  return depthSum;
}; // nodeDepths
