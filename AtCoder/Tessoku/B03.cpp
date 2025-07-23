#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    int A[109];
    cin >> N;
    for (int i = 1; i <= N; i++)
        cin >> A[i];

    bool res = false;
    for (int i = 1; i <= N; i++) {
        for (int j = i + 1; j <= N; j++) {
            for (int k = j + 1; k <= N; k++) {
                res |= A[i] + A[j] + A[k] == 1000;
            }
        }
    }

    if (res) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
    return 0;
}