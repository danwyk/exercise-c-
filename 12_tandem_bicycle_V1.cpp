#include <vector>
#include <string>
#include <iostream>

using namespace std;

void reverseVector(vector<int> &vec_in);

int tandemBicycle(vector<int> redShirtSpeeds, vector<int> blueShirtSpeeds,
                  bool fastest) {

    // O(nlong) Time
    // O(1) Space
    int total_speed = 0;

    if(redShirtSpeeds.empty() || blueShirtSpeeds.empty())
        return 0;

    // sort: samll -> large
    sort(redShirtSpeeds.begin(), redShirtSpeeds.end());
    sort(blueShirtSpeeds.begin(), blueShirtSpeeds.end());


    if(fastest) {
        // sort: large -> small
        reverseVector(redShirtSpeeds);

    } // if fastest

    for(int i = 0; i < redShirtSpeeds.size(); ++i) {
        total_speed += max(redShirtSpeeds[i], blueShirtSpeeds[i]);
    }
    
    return total_speed;
}; // tandemBicycle


void reverseVector(vector<int> &vec_in) {

    auto it_start = vec_in.begin();
    auto it_end = --vec_in.end();

    while(it_start < it_end) {
        swap(*it_start, *it_end);

        it_start++;
        it_end--;
        // cout << "it_start: " << *it_start << endl;
        // cout << "it_end: " << *it_end << endl;
    }

    // for(auto &i:vec_in)
    //     cout << i << " ";

}; // reverseVector

int main() {
    
    // vector<int> red = {1, 4, 7}; 
    // vector<int> blue = {3, 5, 3}; 
    // ----------------------------------
    // max speed = 4 + 5 = 9 
    // 大与小一组
    // (1, 5), (4, 3)

    // min speed = 3 + 5 = 8
    // 大与大一组
    // (1, 3), (4, 5)
    // ----------------------------------

    // vector<int> red = {5, 5, 3, 9, 2};
    // vector<int> blue = {3, 6, 7, 2, 1};

    // vector<int> red = {5, 5, 3, 9, 2};
    // vector<int> blue = {3, 6, 7, 2, 1};
    
    vector<int> red = {}; 
    vector<int> blue = {}; 

    cout << "Total Speed is: " << tandemBicycle(red, blue, false) << endl;

} // main
