#include <bits/stdc++.h>
using namespace std;

int N;
string S;

int main() {
    cin >> N >> S;
    bool ans = false;

    int count = 1;
    char current_color = S[0];
    for (int i = 1; i < N; i++) {
        if (S[i] == current_color) {
            count++;
            if (count == 3) {
                ans = true;
                break;
            }
        } else {
            count = 1;
            current_color = S[i];
        }
    }

    if (ans) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
    return 0;
}