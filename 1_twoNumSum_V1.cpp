#include <vector>
#include <iostream>
using namespace std;

vector<int> twoNumberSum(vector<int> array, int targetSum) {
  // Write your code here.
  // O(n^2)

  int targetLeft;
  vector<int> result;
  bool timeToBreak = false;

  for(int i = 0; i < array.size(); ++i) {
    
    targetLeft = targetSum - array[i];

    // log
    cout << "Now it's " << array[i] << endl;
    cout << "Target Left is " << targetLeft << endl;

    for(int j = 0; j < array.size(); ++j) {
      
        if(array[i] == array[j]) {
        continue;
        }

        else if(array[j] == targetLeft) {
            cout << "Find it!" << endl;

            result.push_back(array[i]);
            result.push_back(array[j]);
            timeToBreak = true;
            break;
        }
    } // for
    
    if(timeToBreak) {
      break;
    }
    
  } // for
  
  return result;
}


int main() {

    vector<int> vec_in = {3, 5, -4, 8, 11, 1, -1, 6};
    
    vector<int> result = twoNumberSum(vec_in, 10);
    for(auto &i : result) {
        cout << i << endl;
    }
    

}
