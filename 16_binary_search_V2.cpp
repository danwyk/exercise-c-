#include <vector>
#include <string>
#include <iostream>

using namespace std;

int binarySearch(vector<int> &array, int target) {
    // O(logn) Time
    // O(1) Space
    int start = 0;
    int end = array.size() - 1;
    int mid= (end + start) / 2;


    if(target >= array[start] || target <= array[end]) {
        
        while(start <= end) {
            if(target < array[mid]) {
                end = --mid;
            }
            else if(target > array[mid]) {
                start = ++mid;
            }
            else {
                return mid;
            }
        } // while

    } // if

    return -1;
} // binarySearch

int main() {
    vector<int> array = {1, 3, 4, 7, 8};

    // cout << "Index is: " << binarySearch(array, 8) << endl;
    cout << binarySearch(array, 8) << endl;

} // main
