#include <vector>
#include <string>
#include <iostream>

using namespace std;

vector<int> findThreeLargestNumbers(vector<int> &array) {
// void findThreeLargestNumbers(vector<int> &array) {

    // O(n) Time
    // O(1) Space
    // 双指针, 一左一右, 同时比较2个数, 交替更新3个large, 
    int left = 0;
    int right = array.size() - 1;

    const int DEFAULT = std::numeric_limits<int>::max();

    int large1 = -DEFAULT;
    int large2 = -DEFAULT;
    int large3 = -DEFAULT;

    while(left <= right) {

        // Find candidate for large1
        if(large1 < max(array[left], array[right])) {

            // Update large2 and large3
            if(large1 > min(array[left], array[right])) {
                large2 =  large1;
                large3 = min(array[left], array[right]);
            }
            else {
                large2 = min(array[left], array[right]);
                large3 = large1;
            }

            // Update large1
            large1 = max(array[left], array[right]);
        }

        // Find candidate for large2
        else if(large2 < max(array[left], array[right])) {
            
            // Update large3
            if(large2 > min(array[left], array[right])) {
                large3 = large2;
            }
            else {
                large3 = min(array[left], array[right]);
            }

            // Update large2
            large2 = max(array[left], array[right]);
        }

        // Find candidate for large3
        else if(large3 < max(array[left], array[right])){
            // Update large3
            large3 = max(array[left], array[right]);
        }
        
        // cout << "large1: " << large1 << endl;
        // cout << "large2: " << large2 << endl;
        // cout << "large3: " << large3 << endl;
        // cout << "----------------" << endl;

        left++;
        right--;

    } // while


    return {large3, large2, large1};
} // findThreeLargestNumbers

int main() {
    // vector<int> array = {10, 5, 9, 10, 12};
    // vector<int> array = {141, 1, 17, -7, -17, -27, 18, 541, 8, 7, 7};
    vector<int> array = {-1, -2, -3, -7, -17, -27, -18, -541, -8, -7, 7};
    vector<int> result = findThreeLargestNumbers(array);
    // findThreeLargestNumbers(array);

    cout << "{ ";
    for(auto &i:result)
        cout << i << " ";
    cout << "}";

} // main
