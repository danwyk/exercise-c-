#include <vector>
#include <string>
#include <cstring>
#include <unordered_map>
#include <iostream>
#include <any>

using namespace std;

string runLengthEncoding(string str) {

    // O(n) Time
    // O(n) Space, where n is the length of the input string

    string new_str;
    string temp_str;
    int length = 1;

    // The input string is guarenteed to be non-empty
    // so our first run will be of at least length 1
    for(int i = 1; i < str.size(); ++i) {

        cout << "Previous character: " << str[i-1] << "     Current character: " << str[i] << endl;
        cout << "Current length: " << length << endl;

        // 如果length == 9 或者发现新的char, 都将之前的char和length一起加到string上
        if(str[i - 1] != str[i] || length == 9) {
            temp_str = to_string(length) + str[i - 1];
            new_str += temp_str;
            length = 1;

            cout << "Add: " << temp_str << endl;
        }

        // 如果current char == previous char, 继续++length, 直到stop point再加到string里面
        else {
            length++;
        }
        cout << "After length: " << length << endl;
        cout << "--------------" << endl;
    } // for

    // 当指到最后一个char时, 加入的是second last char, 所以最后一个char没有加进去,
    // 手动加入最后一个char
    // 同时还可以处理, 整个string只有一个char的情况
    temp_str = to_string(length) + str[str.size() - 1];
    new_str += temp_str;

    cout << "Add last char: " << temp_str << endl;
    cout << "--------------" << endl;

    return new_str;
} // runLengthEncoding

int main() {

    // string str = "AAAAAAAAABBCCCCDD";
    string str = "AAAAAAAAAAAAABBCCCCDD";
    // string str = "ABBCCCCDDDDDDDDDD";
    // string str = "Aa";

    cout << "Before: " << str << endl;
    cout << "--------------" << endl;
    cout << runLengthEncoding(str) << endl;
    // cout << "After: " << runLengthEncoding(str) << endl;

} // main
