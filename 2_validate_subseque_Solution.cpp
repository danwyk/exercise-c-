#include <vector>
#include <iostream>

using namespace std;

// O(n) time, where n is the length of the array
// O(1) space

bool isValidSubsequence(vector<int> array, vector<int> sequence) {
    int arrIdx = 0;
    int seqIdx = 0;

    while(arrIdx < array.size() && seqIdx < sequence.size()) {
        if(array[arrIdx] == sequence[seqIdx])
            seqIdx++;

        arrIdx++;
    } // while

    return seqIdx == sequence.size();
} // isValidSubsequence