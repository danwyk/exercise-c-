#include <vector>
#include <string>
#include <cstring>
#include <unordered_map>
#include <iostream>

using namespace std;

string caesarCypherEncryptor(string str, int key) {

    // O(n) Time
    // O(n) Space, 存到新的vector里面, 再转成string

    vector<char> new_str;
    string alphabet = "abcdefghijklmnopqrstuvwxyz";
    int newKey = key % 26;
    int new_letter_idx;


    for(int i = 0; i < str.length(); ++i) {
        new_letter_idx = (alphabet.find(str[i]) + key) % 26;
        new_str.push_back(alphabet[new_letter_idx]);
    }

    return string(new_str.begin(), new_str.end());
} // caesarCypherEncryptor


int main() {
    string str = "zab"; // abc

    cout << "Before: " << str << endl;

    cout << "After: " << caesarCypherEncryptor(str, 1) << endl;

} // main