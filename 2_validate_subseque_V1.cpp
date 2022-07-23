
#include <iostream>
#include <vector>
using namespace std;

bool isValidSubsequence(vector<int> array, vector<int> sequence) {
    // Write your code here.
    // O(n^2)

    int startIndex = -1;
    bool tempResult = false;

    // edge case handling 1
    if(sequence.size() > array.size())
        return false;


    // find the starting indesx
    for(int i = 0; i < array.size(); ++i) {

        if(array[i] == sequence[0]) {
            startIndex = i + 1;
            break;
        } // if

    } // for


    // edge case handling 2
    if(startIndex == -1)
        return false;

    for(int i = 1; i < sequence.size(); ++i) {
        
        for(int j = startIndex; j < array.size(); ++j) {
            
            if(sequence[i] == array[j]) {
                tempResult = true;
                startIndex = j + 1;
                break;
            } // if

            tempResult = false;
        } // for

        if(startIndex == array.size() && ++i < sequence.size())
            return false;

        if(!tempResult)
            return false;
        
    } // for

    return true;
} // isValidSubsequence

int main() {
    vector<int> array1 = {1, 2, 3, 4};
    vector<int> sequence1 = {1, 3, 4};
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

    bool result = isValidSubsequence(array1, sequence1);

    if(result) 
        cout << "True" << endl;
    else
        cout << "False" << endl;

} // main
