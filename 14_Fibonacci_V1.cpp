#include <vector>
#include <string>
#include <iostream>

using namespace std;

int getNthFib(int n) {
    // O(n) Time
    // O(n) Space
    const int F0 = 0;
    const int F1 = 1;
    int F_n_1 = 1;
    int F_n_2 = 0;
    int F_n = 0;

    vector<int> fibonaci;

    fibonaci.reserve(n);
    fibonaci.push_back(F0);
    fibonaci.push_back(F1);
    
    while(fibonaci.size() < n) {
        F_n = F_n_2 + F_n_1;
        fibonaci.push_back(F_n);

        F_n_2 = F_n_1;
        F_n_1 = F_n;
    }

  return fibonaci[n - 1];
} // getNthFib

int main() {
    int input;

    cout <<"Please enter a number: ";
    cin >> input;
    cout << "fibonaci number is: " << getNthFib(input) << endl;

} // main
