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
    string winnerSoFar;
    

    // hashing into table
    for(int i = 0; i < results.size(); ++i) {
       
        // find the winner per round
        if(results[i] == 1) {
            roundWinTeam = competitions[i][homeIndex];
        }
        else {
            roundWinTeam = competitions[i][awayIndex];
        }


        table[roundWinTeam] += 3;
  

        // update winner so far
        if(table[roundWinTeam] > maxPoint) {
            maxPoint = table[roundWinTeam];
            winnerSoFar = roundWinTeam;
        }
    } // for

    return winnerSoFar;
} // tournamentWinner

int main() {
    vector<vector<string>> competition = { {"HTML", "C#"}, 
                                           {"C#", "Python"},
                                           {"Python", "HTML"} };

    vector<int> result = {0, 0, 1};
    cout << tournamentWinner(competition, result) << endl;

} // main