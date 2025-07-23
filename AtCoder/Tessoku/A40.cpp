#include <bits/stdc++.h>
using namespace std;

int N, A[200009];
vector<long long> nums(101, 0);

int main() {
    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> A[i];
        nums[A[i]]++;
    }

    long long ans = 0;
    for (int i = 1; i <= 100; i++) {
        ans += nums[i] * (nums[i] - 1) * (nums[i] - 2) / 3 / 2;
    }
    cout << ans << endl;
    return 0;
}