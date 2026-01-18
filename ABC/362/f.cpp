#include <bits/stdc++.h>
// #include <atcoder/all>
using namespace std;
// using namespace atcoder;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define rrep(i, a, n) for(int i = a; i >= n; i--)
#define inr(l, x, r) (l <= x && x < r)
#define ll long long
#define ld long double

// using mint = modint1000000007;
// using mint = modint998244353;
constexpr int IINF = 1001001001;
constexpr ll INF = 9e18;

template<class t,class u> void chmax(t&a,u b){if(a<b)a=b;}
template<class t,class u> void chmin(t&a,u b){if(b<a)a=b;}

int main(){
    int n; cin >> n;
    vector<vector<int>> g(n);
    rep(i, 0, n-1){
        int u, v; cin >> u >> v;
        u--, v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    // 重心分解（centroid decomposition）
    vector<bool> used(n); // 重心として除いているかどうか
    vector<int> sz(n);    // 部分木のサイズ
    vector<pair<int, int>> ps;

    auto get_centroid = [&](int v) {
        // DFS1：部分木のサイズを求める O(n)
        auto dfs = [&](auto f, int pos, int pre=-1) -> int {
            sz[pos] = 1;
            for(auto nxt: g[pos]){
                if(nxt == pre || used[nxt]) continue;
                sz[pos] += f(f, nxt, pos);
            }
            return sz[pos];
        };
        int total = dfs(dfs, v), c = -1;
        // DFS2：重心を求める O(n)
        auto dfs2 = [&](auto f, int pos, int pre=-1) -> void {
            bool ok = (total-sz[pos])*2 <= total;
            for(auto nxt: g[pos]){
                if(nxt == pre || used[nxt]) continue;
                f(f, nxt, pos);
                if(sz[nxt]*2 > total) ok = false;
            }
            if(ok) c = pos;
        };
        dfs2(dfs2, v);
        return c;
    };
    int centroid = get_centroid(0);

    vector<int> p;
    auto dfs = [&](auto self, int pos, int pre) -> void {
        if(pos != centroid) p.push_back(pos);
        for(auto nxt: g[pos]){
            if(nxt == pre) continue;
            self(self, nxt, pos);
        }
    };
    dfs(dfs, centroid, -1);
    p.push_back(centroid);

    rep(i, 0, n/2){
        cout << p[i]+1 << ' ' << p[i+n/2]+1 << endl;
    }

    return 0;
}