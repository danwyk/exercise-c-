#include <vector>
#include <string>
#include <iostream>

using namespace std;

vector<int> insertionSort(vector<int> array) {
// void insertionSort(vector<int> &array) {
    
    // Best: O(n) Time | O(1) Space
    // Average: O(n^2) Time | O(1) Space
    //  Worst: O(n^2) Time | O(1) Space

    for(int i = 1; i < array.size(); ++i) {

        for(int j = i; j - 1 >= 0; --j) {
            if(array[j] < array[j - 1])
                swap(array[j], array[j - 1]);
            else
                break;

        } // for

    } // for
  
    // cout << "After: { ";
    // for(auto &i:array) 
    //     cout << i << " ";
    // cout << "}" << endl;

  return array;
} // insertionSort

int main() {

    vector<int> array = {8, 5, 2, 9, 5, 6, 3};

    cout << "Before: { ";
    for(auto &i:array) 
        cout << i << " ";
    cout << "}" << endl; 

    insertionSort(array);


} // main
