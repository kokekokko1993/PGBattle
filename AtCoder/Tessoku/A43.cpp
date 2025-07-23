#include <bits/stdc++.h>
using namespace std;

int N, L, A[200009];
char B[200009];

int main() {
    cin >> N >> L;
    for (int i = 1; i <= N; i++) {
        cin >> A[i] >> B[i];
    }
    int maxLen = 0;
    for (int i = 1; i <= N; i++) {
        int len;
        if (B[i] == 'E') {
            len = L - A[i];
        } else {
            len = A[i];
        }
        maxLen = max(maxLen, len);
        // cout << len << endl;
    }
    cout << maxLen << endl;
    return 0;
}