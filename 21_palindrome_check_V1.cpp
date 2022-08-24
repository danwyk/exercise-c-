#include <vector>
#include <string>
#include <iostream>

using namespace std;

bool isPalindrome(string &str) {
    
    // O(n) Time | O(1) Space
    // 双指针不重合, 同时比较 “左” 和 “右”
    
    int left = 0;
    int right = str.size() - 1;

    if(str.empty())
        return false;

    while(left < right) {

        // cout << "left: " << str[left] << "     right: " << str[right] << endl;

        if(str[left] != str[right])
            return false;
        
        left++;
        right--;
    } // while

    return true;
} //  isPalindrome

int main() {
    // string str = "";
    // string str = "a";
    // string str = "abc";
    // string str = "aba";
    // string str = "abba";
    string str = "abcba";

    isPalindrome(str) ? cout << "true\n" : cout << "false\n";
        
} // main
