#include <vector>
#include <unordered_set>

using namespace std;
// 0(n) time 
// 0(n) space

vector<int> twoNumberSum(vector<int> array, int targetSum) {
    unordered_set<int> nums;
    
    for (int num : array) {
        int potentialMatch = targetSum - num;

        if(nums.find(potentialMatch) != nums.end()) {
            return vector<int> {potentialMatch, num};
        }
        else {
            nums. insert (num) ;
        }
    } // for

    return {};
} // twoNumberSum