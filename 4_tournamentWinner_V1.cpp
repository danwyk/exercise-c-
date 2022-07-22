#include <vector>
#include <iostream>
#include <unordered_map>
using namespace std;

string tournamentWinner(vector<vector<string>> &competitions,
                        vector<int> &results) {
    // Write your code here.
    // O(n) T, n for # of competitions
    // O(k) S, k for # of teams

    unordered_map<string, int> table;
    const int homeIndex = 0;
    const int awayIndex = 1;
    string roundWinTeam; 
    int maxPoint = -1;
    string tournamentWinner;
    

    // hashing into table
    for(int i = 0; i < results.size(); ++i) {
       
        if(results[i] == 1) {
            roundWinTeam = competitions[i][homeIndex];
        }

        else {
            roundWinTeam = competitions[i][awayIndex];
        }

        if(table.find(roundWinTeam) != table.end()) {
            table[roundWinTeam] += 3;
        }
        else {
            table[roundWinTeam] = 1;
        }

    } // for

    // find the tournament winner
    for(auto &it : table) {
        if(it.second > maxPoint) {
            maxPoint = it.second;
            tournamentWinner = it.first;
        }
    } // for

    return tournamentWinner;
} // tournamentWinner

int main() {
    vector<vector<string>> competition = { {"HTML", "C#"}, 
                                           {"C#", "Python"},
                                           {"Python", "HTML"} };

    vector<int> result = {0, 0, 1};
    cout << tournamentWinner(competition, result) << endl;

} // main