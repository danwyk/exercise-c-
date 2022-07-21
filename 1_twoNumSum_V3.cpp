#include <vector>
#include <iostream>
#include <unordered_map>
using namespace std;

vector<int> twoNumberSum(vector<int> array, int targetSum) {
  // Write your code here.
  // O(n)
 
  unordered_map<int, bool> seen;
  int targetLeft;

  for(int i = 0; i < array.size(); ++i) {

    targetLeft = targetSum - array[i];

    if(seen.find(targetLeft) == seen.end()) {
      seen[array[i]] = true;
    }
    else {
      return vector<int> {array[i], targetLeft};
    }
  } // for

  return {};
} // twoNumberSum


int main() {

    vector<int> vec_in = {3, 5, -4, 8, 11, 1, -1, 6};
    
    vector<int> result = twoNumberSum(vec_in, 10);
    for(auto &i : result) {
        cout << i << endl;
    }
    

}
