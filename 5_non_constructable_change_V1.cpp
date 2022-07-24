#include <vector>
#include <algorithm>
#include <iostream>a

using namespace std;

// O(nlogn) Time, where n is the length of the coins
// O(1) Space
int nonConstructibleChange(vector<int> coins) {

    int maxChange = 0;
    sort(coins.begin(), coins.end());

    // if(coins.front() > 1) {
    //     maxChange = 1;
    //     return maxChange;
    // } 

    for(int i = 0; i < coins.size(); ++i) {

        if(coins[i] <= maxChange + 1) {
            maxChange += coins[i];
        }
        else {
            return maxChange + 1;
        }

    } // for

    return maxChange + 1;
} // nonConstructibleChange