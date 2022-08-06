#include <vector>
#include <iostream>
using namespace std;

vector<int> sortedSquaredArray(vector<int> &array) {
    // Write your code here.
    // O(n)
    // insert function插在前面,插完自动指向新插入的位置
    
    vector<int> new_array;
    new_array.reserve(array.size());

    int right_bound = array.size() - 1;
    int left_bound = 0;
    auto insert_it = new_array.end();

    while(left_bound <= right_bound) {

        // cout << "left bound: " << array[left_bound] << " right bound: " << array[right_bound] << endl;

        if(abs(array[left_bound]) > abs(array[right_bound])) {
            // cout << "Add " << array[left_bound] * array[left_bound] << endl;
            
            insert_it = new_array.insert(insert_it, array[left_bound] * array[left_bound]);
            left_bound++;
        }

        else {
            // cout << "Add " << array[right_bound] * array[right_bound] << endl;

            insert_it = new_array.insert(insert_it, array[right_bound] * array[right_bound]);
            right_bound--;
        }

        // cout << "{";
        // for(auto &item : new_array)
        //     cout << item << ", ";
        // cout << "}" << endl;

        // cout << "Now insert_it points to: " << *insert_it << endl;
        // cout << "-------------" << endl;

    } // while    
    
    // new_array.insert(insert_it, array[right_bound] * array[right_bound]);

    return new_array;
} // sortedSquaredArray

int main() {

    vector<int> array_in1 = {1, 2, 3, 5, 6, 8, 9};
    vector<int> array_in2 = {-4, -2, 1, 5};
    vector<int> array_out = sortedSquaredArray(array_in2);
    
    cout << "{";
    for(int i = 0; i < array_out.size(); ++i) {
        cout << array_out[i];

        if(i < array_out.size() - 1)
            cout << ", ";
    }
    cout << "}";

} // main