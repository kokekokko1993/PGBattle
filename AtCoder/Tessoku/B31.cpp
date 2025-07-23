#include <bits/stdc++.h>
using namespace std;

// 包除原理
// 集合の和集合 → 奇数個の共通部分を足し、偶数個の共通部分を引く！！

long long N;

int main() {
    cin >> N;
    long long ans = (N / 3) + (N / 5) + (N / 7) - (N / 15) - (N / 35) - (N / 21)
                    + (N / 105);
    cout << ans << endl;
    return 0;
}