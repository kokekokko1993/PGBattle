#include <bits/stdc++.h>
using namespace std;

int N, K;
string S;

int main() {
    cin >> N >> K >> S;
    int nTurnOn = 0;
    for (int i = 0; i < N; i++) {
        nTurnOn += S[i] == '1';
    }
    if (nTurnOn % 2 == K % 2) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
    return 0;
}