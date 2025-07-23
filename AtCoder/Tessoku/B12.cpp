#include <bits/stdc++.h>
using namespace std;

int N;

double f(double x) { return pow(x, 3) + x; }

bool solve(double v) { return f(v) <= N; }

double binarySearch(double ok, double ng) {
    while (abs(ok - ng) > 0.0001) {
        double mid = (ok + ng) / 2;
        if (solve(mid)) {
            ok = mid;
        } else {
            ng = mid;
        }
    }
    return ok;
}

int main() {
    cin >> N;
    double ans = binarySearch(0, 100);
    cout << ans << endl;
    return 0;
}