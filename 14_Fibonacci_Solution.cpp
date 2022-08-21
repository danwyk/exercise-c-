#include <vector>
#include <string>
#include <iostream>

using namespace std;

int getNthFib(int n) {
    // O(n) Time
    // O(1) Space
    int lastTwoNum[2] = {0, 1};
    int fibo_idx = 3;
    int fibo_Nth = 0;
    
    if(n == 1 || n == 2) {
        return (n - 1);
    }

    while(fibo_idx <= n) {
        fibo_Nth = lastTwoNum[0] + lastTwoNum[1];
        lastTwoNum[0] = lastTwoNum[1];
        lastTwoNum[1] = fibo_Nth;
        fibo_idx++;
    }

    return fibo_Nth;
} // getNthFib

int main() {
    int input;

    cout <<"Please enter a number: ";
    cin >> input;
    cout << "fibonaci number is: " << getNthFib(input) << endl;

} // main
