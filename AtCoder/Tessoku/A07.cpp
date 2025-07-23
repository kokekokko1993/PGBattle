#include <bits/stdc++.h>
using namespace std;

int main() {
    int D, N;
    int L[100009], R[100009];
    int A[100009], S[100009];

    cin >> D >> N;
    for (int i = 0; i <= N; i++) {
        A[i] = 0;
    }
    for (int i = 1; i <= N; i++) {
        cin >> L[i] >> R[i];
        A[L[i]] += 1;
        A[R[i] + 1] -= 1;
    }

    S[0] = 0;
    for (int i = 1; i <= D; i++) {
        S[i] = S[i - 1] + A[i];
    }
    for (int i = 1; i <= D; i++) {
        cout << S[i] << endl;
    }

    return 0;
}