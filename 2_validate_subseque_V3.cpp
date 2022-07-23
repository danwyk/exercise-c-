
#include <iostream>
#include <vector>
using namespace std;

bool isValidSubsequence(vector<int> array, vector<int> sequence) {
    // Write your code here.
    // O(n) more concise

    int sub_index = 0;
    int array_index = 0;

    // edge case handling 1
    if(sequence.size() > array.size())
        return false;
    
    while(array_index < array.size() && sub_index < sequence.size()) {
    
        if(array[array_index] == sequence[sub_index]) {
            sub_index++;
        }

        array_index++;
    } // while

    if(sub_index == sequence.size())
        return true;

    return false;
} // isValidSubsequence

int main() {
    vector<int> array1 = {1, 2, 3, 4};
    // vector<int> sequence1 = {1, 3, 2};
    // // vector<int> sequence1 = {2, 4};
    vector<int> sequence1 = {1, 2, 3, 4, 2};
    
    // vector<int> array2 = {5, 1, 22, 25, 6, -1, 8, 10};
    // vector<int> sequence2 = {1, 6, -1, 10};
    
    // vector<int> array3 = {5, 1, 22, 25, 6, -1, 8, 10};
    // vector<int> sequence3 = {5, 1, 22, 22, 25, 6, -1, 8, 10};
    
    // vector<int> array4 = {5, 1, 22, 25, 6, -1, 8, 10};
    // vector<int> sequence4 = {5, 1, 22, 25, 6, -1, 8, 10, 12};
    
    vector<int> array5 = {1, 1, 6, 1};
    vector<int> sequence5 = {1, 1, 1, 6};

    bool result = isValidSubsequence(array1, sequence1);

    if(result) 
        cout << "True" << endl;
    else
        cout << "False" << endl;

} // main
