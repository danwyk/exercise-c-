#include <any>
#include <vector>
#include <iostream>

using namespace std;

// Tip: You can use el.type() == typeid(vector<any>) to check whether an item is
// a list or an integer.
// If you know an element of the array is vector<any> you can cast it using:
//     any_cast<vector<any>>(element)
// If you know an element of the array is an int you can cast it using:
//     any_cast<int>(element)

int productSum(vector<any> array, int depth) {
    // O(n) Time, where n is the total number of element in the array, including sub-elements
    // O(d) Space, wehre d is the greatest depth of "Special Arrays" in the array

    int total_sum = 0;

    for(auto &i:array) {
        if(i.type() != typeid(vector<any>)) {
           total_sum += any_cast<int>(i);
        }

        else {
            total_sum += productSum(any_cast<vector<any>>(i), depth + 1);
        }

    } // for i
    
    return total_sum * depth;
} // productSum


int main() {
    vector<any> test = {5, 2, vector<any>{7, -1}, 3, vector<any>{6, vector<any>{-13, 8}, 4} };

    cout << "Product Sum is: " << productSum(test, 1) << endl;


} // main
