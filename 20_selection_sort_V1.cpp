#include <vector>
#include <string>
#include <iostream>

using namespace std;

// vector<int> selectionSort(vector<int> array) {
void selectionSort(vector<int> &array) {

    // Best: O(n^2) Time | O(1) Space
    // Average: O(n^2) Time | O(1) Space
    // Worst: O(n^2) Time | O(1) Space

    int smallest_idx = 0;
    int sub_size = 0;
    const int SIZE = array.size();

    while(sub_size <= SIZE - 1) {

        // find the smallest number
        for(int i = sub_size; i < SIZE; ++i) {
            // cout << "i = " << i << endl;
            // cout << "array[i]: " << array[i] << "     array[smallest_idx]: " << array[smallest_idx] << endl;

            if(array[i] < array[smallest_idx]) {
                smallest_idx = i;
                // cout << "New smallest: " << array[smallest_idx] << endl;
            }

        } // for

        // cout << "sub_size = " << sub_size << endl;
        // cout << "smallest_idx = " << smallest_idx << endl;

        if(smallest_idx != sub_size) {
            swap(array[sub_size], array[smallest_idx]);
            // cout << "Swap: " << array[sub_size] << " and " << array[smallest_idx] << endl;
        }

        // cout << "-----------------------" << endl;
        sub_size++;
        smallest_idx = sub_size;
    } // while

    cout << "After: { ";
    for(auto &i:array) 
        cout << i << " ";
    cout << "}" << endl;


//   return array;
} // selectionSort

int main() {

    // vector<int> array = {8, 5, 2, 9, 5, 6, 3};
    vector<int> array = {1, 3};

    cout << "Before: { ";
    for(auto &i:array) 
        cout << i << " ";
    cout << "}" << endl; 

    selectionSort(array);


} // main
