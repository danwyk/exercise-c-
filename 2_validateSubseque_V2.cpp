
#include <iostream>
#include <vector>
using namespace std;

bool isValidSubsequence(vector<int> array, vector<int> sequence) {
    // Write your code here.
    // O(n)

    auto sub_it = sequence.begin();
    auto array_it = array.begin();
    int match = 0;

    // edge case handling 1
    if(sequence.size() > array.size())
        return false;
    
    
    while(array_it != array.end()) {

        if(sub_it == sequence.end()) {
            // log
            // cout << "Reach the end of subsequence" << endl;
            break;
        }
        
        // log
        // cout << "num in array: " << *array_it << endl;
        // cout << "num in subsequence: " << *sub_it << endl;

        if(*array_it == *sub_it) {
            // log
            // cout << "Matched!" << endl;

            array_it++;
            sub_it++;
            match++;
        }

        else {
            array_it++;
        }

        // log
        // cout << "---------------" << endl;

    } // while

    // log
    // cout << "Reach the end of array" << endl;
    // cout << "Match: " << match << endl;

    if(match == sequence.size())
        return true;

    return false;
} // isValidSubsequence

int main() {
    vector<int> array1 = {1, 2, 3, 4};
    vector<int> sequence1 = {1, 3, 2};
    // // vector<int> sequence2 = {2, 4};
    // // vector<int> sequence2 = {1, 3, 4, 2};
    
    // vector<int> array2 = {5, 1, 22, 25, 6, -1, 8, 10};
    // vector<int> sequence2 = {1, 6, -1, 10};
    
    // vector<int> array3 = {5, 1, 22, 25, 6, -1, 8, 10};
    // vector<int> sequence3 = {5, 1, 22, 22, 25, 6, -1, 8, 10};
    
    // vector<int> array4 = {5, 1, 22, 25, 6, -1, 8, 10};
    // vector<int> sequence4 = {5, 1, 22, 25, 6, -1, 8, 10, 12};
    
    vector<int> array5 = {1, 1, 6, 1};
    vector<int> sequence5 = {1, 1, 1, 6};

    bool result = isValidSubsequence(array5, sequence5);

    if(result) 
        cout << "True" << endl;
    else
        cout << "False" << endl;

} // main
