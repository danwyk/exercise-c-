#include <vector>
#include <string>
#include <iostream>

using namespace std;

int minimumWaitingTime(vector<int> queries) {
    // O(nlogn) Time
    // O(1) Space
    int sum = 0;
    int waitTime = 0;

    sort(queries.begin(), queries.end());

    for(int i = 0; i < queries.size() - 1; ++i) {
        cout << "It's: " << queries[i] << "   Before sum: " << sum;

        waitTime = waitTime + queries[i];
        sum += waitTime;

        cout << "   After sum: " << sum << endl;
    } // for

    return sum;
} // minimumWaitingTime


int main() {
    vector<int> queries = {3, 2, 1, 2, 6};

    cout << minimumWaitingTime(queries);
}