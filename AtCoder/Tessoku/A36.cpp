#include <bits/stdc++.h>
using namespace std;

int N, K;

int main() {
    cin >> N >> K;
    K = K - (N - 1) * 2;
    if (K >= 0 && K % 2 == 0) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
    return 0;
}