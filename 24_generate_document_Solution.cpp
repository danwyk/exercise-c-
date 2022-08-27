#include <vector>
#include <string>
#include <unordered_map>
#include <iostream>

using namespace std;

// Solution
bool generateDocument(string characters, string document) {
    
    // O(n + m) Time, where n is the # of characters, m is the length of document
    // O(c) Space, where c is the # of unique characters in the characters string
    
    unordered_map<char, int> table;

    // Hash every char into a table
    for(auto &i:characters) {
        if(table.find(i) == table.end())
            table[i] = 0;

        table[i]++;
    } // for
    
    // Find if the table contains the character
    for(auto &i:document) {
        if(table.find(i) == table.end() || table[i] == 0) {
            return false;
        }

        table[i]--;
    } // for

    return true;
} // generateDocument

int main() {
    // string characters = "Bste!hetsi ogEAxpelrt x ";
    // string document = "AlfoExpert is the Best!";

    // string characters = "abcabc";
    // string document = "aabbccc";

    string characters = "A";
    string document = "a";

    generateDocument(characters, document) ? cout << "True\n" : cout << "False\n";

} // main