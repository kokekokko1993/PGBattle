#include <bits/stdc++.h>
using namespace std;

int N;
string S;
int L[3009], R[3009];
int H[3009];

int main() {
    cin >> N >> S;
    for (int i = 1; i <= N; i++) {
        L[i] = R[i] = -1e9;
    }
    int s = 1, count = 0;
    for (int i = 0; i < N; i++) {
        if ((S[i] == 'A') && (i < N - 1)) {
            count++;
        } else {
            for (int j = s; j <= s + count; j++) {
                L[j] = j - s + 1;
            }
            s += count + 1;
            count = 0;
        }
    }
    // for (int i = 1; i <= N; i++) {
    //     cout << L[i] << " ";
    // }
    // cout << endl;
    s = N, count = 0;
    for (int i = N - 2; i >= -1; i--) {
        if ((S[i] == 'B') && (i >= 0)) {
            count++;
        } else {
            for (int j = s; j >= s - count; j--) {
                R[j] = s - j + 1;
            }
            s -= count + 1;
            count = 0;
        }
        // cout << i << " " << s << " " << count << endl;
    }
    // for (int i = 1; i <= N; i++) {
    //     cout << R[i] << " ";
    // }
    // cout << endl;
    for (int i = 1; i <= N; i++) {
        H[i] = max(L[i], R[i]);
    }
    int ans = 0;
    for (int i = 1; i <= N; i++) {
        ans += H[i];
    }
    cout << ans << endl;
    return 0;
}