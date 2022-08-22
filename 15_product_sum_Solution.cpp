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

// template<class any>
int productSum(vector<any> array, int depth = 1) {
     // O(n) Time, where n is the total number of element in the array, including sub-elements
    // O(d) Space, wehre d is the greatest depth of "Special Arrays" in the array

    int sum = 0;

    for(auto element:array) {
        if(element.type() == typeid(vector<any>)) {
            sum += productSum(any_cast<vector<any>>(element), depth + 1);
        }
        
        else {
            sum += any_cast<int>(element);
        }

    } // for
    
    return sum * depth;
} // productSum

int main() {
    vector<any> test = {5, 2, vector<any>{7, -1}, 3, vector<any>{6, vector<any>{-13, 8}, 4} };

    cout << "Product Sum is: " << productSum(test, 1) << endl;


} // main
