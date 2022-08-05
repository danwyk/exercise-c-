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
    // Space: O(logn) average
    // Space: O(n) worse case
    // tree recursion不是tail recursion会不断stack

    // update the closet node value
    if(abs(tree->value - target) < abs(closet - target)) {
        closet = tree->value;
    }

    // if target == current node value
    if(target == closet) {
        return closet;
    }

    // if target > current node value, go right
    if(target > tree->value && tree->right) {
        return Helper(tree->right, target, closet);
    }

    // if target < current node value, go left
    else if(target < tree->value && tree->left) {
        return Helper(tree->left, target, closet);
    } // else if

    return closet;  
};