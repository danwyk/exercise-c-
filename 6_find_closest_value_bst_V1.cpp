#include <cmath>
#include <float.h>
using namespace std;

class BST {
    public:
        int value;
        BST *left;
        BST *right;

        BST (int val);
        BST &insert(int val);
};

int findclosestValueInBst(BST *tree, int target);
int findclosestValueInBstHelper (BST *tree, int target, int closest);


// Average: 0(log(n)) time| 0(1) space
// Worst: O(n) time | 0(1) space
int findclosestValueInBst (BST *tree, int target) {
    

}


int findclosestValueInBstHelper(BST *tree, int target, int closest) {
    

    
    return (int)closest;
}