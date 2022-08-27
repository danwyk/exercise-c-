#include <vector>
#include <string>
#include <unordered_map>
#include <utility>
#include <limits>
#include <iostream>

using namespace std;

int firstNonRepeatingCharacter(string str) {

    // O(n^2) TIme, n is the # of letters in the string
    // O(1) Space, 因为str只包含 lower letter, 所以不会超过26个, constant space
    unordered_map<char, int> table;
    int temp_idx;
    int target_idx = std::numeric_limits<int>::max();
    bool changed_target_idx = false;

    // Hash letters into the table
    for(auto &letter:str) {

        if(table.find(letter) == table.end()) {
            table[letter] = 1;
        }
        else {
            table[letter]++;
        }
    } // for

    // 在table里找到所有的 “distinctive” letter, 
    // 因为unordered_map不知道哪个最先写入, 
    // 所以要在所有 distinctive letter 里面找到index最小的
    for(auto &combo:table) {
        if(combo.second == 1) {
            // cout << combo.first << "   " << combo.second << endl;

            // O(n): 遍历str去找到对应的letter, 并记录其index
            temp_idx = str.find(combo.first);

            if(temp_idx < target_idx) { 
                target_idx = temp_idx;
                changed_target_idx = true;
            }
        
        }
    }
    
    // 如果根本就没有 “非重复” 的letter, 那我们初始的target_idx就不会改变, 就return -1
    if(!changed_target_idx)
        return -1;

    return target_idx;
} // firstNonRepeatingCharacter

int main() {
    // string str = "abcdcaf";
    string str = "abc";
    // string str = "aaaaa";
    // string str = "";
    // string str = "faadabcbbebdf";

    cout << firstNonRepeatingCharacter(str);
    // cout << "First non-repeating char is: " << str[firstNonRepeatingCharacter(str)]
    //     << " at index: " << firstNonRepeatingCharacter(str) << endl;

} // main
