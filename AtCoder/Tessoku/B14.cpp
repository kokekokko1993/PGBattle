#include <bits/stdc++.h>
using namespace std;

int main() {
    long long N, K, A[39];
    cin >> N >> K;
    vector<long long> F, B, SF, SB;
    for (int i = 0; i < N; i++) {
        cin >> A[i];
        if (i < N / 2) {
            F.push_back(A[i]);
        } else {
            B.push_back(A[i]);
        }
    }
    for (int i = 0; i < pow(2, F.size()); i++) {
        long long tmp = 0;
        for (int j = 0; j < (int)F.size(); j++) {
            if (i & (1 << j)) {
                tmp += F[j];
            }
        }
        SF.push_back(tmp);
    }
    for (int i = 0; i < pow(2, B.size()); i++) {
        long long tmp = 0;
        for (int j = 0; j < (int)B.size(); j++) {
            if (i & (1 << j)) {
                tmp += B[j];
            }
        }
        SB.push_back(tmp);
    }
    sort(SB.begin(), SB.end());
    SB.push_back(1e12);

    bool ans = false;
    for (int i = 0; i < (int)SF.size(); i++) {
        int idx = lower_bound(SB.begin(), SB.end(), K - SF[i]) - SB.begin();
        ans |= SF[i] + SB[idx] == K;
    }

    if (ans) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
    return 0;
}