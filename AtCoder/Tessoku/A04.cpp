#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    int bN[10];
    for (int i = 0; i < 10; i++)
        bN[i] = 0;
    cin >> N;

    int current = 0;
    while (N > 0) {
        bN[current] = N % 2;
        N /= 2;
        current++;
    }
    for (int i = 9; i >= 0; i--) {
        cout << bN[i];
    }
    cout << endl;
    return 0;
}