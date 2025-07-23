#include <bits/stdc++.h>
using namespace std;

int N, K;
int L[100009], R[100009];
pair<int, int> p[100009], rp[100009];
int cntL[200009], cntR[200009];

int main() {
    cin >> N >> K;
    for (int i = 1; i <= N; i++) {
        cin >> L[i] >> R[i];
        R[i] += K;
        p[i] = {R[i], L[i]};
        rp[i] = {L[i], R[i]};
    }
    sort(p + 1, p + N + 1);
    sort(rp + 1, rp + N + 1);
    reverse(rp + 1, rp + N + 1);
    for (int i = 0; i <= 200000; i++) {
        cntL[i] = cntR[i] = 0;
    }

    int current_end = 0;
    for (int i = 1; i <= N; i++) {
        auto [r, l] = p[i];
        if (current_end <= l) {
            cntL[r]++;
            current_end = r;
        }
    }
    for (int i = 1; i <= 200000; i++) {
        cntL[i] = cntL[i] + cntL[i - 1];
    }

    int current_start = 200000;
    for (int i = 1; i <= N; i++) {
        auto [l, r] = rp[i];
        if (r <= current_start) {
            cntR[l]++;
            current_start = l;
        }
    }
    for (int i = 200000; i > 0; i--) {
        cntR[i - 1] = cntR[i - 1] + cntR[i];
    }

    for (int i = 1; i <= N; i++) {
        int ans = cntL[L[i]] + 1 + cntR[R[i]];
        cout << ans << endl;
    }
    return 0;
}