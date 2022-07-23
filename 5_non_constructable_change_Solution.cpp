#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

// O(nlog(n)) T, where n is the # of coins
// O(1) S
int nonConstructibleChange(vector<int> coins) {
    sort(coins .begin(), coins.end());

    int currentChangeCreated = 0;
    for (int coin : coins) {

        if (coin > currentChangeCreated + 1)
            return currentChangeCreated + 1;

        currentChangeCreated += coin;
    }

    return currentChangeCreated + 1;
} // nonConstructibleChange

int main() {




} // main