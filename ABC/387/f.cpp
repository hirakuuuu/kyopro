#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define rrep(i, a, n) for(int i = a; i >= n; i--)
#define inr(l, x, r) (l <= x && x < r)
#define ll long long
#define ld long double

// using mint = modint1000000007;
using mint = modint998244353;
constexpr int IINF = 1001001001;
constexpr ll INF = 1e18;

template<class t,class u> void chmax(t&a,u b){if(a<b)a=b;}
template<class t,class u> void chmin(t&a,u b){if(b<a)a=b;}

struct StronglyConnectedComponents {

private:

    int n; // 頂点の数
    vector<vector<int>> g; // グラフの隣接リスト
    vector<vector<int>> g_reverse; // 辺の向きを逆にしたグラフの隣接リスト
    vector<vector<int>> components; // 成分のリスト
    vector<int> postorder; // 帰りがけ順に記録するリスト
    vector<bool> seen; // 探索済みかどうかを記録

    // 帰りがけ順を求めるためのDFS
    void dfs_for_postorder(int s){
        seen[s] = true;
        for(auto ns: g[s]){
            if(seen[ns]) continue;
            dfs_for_postorder(ns);
        }
        postorder.push_back(s);
    }

    // 成分を取得するためのDFS
    void dfs_for_components(int s){
        if(seen[s]) return;
        seen[s] = true;
        for(auto ns: g_reverse[s]){
            if(seen[ns]) continue;
            dfs_for_components(ns);
        }
        components.back().push_back(s);
    }

    // 探索のリセット
    void reset(){
        fill(seen.begin(), seen.end(), false);
    }
    
public:

    // コンストラクタ
    StronglyConnectedComponents(const vector<vector<int>> &g_) : g(g_) {
        n = (int)g.size();
        seen.resize(n);
        g_reverse.resize(n);
        rep(i, 0, n){
            for(auto j: g[i]){
                g_reverse[j].push_back(i); // 辺 i→j を j→i に変換
             }
        }
    }

    // 分解操作
    vector<vector<int>> decomposition() {
        // 探索の状態をリセット
        reset();
        // 帰りがけ順を求めるためのDFS
        rep(i, 0, n){ // 連結で無い場合を考慮してループにする
            if(seen[i]) continue;
            dfs_for_postorder(i);
        }

        // 帰りがけ順の後ろから探索するので、配列を反転
        reverse(postorder.begin(), postorder.end());

        // 探索の状態をリセット
        reset();
        // 分解のためのDFS
        for(auto node: postorder){
            if(seen[node]) continue; // 探索済みならスキップ
            components.push_back({}); // 配列を追加
            dfs_for_components(node);
        }

        return components;
    }

};

int main(){
    int n, m; cin >> n >> m;
    vector<int> a(n);
    rep(i, 0, n) cin >> a[i], a[i]--;

    vector<vector<int>> g(n);
    rep(i, 0, n){
        g[i].push_back(a[i]);
    }

    StronglyConnectedComponents scc(g);
    vector<vector<int>> c = scc.decomposition();

    int l = (int)c.size();
    vector<int> root(n);
    rep(i, 0, l){
        for(auto node: c[i]){
            root[node] = i;
            // cout << node << ' ' << i << endl;
        }
    }

    vector<pair<int, int>> e;
    rep(i, 0, n){
        if(root[i] == root[a[i]]) continue;
        e.push_back({root[i], root[a[i]]});
    }
    sort(e.begin(), e.end());
    e.erase(unique(e.begin(), e.end()), e.end());
    vector<vector<int>> ng(l);
    vector<vector<int>> rev(l);
    for(auto [from, to]: e){
        // cout << from << ' ' << to << endl;
        ng[from].push_back(to);
        rev[to].push_back(from);
    }

    mint ans = 1;
    vector<vector<bool>> memo(l, vector<bool>(m+1));
    vector<vector<mint>> dp(l, vector<mint>(m+1));
    rep(i, 0, l){
        if(ng[i].empty()){
            auto f = [&](auto self, int pos) -> mint {
                mint res = 0;
                for(auto nxt: rev[pos]){
                    self(self, nxt);
                }
                rep(val, 1, m+1){
                    mint tmp = 1;
                    for(auto nxt: rev[pos]){
                        tmp *= dp[nxt][val];
                    }
                    res += tmp;
                    dp[pos][val] = tmp;
                }
                rrep(j, m-1, 1){
                    dp[pos][j] += dp[pos][j+1];
                }
                // cout << pos << ' ' << res.val() << endl;
                return res;
            };
            ans *= f(f, i);
        }
    }
    cout << ans.val() << endl;


    
    return 0;
}