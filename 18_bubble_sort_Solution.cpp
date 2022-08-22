#include <vector>
#include <string>
#include <iostream>

using namespace std;

vector<int> bubbleSort(vector<int> array) {
    // Best: O(n) Time | O(1) Space, if the array is sorted
    // Average: O(n^2) Time | O(1) Space
    // Worst: O(n^2) Time | O(1) Space
    // 本身bubble sort就很蠢, 所以 worst case 也不会比 average 更差

    if(array.empty())
        return {};
    
    bool isSorted = false;
    int counter = 0;

    while(!isSorted) {
        isSorted = true;

        for(int i = 0; i + 1 < array.size() - counter; i++) {
            if(array[i] > array[i+1]) {
                swap(array[i], array[i+1]);
                isSorted = false;
            }
        } // for
        
        counter++;
    } // while

    return array;
} // bubbleSort

int main() {

    vector<int> array = {8, 5, 2, 9, 5, 6, 3};

    cout << "Before: { ";
    for(auto &i:array) 
        cout << i << " ";
    cout << " }" << endl; 

    array = bubbleSort(array);

    cout << "After: { ";
    for(auto &i:array) 
        cout << i << " ";
    cout << " }" << endl; 

} // main
