#include <bits/stdc++.h>
using namespace std;

constexpr long long INF = (1LL << 60);

// 辺の情報
struct Edge {
    // 行先
    int to;

    // コスト
    int cost;
};

using Graph = std::vector<std::vector<Edge>>;

// { distance, from }
using Pair = std::pair<long long, int>;

// ダイクストラ法 (1.2 最短経路を再構築する)
// 頂点 startIndex から頂点 targetIndex までの最短経路を path に格納する
// distances は頂点数と同じサイズ, 全要素 INF で初期化しておく
void DijkstraWithPath(const Graph &graph, std::vector<long long> &distances,
                      int startIndex, int targetIndex, std::vector<int> &path) {
    // 直前の頂点を記録する配列
    std::vector<int> p(distances.size(), -1);

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
                // 直前の頂点を記録
                p[edge.to] = from;

                q.emplace((distances[edge.to] = d), edge.to);
            }
        }
    }

    // targetIndex に到達できれば最短経路を再構築する
    if (distances[targetIndex] != INF) {
        for (int i = targetIndex; i != -1; i = p[i]) {
            path.push_back(i);
        }

        std::reverse(path.begin(), path.end());
    }
}

int N, M;
int A[100009], B[100009], C[100009];

int main() {
    cin >> N >> M;
    Graph g = vector<vector<Edge>>(N + 1);
    vector<long long> distances(N + 1, INF);
    for (int i = 1; i <= M; i++) {
        cin >> A[i] >> B[i] >> C[i];
        g[A[i]].push_back({B[i], C[i]});
        g[B[i]].push_back({A[i], C[i]});
    }
    vector<int> path;
    DijkstraWithPath(g, distances, 1, N, path);
    for (auto e : path) {
        cout << e << " ";
    }
    cout << endl;
    return 0;
}