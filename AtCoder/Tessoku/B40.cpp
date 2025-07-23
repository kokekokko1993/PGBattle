#include <bits/stdc++.h>
using namespace std;

int N, A[200009];
vector<long long> r100(100, 0);

int main() {
    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> A[i];
        r100[A[i] % 100]++;
    }

    long long ans = 0;
    ans += r100[0] * (r100[0] - 1) / 2;
    ans += r100[50] * (r100[50] - 1) / 2;
    for (int i = 1; i <= 49; i++) {
        ans += r100[i] * r100[100 - i];
    }
    cout << ans << endl;

    return 0;
}