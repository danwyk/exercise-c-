#include <vector>
#include <string>
#include <iostream>

using namespace std;

int binarySearch(vector<int> &array, int target) {
    // O(logn) Time
    // O(1) Space
    auto it_start = array.begin();
    auto it_end = --array.end();
    auto it_mid = it_start + (it_end - it_start) / 2;

    if(target <= *it_end || target >= *it_start) {

        while(it_start <= it_end) {
            if(target < *it_mid) {
                it_end = --it_mid;
            }
            else if(target > *it_mid) {
                it_start = ++it_mid;
            }
            else {
                return it_mid - array.begin();
            }
        } // while
        
    } // if

    return -1;
} // binarySearch 



int main() {
    // vector<int> array = {1, 3, 4, 7, 8};
    vector<int> array = {0, 1, 21, 33, 45, 45, 61, 71, 72, 73};

    // cout << "Index is: " << binarySearch(array, 8) << endl;
    cout << binarySearch(array, 0) << endl;

} // main
