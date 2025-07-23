#include <bits/stdc++.h>
using namespace std;

int N, K;
int A[309], B[309];

int getScore(int a, int b) {
    int cnt = 0;
    for (int i = 1; i <= N; i++) {
        cnt += (a <= A[i] && A[i] <= a + K && b <= B[i] && B[i] <= b + K);
    }
    return cnt;
}

int main() {
    cin >> N >> K;
    for (int i = 1; i <= N; i++) {
        cin >> A[i] >> B[i];
    }

    int ans = 0;
    // 答えの下限を固定して、その中に何人入るかを考える！
    for (int a = 1; a <= 100; a++) {
        for (int b = 1; b <= 100; b++) {
            ans = max(ans, getScore(a, b));
        }
    }
    cout << ans << endl;
    return 0;
}