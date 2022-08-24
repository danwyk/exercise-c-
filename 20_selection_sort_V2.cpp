#include <vector>
#include <string>
#include <iostream>

using namespace std;

vector<int> selectionSort(vector<int> array) {
// void selectionSort(vector<int> &array) {

    // Best: O(n^2) Time | O(1) Space, 即使是sorted, 也需要完整走两层loop
    // Average: O(n^2) Time | O(1) Space
    // Worst: O(n^2) Time | O(1) Space

    int smallest_idx = 0;
    int start_idx = 0;
    const int SIZE = array.size();

    // 遍历到倒数第二位就可以, 最后一位自然就是最大的
    while(start_idx <= SIZE - 2) {

        for(int i = start_idx; i < SIZE; ++i) {

            if(array[i] < array[smallest_idx])
                smallest_idx = i;

        } // for

        // 避免自己和自己交换
        if(smallest_idx != start_idx)
            swap(array[start_idx], array[smallest_idx]);

        start_idx++;
        smallest_idx = start_idx;
    } // while


    // cout << "After: { ";
    // for(auto &i:array) 
    //     cout << i << " ";
    // cout << "}" << endl;


    return array;
} // selectionSort

int main() {

    vector<int> array = {8, 5, 2, 9, 5, 6, 3};
    // vector<int> array = {1, 3};

    cout << "Before: { ";
    for(auto &i:array) 
        cout << i << " ";
    cout << "}" << endl; 

    selectionSort(array);


} // main
