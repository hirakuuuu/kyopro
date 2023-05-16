#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define rrep(i, a, n) for(int i = a; i >= n; i--)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
const int MOD = 1000000007;
const int mod = 998244353;
const int iinf = 1001001001;

template<class t,class u> void chmax(t&a,u b){if(a<b)a=b;}
template<class t,class u> void chmin(t&a,u b){if(b<a)a=b;}


struct BiconnectedComponent {
    vector<int> ord;                   // 頂点に番号付け（行きがけ順） 
    vector<int> low;                   // どの連結成分に属するか
    vector<bool> used;                 // 探索済みかどうか
    vector<vector<int>> g;             // グラフの隣接リスト表現
    vector<vector<pair<int, int>>> bc; // 成分ごとに辺を格納するリスト
    vector<pair<int, int>> tmp;        // 一時的に辺を格納するリスト
    int n, k = 0;
    BiconnectedComponent(const vector<vector<int>> &g_) : g(g_) {
            n = (int)g.size();
            ord.resize(n, -1);
            low.resize(n, -1);
            used.resize(n, false);
    }
    void dfs(int u, int prev) {
        used[u] = true; // 探索済みにする
        ord[u] = k ++;  // 行きがけ順にナンバリング
        low[u] = ord[u]; // 自分自身のみを含む連結成分として記録
        for (auto v : g[u]){
            if (v == prev) continue; // 一つ前の頂点であれば飛ばす

            if (ord[v] < ord[u]) tmp.emplace_back(min(u, v), max(u, v)); // まだ探索してないor 前に探索した頂点に向かう辺であれば、辺を保存
            
            if (!used[v]) { // 探索していない場合
                dfs(v, u);
                low[u] = min(low[u], low[v]); // uとvを同じ連結成分に属するようにする
                if (low[v] >= ord[u]) { // vが属する連結成分の代表元がuより後に探索した頂点であるとき
                    // uを代表元とする連結成分が取得できる
                    bc.push_back({});
                    while (true) {
                        pair<int, int> e = tmp.back();
                        bc.back().emplace_back(e);
                        tmp.pop_back();
                        if (min(u, v) == e.first && max(u, v) == e.second) { // (u, v)までの辺が連結成分に属する
                            break;
                        }
                    }
                }
            }else{ // vが探索済みである場合
                low[u] = min(low[u], ord[v]); // 閉路ができたので、uとvを連結にする
            }
        }
    }
};


int main(){
    int n, m; cin >> n >> m;
    vector<vector<int>> g(n);
    rep(i, 0, m){
        char u, v; cin >> u >> v;
        g[u-'a'].push_back(v-'a');
        g[v-'a'].push_back(u-'a');
    }
    BiconnectedComponent bc(g);
    bc.dfs(0, -1);
    cout << endl;
    for(auto bb: bc.bc){
        for(auto uv: bb){
            cout << (char)('a'+uv.first) << ' ' << (char)('a'+uv.second) << endl;
        }
        cout << endl;
    }

    
    return 0;
}