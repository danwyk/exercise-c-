#include <vector>
#include <string>
#include <iostream>

using namespace std;

int minimumWaitingTime(vector<int> queries) {
  // O(nlogn) Time | O(1) space, where  n is the number of queries
  sort(queries.begin(), queries.end());

  int totalWaitingTime = 0;
  for(int i = 0; i < queries.size(); ++i) {
    int duration =  queries[i];
    int queriesLeft = queries.size() - (i + 1);

    cout << "Duration: " << duration << "   ";
    cout << "Queries Left: " << queriesLeft << "   ";

    totalWaitingTime += duration * queriesLeft; 

    cout << "Total Waiting Time: " << totalWaitingTime << endl;
  } // for

  return totalWaitingTime;
} // minimumWaitingTime


int main() {
    vector<int> queries = {3, 2, 1, 2, 6};

    minimumWaitingTime(queries);
}
