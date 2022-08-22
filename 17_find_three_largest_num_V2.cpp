#include <vector>
#include <string>
#include <iostream>

using namespace std;

vector<int> findThreeLargestNumbers(vector<int> &array) {
// void findThreeLargestNumbers(vector<int> &array) {

    // O(n) Time
    // O(1) Space
    // 不用pointer, 占用更少内存, 直接遍历整个array, 边遍历边更新

    const int DEFAULT = std::numeric_limits<int>::max();

    int large1 = -DEFAULT;
    int large2 = -DEFAULT;
    int large3 = -DEFAULT;

    for(int i = 0; i < array.size(); ++i) {

        if(array[i] > large1) {
            large3 = large2;
            large2 = large1; 
            large1 = array[i];
        }

        else if(array[i] > large2) {
            large3 = large2;
            large2 = array[i];
        }
        else if(array[i] > large3) {
            large3 = array[i];
        }

    } // for

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
