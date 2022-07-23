#include <vector>
#include <iostream>
#include <map>
using namespace std;

vector<int> twoNumberSum(vector<int> array, int targetSum) {
  // Write your code here.
  // O(nlogn)

  sort(array.begin(), array.end());

  auto left_bound = array.begin();
  auto right_bound = --array.end();
  // cout << *right_bound;

  while(left_bound != right_bound) {

    if(*left_bound + *right_bound < targetSum) {
      left_bound++;
    }
    else if(*left_bound + *right_bound > targetSum) {
      right_bound--;
    }
    else {
      // cout << *left_bound << " " << *right_bound << endl;
      return vector<int> {*left_bound, *right_bound};
    }
  } // while

  return {};
}


int main() {

    vector<int> vec_in = {3, 5, -4, 8, 11, 1, -1, 6};
    
    vector<int> result = twoNumberSum(vec_in, 10);
    for(auto &i : result) {
        cout << i << endl;
    }
    

}
