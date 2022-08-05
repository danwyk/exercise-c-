#include <cmath>
#include <float.h>

using namespace std;

class BST {
  public:
    int value;
    BST *left;
    BST *right;

    BST(int val);
    BST &insert(int val);
};

int Helper(BST *tree, int target, int closet);
int findClosestValueInBst(BST *tree, int target);

int findClosestValueInBst(BST *tree, int target) {
    // Write your code here.
    return Helper(tree, target, tree->value);
};

int Helper(BST *tree, int target, int closet) {
    // Time: O(logn) average
  // Time O(n) worse case
  // Space: O(1) average
  // Space: O(1) worse case
  // iterative solution, 不占用额外的stack

  BST *currentNode = tree;

  while(currentNode) {

    // update closet node value
    if(abs(currentNode->value - target) < abs(closet - target)) {
      closet = currentNode->value;
    }

    // if target == current node value
    if(target == currentNode->value) {
      closet = currentNode->value;
      break;
    }

    // if target < current node value, go left
    else if(target < currentNode->value && currentNode->left) {
      currentNode = currentNode->left;
      continue;
    }

    // if target > current node value, go right
    else if(target > currentNode->value && currentNode->right) {
      currentNode = currentNode->right;
      continue;
    }

    break;
  } // while

  return closet;  
};