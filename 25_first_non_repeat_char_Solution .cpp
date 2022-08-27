#include <vector>
#include <string>
#include <unordered_map>
#include <iostream>

using namespace std;

// Solution
int firstNonRepeatingCharacter(string string) {

    // O(n) Time, where n is the length of the input string
    // O(1) Space, the constant space is because 
    // the input string only has lowercase English-alphabet letters; 
    // Thus, our hash table will never have more than 25 character frequencies.

    unordered_map<char, int> table;

    // Hash every letter of the string into a table
    for(auto &character : string) {
        if(table.find(character) == table.end()) {
            table[character] = 0;
        }

        table[character]++;
    } // for

    // 直接遍历 string 里面每个 letter, 看 table 里面这个 letter 的频率是否为 1,
    // 因为是按照 string 里面 letter 出现的顺序, 所以只要找到频率为 1, 就可以直接 return
    for(int idx = 0; idx < string.size(); ++idx) {
        char character = string[idx];

        if(table[character] == 1)
            return idx;

    } // for
    
    return -1;
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
