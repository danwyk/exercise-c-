#include <vector>
#include <string>
#include <iostream>

using namespace std;

bool classPhotos(vector<int> redShirtHeights, vector<int> blueShirtHeights) {
  // O(nlogn)
  bool redIsBack = false;

  sort(redShirtHeights.begin(), redShirtHeights.end());
  sort(blueShirtHeights.begin(), blueShirtHeights.end());

  if(redShirtHeights.back() == blueShirtHeights.back())
    return false;
  else if(redShirtHeights.back() > blueShirtHeights.back())
    redIsBack = true;

  for(int i = 0; i < redShirtHeights.size(); ++i) {
    if(redIsBack && redShirtHeights[i] <= blueShirtHeights[i])
      return false;
    else if(!redIsBack && blueShirtHeights[i] <= redShirtHeights[i])
      return false;

  } // for
  
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
