#include <bits/stdc++.h>
using namespace std;

long long N;

int main() {
    cin >> N;
    long long ans = (N / 3) + (N / 5) - (N / 15);
    cout << ans << endl;
    return 0;
}