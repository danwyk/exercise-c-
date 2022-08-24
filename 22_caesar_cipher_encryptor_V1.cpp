#include <vector>
#include <string>
#include <cstring>
#include <unordered_map>
#include <iostream>

using namespace std;

string caesarCypherEncryptor(string str, int key) {

    // O(n) Time
    // O(1) Space, 直接重新写入str

    const int SIZE = str.length();

    key = key % 26;

    for(int i = 0; i < SIZE ; ++i) {

        str[i] = 'a' + (str[i] - 'a' + key) % 26;
    }

    return str;
} // caesarCypherEncryptor

int main() {
    string str = "zab"; // abc

    cout << "Before: " << str << endl;
    cout << "After: " << caesarCypherEncryptor(str, 1) << endl;

} // main