#include <vector>
#include <iostream>
using namespace std;

vector<int> sortedSquaredArray(vector<int> &array) {
    // Write your code here.
    // O(nlogn)

    vector<int> new_array;
    bool negativeNum = false;
    new_array.reserve(array.size());

    for(int i = 0; i < array.size(); ++i) {
    
        if(array[i] < 0) {
            negativeNum = true;
        }
        new_array.push_back(array[i] * array[i]);
    }
    
    if(!negativeNum)
        return new_array;

    else {
        sort(new_array.begin(), new_array.end());
        return new_array;
    }
} // sortedSquaredArray

int main() {

    vector<int> array_in = {1, 2, 3, 5, 6, 8, 9};
    vector<int> array_out = sortedSquaredArray(array_in);
    
    cout << "{";
    for(int i = 0; i < array_out.size(); ++i) {
        cout << array_out[i];

        if(i < array_out.size() - 1)
            cout << ", ";
    }
    cout << "}";

} // main