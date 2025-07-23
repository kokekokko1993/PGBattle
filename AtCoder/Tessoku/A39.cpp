#include <bits/stdc++.h>
using namespace std;

int N, L[300009], R[300009];
pair<int, int> S[300009];

int main() {
    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> L[i] >> R[i];
        S[i] = {R[i], L[i]};
    }
    sort(S + 1, S + N + 1);

    int current = 0;
    int ans = 0;
    for (int i = 1; i <= N; i++) {
        auto [end, start] = S[i];
        if (start >= current) {
            ans++;
            current = end;
        }
    }
    cout << ans << endl;
    return 0;
}