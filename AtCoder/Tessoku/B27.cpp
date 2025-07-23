#include <bits/stdc++.h>
using namespace std;

// O(lob(a+b))
long long calculate_gcd(long long a, long long b) {
    if (a < b) {
        swap(a, b);
    }
    if (b == 0) {
        return a;
    }
    return calculate_gcd(b, a % b);
}

// O(lob(a+b))
long long calculate_lcm(long long a, long long b) {
    long long gcd = calculate_gcd(a, b);
    long long ans = a / gcd * b;
    return ans;
}

int A, B;

int main() {
    cin >> A >> B;
    cout << calculate_lcm(A, B) << endl;
    return 0;
}