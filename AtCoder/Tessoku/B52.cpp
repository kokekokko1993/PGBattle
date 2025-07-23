#include <bits/stdc++.h>
using namespace std;

int N, X;
string A;
queue<int> q;

int main() {
    cin >> N >> X >> A;
    q.push(X);
    A[X - 1] = '@';

    while (!q.empty()) {
        int current = q.front();
        q.pop();
        if (current > 1 && A[current - 2] == '.') {
            A[current - 2] = '@';
            q.push(current - 1);
        }
        if (current < N && A[current] == '.') {
            A[current] = '@';
            q.push(current + 1);
        }
    }
    cout << A << endl;
    return 0;
}