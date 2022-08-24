#include <vector>
#include <string>
#include <iostream>

using namespace std;

bool isPalindrome(string &str) {
    
    // O(n) Time | O(1) Space

    int left = 0;
    int right = str.size() - 1;

    while(left < right) {

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
