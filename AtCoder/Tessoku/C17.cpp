#include <bits/stdc++.h>
using namespace std;

int Q;
char t[300009];
string X[300009];

int main() {
    cin >> Q;
    for (int i = 1; i <= Q; i++) {
        cin >> t[i];
        if (t[i] == 'A' || t[i] == 'B') {
            cin >> X[i];
        }
    }

    deque<string> q1, q2;
    int current_num = 0;
    for (int i = 1; i <= Q; i++) {
        if (t[i] == 'A') {
            q2.push_back(X[i]);
            if (current_num % 2 == 0) {
                q1.push_back(q2.front());
                q2.pop_front();
            }
            current_num++;
        } else if (t[i] == 'B') {
            if (current_num % 2 == 1) {
                q2.push_front(X[i]);
            } else {
                q1.push_back(X[i]);
            }
            current_num++;
        } else if (t[i] == 'C') {
            q1.pop_front();
            current_num--;
            if (current_num % 2 == 1) {
                q1.push_back(q2.front());
                q2.pop_front();
            }
        } else {
            cout << q1.front() << endl;
        }
    }
    return 0;
}