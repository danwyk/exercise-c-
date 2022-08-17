#include <vector>
#include <string>
#include <iostream>

using namespace std;

int minimumWaitingTime(vector<int> queries) {
    // O(nlogn) Time
    // O(1) Space
    int sum = 0;
    int remainQueries = 0;

    sort(queries.begin(), queries.end());

    for(int i = 0; i < queries.size() - 1; ++i) {
        // 后面每个queries都要等这么长时间, 还剩几个query就等几倍
        remainQueries = queries.size() - i - 1;
        sum += remainQueries * queries[i];

    } // for

    return sum;
} // minimumWaitingTime


int main() {
    vector<int> queries = {3, 2, 1, 2, 6};

    cout << minimumWaitingTime(queries);
}