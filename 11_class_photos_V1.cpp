#include <vector>
#include <string>
#include <iostream>

using namespace std;

bool classPhotos(vector<int> redShirtHeights, vector<int> blueShirtHeights) {
  // O(nlogn)

  const int SIZE = redShirtHeights.size();

  sort(redShirtHeights.begin(), redShirtHeights.end());
  sort(blueShirtHeights.begin(), blueShirtHeights.end());
  // cout << "Blue.back(): " << blueShirtHeights.back() << endl;
  // cout << "Red.back(): " << redShirtHeights.back() << endl;
  
  if(redShirtHeights.back() == blueShirtHeights.back())
    return false;
  
  // Red is back, Blue is front
  if(redShirtHeights.back() > blueShirtHeights.back()) {
    // cout << "Back Row is: red\n";

    for(int i = 0; i < SIZE; ++i) {

      if(redShirtHeights[i] <= blueShirtHeights[i])
        return false;

    } // for

  }
  
  // Blue is back, Red is front
  else if(blueShirtHeights.back() > redShirtHeights.back()) {
    // cout << "Back Row is: blue\n";

    for(int i = 0; i < SIZE; ++i) {

      if(blueShirtHeights[i] <= redShirtHeights[i])
        return false;

    } // for
  }
   
  return true;
} // classPhotos


int main() {
  // vector<int> redRow = {6, 9, 2, 4, 5}; // {9, 6, 5, 4, 2}
  // vector<int> blueRow = {5, 8, 1, 3, 4}; // {8, 5, 4, 3, 1}

  vector<int> redRow = {5, 8, 1, 3, 4}; // {8, 5, 4, 3, 1}
  vector<int> blueRow = {6, 9, 2, 4, 5}; // {9, 6, 5, 4, 2}

  if(classPhotos(redRow, blueRow) != 0) 
    cout << "True\n";
  else
    cout << "False\n";

} // main
