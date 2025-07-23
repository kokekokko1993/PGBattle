#include <bits/stdc++.h>
using namespace std;

constexpr long long INF = (1LL << 60);

// 辺の情報
struct Edge {
    // 行先
    int to;

    // コスト
    long long cost;
};

using Graph = std::vector<std::vector<Edge>>;

// { distance, from }
using Pair = std::pair<long long, int>;

// ダイクストラ法 (1.1 基本実装)
// distances は頂点数と同じサイズ, 全要素 INF で初期化しておく
// O(MlogM)
void Dijkstra(const Graph &graph, std::vector<long long> &distances,
              int startIndex) {
    // 「現時点での最短距離, 頂点」の順に取り出す priority_queue
    // デフォルトの priority_queue は降順に取り出すため std::greater を使う
    std::priority_queue<Pair, std::vector<Pair>, std::greater<Pair>> q;
    q.emplace((distances[startIndex] = 0), startIndex);

    while (!q.empty()) {
        const long long distance = q.top().first;
        const int from = q.top().second;
        q.pop();

        // 最短距離でなければ処理しない
        if (distances[from] < distance) {
            continue;
        }

        // 現在の頂点からの各辺について
        for (const auto &edge : graph[from]) {
            // to までの新しい距離
            const long long d = (distances[from] + edge.cost);

            // d が現在の記録より小さければ更新
            if (d < distances[edge.to]) {
                q.emplace((distances[edge.to] = d), edge.to);
            }
        }
    }
}

set<int> get_points(const Graph &graph, std::vector<long long> &distances,
                    int startIndex, int targetIndex) {
    set<int> points;
    queue<int> q;
    points.insert(targetIndex);
    q.push(targetIndex);
    int current;
    while (!q.empty()) {
        current = q.front();
        q.pop();
        for (auto e : graph[current]) {
            int next = e.to;
            int cost = e.cost;
            if (distances[current] - cost == distances[next]) {
                points.insert(next);
                q.push(next);
            }
        }
    }
    return points;
}

int N, M;
int A[100009], B[100009];
long long C[100009];

int main() {
    cin >> N >> M;
    Graph g = vector<vector<Edge>>(N + 1, vector<Edge>());
    for (int i = 1; i <= M; i++) {
        cin >> A[i] >> B[i] >> C[i];
        g[A[i]].push_back(Edge{B[i], C[i]});
        g[B[i]].push_back(Edge{A[i], C[i]});
    }
    vector<long long> dist(N + 1, INF);
    Dijkstra(g, dist, 1);

    set<int> points = get_points(g, dist, 1, N);
    cout << points.size() << endl;

    // for (auto e : dist) {
    //     cout << e << " ";
    // }
    // cout << endl;
    // for (auto e : points) {
    //     cout << e << " ";
    // }
    // cout << endl;
    return 0;
}