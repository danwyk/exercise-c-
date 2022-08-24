#include <vector>
#include <string>
#include <iostream>

using namespace std;

vector<int> selectionSort(vector<int> array) {

    // Best: O(n^2) Time | O(1) Space
    // Average: O(n^2) Time | O(1) Space
    // Worst: O(n^2) Time | O(1) Space

    int smallest_idx = 0;
    int sub_size = 0;
    const int SIZE = array.size();

    while(sub_size <= SIZE - 1) {


        if(array.empty())
            return {};
        
        int start_idx = 0;

        while(start_idx < array.size() - 1 ) {
            int smallest_idx = start_idx;

            for(int i = smallest_idx + 1; i < array.size(); ++i) {
                if(array[smallest_idx] > array[i])
                    smallest_idx = i;

            } // for
            swap(array[start_idx], array[smallest_idx]);
            start_idx++;
        } // while

    } // while
  
  return array;
} // selectionSort

int main() {

    vector<int> array = {8, 5, 2, 9, 5, 6, 3};
    // vector<int> array = {1, 3};

    cout << "Before: { ";
    for(auto &i:array)
        cout << i << " ";
    cout << "}" << endl;

    array = selectionSort(array);

    cout << "After: { ";
    for(auto &i:array)
        cout << i << " ";
    cout << "}" << endl;

} // main
