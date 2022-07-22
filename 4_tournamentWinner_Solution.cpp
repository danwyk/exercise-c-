#include <vector>
#include <unordered_map>
#include <iostream>

using namespace std;


const int HOME_TEAM_WON = 1;
void updateScores (string team, int points, unordered_map<string, int> &scores);
// O(n) time O(k) space where n is the number
// of competitions and k is the number of teams

string tournamentWinner(vector<vector<string>> competitions,
                        vector<int> results) {

    string currentBestTeam = "";
    unordered_map<string, int> scores = {{currentBestTeam, 0}};

    vector<string> currentRound; 
    string homeTeam;
    string awayTeam;
    string winningTeam;
    int result;

    for (int idx = 0; idx < competitions.size(); idx++) {
        result = results[idx];
        currentRound = competitions[idx];
        homeTeam = currentRound[0];
        awayTeam = currentRound[1];
            
        if(result == HOME_TEAM_WON)
            winningTeam = homeTeam;
        else
            winningTeam = awayTeam;

        updateScores (winningTeam, 3, scores) ;
        
        if (scores[winningTeam] > scores[currentBestTeam]) {
            currentBestTeam = winningTeam;
        }
    } // for

    return currentBestTeam;
}

void updateScores (string team, int points, unordered_map<string, int> &scores) {
    if (scores.find(team)== scores.end())
        scores[ team] = 0;
        
    scores[team] += points;
} // updateScores

int main() {
    vector<vector<string>> competition = { {"HTML", "C#"}, 
                                           {"C#", "Python"},
                                           {"Python", "HTML"} };

    vector<int> result = {0, 0, 1};
    cout << tournamentWinner(competition, result) << endl;

} // main