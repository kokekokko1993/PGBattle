#include <bits/stdc++.h>
using namespace std;

long long a, b, c;
// 総和は不変→総和が0ならOK！！！

int main() {
    cin >> a >> b >> c;
    if (a + b + c == 0) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
    return 0;
}