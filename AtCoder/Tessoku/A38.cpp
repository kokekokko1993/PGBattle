#include <bits/stdc++.h>
using namespace std;

int D, N;
int L[10009], R[10009], H[10009];
int M[10009];

int main() {
    cin >> D >> N;
    for (int i = 1; i <= N; i++) {
        cin >> L[i] >> R[i] >> H[i];
    }
    for (int i = 1; i <= D; i++) {
        M[i] = 24;
    }

    for (int i = 1; i <= N; i++) {
        for (int j = L[i]; j <= R[i]; j++) {
            M[j] = min(M[j], H[i]);
        }
    }
    int ans = 0;
    for (int i = 1; i <= D; i++) {
        ans += M[i];
    }
    cout << ans << endl;
    return 0;
}