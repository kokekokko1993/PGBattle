#include <bits/stdc++.h>
using namespace std;

int R, C, sy, sx, gy, gx;
char c[59][59];
int dist[59][59];
pair<int, int> dij[4] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

int main() {
    cin >> R >> C >> sy >> sx >> gy >> gx;
    for (int i = 1; i <= R; i++) {
        for (int j = 1; j <= C; j++) {
            cin >> c[i][j];
            dist[i][j] = -1;
        }
    }

    queue<pair<int, int>> q;
    dist[sy][sx] = 0;
    q.push({sy, sx});
    while (!q.empty()) {
        auto [i, j] = q.front();
        q.pop();

        for (int k = 0; k < 4; k++) {
            auto [di, dj] = dij[k];
            bool inRange =
                (i + di > 0) && (i + di <= R) && (j + dj > 0) && (j + dj <= C);
            if (!inRange) continue;
            bool canNext =
                (c[i + di][j + dj] == '.') && (dist[i + di][j + dj] < 0);
            if (canNext) {
                dist[i + di][j + dj] = dist[i][j] + 1;
                q.push({i + di, j + dj});
            }
        }
    }
    cout << dist[gy][gx] << endl;
    return 0;
}