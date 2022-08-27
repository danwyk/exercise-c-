#include <vector>
#include <string>
#include <unordered_map>
#include <iostream>

using namespace std;

bool generateDocument(string characters, string document) {
    
    // O(n + m) Time, where n is the # of characters, m is the length of document
    // O(c) Space, where c is the # of unique characters in the characters string
    
    unordered_map<char, int> table;

    if(document.empty())
        return true;

    // Hash every char into a table
    for(int i = 0; i < characters.size(); ++i) {

        if(table.find(characters[i]) != table.end()) {
            table[characters[i]] += 1;
        }
        else {
            table[characters[i]] = 1;
        }
    } // for

    // Find if the table contains the character
    for(int i = 0; i < document.size(); ++i) {

        if(table.find(document[i]) == table.end()) {
            return false;
        }

        else {
            // cout << "Before char: " << document[i] << " = " << table[characters[i]] << endl;
            table[document[i]] -= 1;
            // cout << "After char: " << document[i] << " = " << table[characters[i]] << endl;

            if(table[document[i]] < 0)
                return false;
        }

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