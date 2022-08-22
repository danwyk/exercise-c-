#include <vector>
#include <string>
#include <iostream>

using namespace std;

vector<int> insertionSort(vector<int> array) {

    // Best: O(n) Time | O(1) Space
    // Average: O(n^2) Time | O(1) Space
    //  Worst: O(n^2) Time | O(1) Space

    if(array.empty()) {
        return {};
    }

    for(int i = 1; i < array.size(); ++i) { 

        int j = i;

        while(j > 0 && array[j] < array[j - 1]) {
            swap(array[j], array[j-1]);
            j--;
        } // while

    } // for

    return array;
} // insertionSort

int main() {

    vector<int> array = {8, 5, 2, 9, 5, 6, 3};

    cout << "Before: { ";
    for(auto &i:array) 
        cout << i << " ";
    cout << "}" << endl; 

    array = insertionSort(array);

    cout << "After: { ";
    for(auto &i:array) 
        cout << i << " ";
    cout << "}" << endl; 


} // main
