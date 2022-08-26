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
    
    vector<char> encoded_string_char;
    int current_run_length = 1;

    encoded_string_char.reserve(2 * str.size());

    // The input string is guarenteed to be non-empty
    // so our first run will be of at least length 1
    for(int i = 1; i < str.size(); ++i) {
        char current_char = str[i];
        char previous_char = str[i - 1];

        cout << "Previous character: " << previous_char << "     Current character: " << current_char << endl;
        cout << "Current length: " << current_run_length << endl;

        // 如果length == 9 或者发现新的char, 都将之前的char和length一起加到string上
        if(current_char != previous_char || current_run_length == 9) {
            encoded_string_char.push_back(to_string(current_run_length)[0]);
            encoded_string_char.push_back(previous_char);
            current_run_length = 0;
        }

        // 如果current char == previous char, 继续++length, 直到stop point再加到string里面
        current_run_length++;
        cout << "After length: " << current_run_length << endl;
        cout << "--------------" << endl;
    } // for

    // 当指到最后一个char时, 加入的是second last char, 所以最后一个char没有加进去,
    // 手动加入最后一个char
    encoded_string_char.push_back(to_string(current_run_length)[0]);
    encoded_string_char.push_back(str[str.size() - 1 ]);

    string result(encoded_string_char.begin(), encoded_string_char.end());
    return result;
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
