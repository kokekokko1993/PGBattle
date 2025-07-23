#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;

    cout << N << endl;
    for (int i = 1; i < N; i++) {
        cout << i << " " << i + 1 << endl;
    }
    cout << 1 << " " << N << endl;
    return 0;
}