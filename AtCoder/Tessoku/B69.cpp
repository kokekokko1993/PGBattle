/*FORDFULKERSON*/
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
#define rep(i, a, b) for (int i = a; i < b; i++)
#define INF (1e9 + 1)

// 辺の構造体
struct Edge {
    // rev: toから行ける頂点のうち、toから見てfromが何番目に位置するか
    // G[from].size() == rev
    int rev, from, to, cap;
};

// フォードファルカーソン法
class FordFulkerson {
  public:
    vector<vector<Edge>> G;
    vector<bool> visited;
    // 頂点数 n の残余グラフを用意
    int size = 0;
    void init(int n) {
        G.resize(n);
        visited.resize(n);
        size = n;
    }
    /*
        頂点 u -> v について 上限 cost の辺を追加
        コスト0の逆辺も張る
    */
    void add_edge(int u, int v, int cost) {
        int u_vID = G[u].size(); // 現時点での G[u] の要素数 = uからみたvのindex
        int v_uID = G[v].size(); // 現時点での G[v] の要素数 = vからみたuのindex
        G[u].emplace_back(
            Edge{v_uID, u, v, cost});            //<u,v>の逆辺<v,u>はG[u][v_uID]
        G[v].emplace_back(Edge{u_vID, v, u, 0}); // 逆辺は追加時はコスト0!!
    }
    /*
        深さ優先探索（F はスタートした頂点からposに到達する過程での
 　　　　"残余グラフの辺の容量" の最小値）
        goalまでの往路は頂点を記録しながらs->tまでに共通して流せる容量
　　　　　　　　　　　　　　　　　　　　　　 = s->tまでの容量の最小値を取得
        復路はs->tまでの容量の最小値を使って残余ネットワークのコストを更新
        返り値: 流したフローの量
    */
    int dfs(int pos, int goal, int F) {
        if (pos == goal) return F; // ゴールに到着したら流す
        visited[pos] = true;       // 訪れた頂点を記録

        // G[pos]に隣接する頂点を探索
        for (auto &e : G[pos]) {
            // 容量0の辺や訪問済みの頂点は無視
            if (e.cap == 0 or visited[e.to]) continue;
            // 再帰で目的地までのパスを探す
            int flow = dfs(e.to, goal, min(F, e.cap));
            // 残余ネットワークの更新
            // フローを流せる場合、残余グラフの容量をflowだけ増減させる
            if (flow > 0) {
                e.cap -= flow;              // u->vの辺を減少
                G[e.to][e.rev].cap += flow; // v->uの辺を増加
                return flow;
            }
        }
        return 0;
    }

    // 頂点sから頂点tまでの最大フローの総流量を返す
    int maxFlow(int s, int t) {
        int totalFlow = 0;
        while (true) {
            // s->tに探索する前に記録した頂点をリセット
            visited.assign(size, false);
            int F = dfs(s, t, INF); // s->tへの流量を取得
            // フローを流せなくなったら終了
            if (F == 0) break;
            totalFlow += F;
        }
        return totalFlow;
    }
};

// グローバル変数で管理
int n, m;
char c[59][24];

// FordFulkersonのインスタンスff
FordFulkerson ff;

int main() {
    // 入力
    cin >> n >> m;
    // グラフの作成
    // 0: s, 1~n: 従業員、n+1~n+24: 時間帯, n+25: t
    int s = 0, t = n + 25;
    ff.init(n + 26);
    rep(i, 1, n + 1) {
        rep(j, 1, 25) {
            cin >> c[i][j];
            if (c[i][j] == '1') {
                ff.add_edge(i, n + j, 1); // from, to, costで辺を生成
            }
        }
    }
    rep(i, 1, n + 1) { ff.add_edge(s, i, 10); }
    rep(i, 1, 25) { ff.add_edge(n + i, t, m); }
    // 頂点0->n-1までの最大流の出力
    if (ff.maxFlow(s, t) >= m * 24) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
    // cout << ff.maxFlow(s, t) << endl;
    return 0;
}
