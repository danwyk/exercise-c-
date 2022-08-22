#include <vector>
#include <string>
#include <iostream>

using namespace std;

// vector<int> bubbleSort(vector<int> &array) {
void bubbleSort(vector<int> &array) {
    // Best: O(n) Time | O(1) Space, if the array is sorted
    // Average: O(n^2) Time | O(1) Space
    // Worst: O(n^2) Time | O(1) Space
    // 本身bubble sort就很蠢, 所以 worst case 也不会比 average 更差

    int num_swap = 1;
    int size = array.size();

    while(num_swap != 0) {

        cout << "------------- loop size: " << size << " --------------" << endl;

        num_swap = 0;
        for(int i = 0; i + 1 < size; ++i) {

            if(array[i] > array[i+1]) {
                swap(array[i], array[i+1]);
                cout << "Swap " << array[i] << " and " << array[i+1] << endl;
                num_swap++;
            }
          
        } // for

        size--;
    } // while

    cout << "After: { ";
    for(auto &i:array) 
        cout << i << " ";
    cout << " }" << endl;

    // return array;
} // bubbleSort

int main() {

    vector<int> array = {8, 5, 2, 9, 5, 6, 3};

    cout << "Before: { ";
    for(auto &i:array) 
        cout << i << " ";
    cout << " }" << endl; 

    bubbleSort(array);

} // main
