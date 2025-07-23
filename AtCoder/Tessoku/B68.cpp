// 燃やす埋める問題
// https://ikatakos.com/pot/programming_algorithm/graph_theory/maximum_flow/burn_bury_problem
/*
N個の品物があり、それぞれの物を「燃やす」か「埋める」必要がある
品物iを燃やすのにxi(>=0)円、埋めるのにyi(>=0)円かかる
また、以下の形式のルールがM個ある
・品物ajを燃やして品物bjを埋めると、罰金cj円かかる
最小で何円必要か

以下のようなs,tを始点、終点とするグラフ(かかる費用をエッジの重みとする)とする。
※i in s -> 燃やす、i in t -> 埋める
s->i->t
 ->j->

このグラフにおける最小カット(=最大フロー)が求めるもの！

[費用が負(利益が存在する)のとき]
        a1   a2  a3
燃やす	50	 60	 -130
埋める	-100 100 -100

あらかじめ負となる分をもらっておき、最後にコストとして引く
        a1   a2  a3
燃やす	150	 60	  0
埋める	0    100  30
※最後に100+130=230をコストとして引く
*/

/*
i in s -> 特急駅にする
(i->t:
特急駅にする際のコスト、s->i:特急駅にすることで得られる利益(特急駅にしないことによる損失))
*/

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
int p[159];
int a[159], b[159];
int income = 0;

// FordFulkersonのインスタンスff
FordFulkerson ff;

int main() {
    // 入力
    cin >> n >> m;
    // グラフの作成
    // 0: s, n+1: t
    ff.init(n + m + 2);
    int s = 0, t = n + 1;
    for (int i = 1; i <= n; i++) {
        cin >> p[i];
        if (p[i] > 0) {
            income += p[i];
            ff.add_edge(s, i, p[i]);
            ff.add_edge(i, t, 0);
        } else {
            ff.add_edge(s, i, 0);
            ff.add_edge(i, t, -p[i]);
        }
    }
    for (int i = 0; i < m; i++) {
        cin >> a[i] >> b[i];
        ff.add_edge(a[i], b[i], INF);
    }
    // 頂点s->tまでの最大流の出力
    int res = ff.maxFlow(s, t);
    res -= income;
    cout << -res << endl; // コストで考えていたので-をつけて利益に戻す！
    return 0;
}
