#include <bits/stdc++.h>
using namespace std;

long long gcd(long long a, long long b) {
    if (a < b) {
        swap(a, b);
    }
    if (b == 0) {
        return a;
    }
    return gcd(b, a % b);
}

int A, B;

int main() {
    cin >> A >> B;
    long long ans = gcd(A, B);
    cout << ans << endl;
    return 0;
}