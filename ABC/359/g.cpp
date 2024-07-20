#include <bits/stdc++.h>
// #include <atcoder/all>
using namespace std;
// using namespace atcoder;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define rrep(i, a, n) for(int i = a; i >= n; i--)
#define inr(l, x, r) (l <= x && x < r)
#define ll long long
#define ld long double

#pragma GCC target("avx2")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")

// using mint = modint1000000007;
// using mint = modint998244353;
constexpr int IINF = 1001001001;
constexpr ll INF = 9e18;

template<class t,class u> void chmax(t&a,u b){if(a<b)a=b;}
template<class t,class u> void chmin(t&a,u b){if(b<a)a=b;}

/*
重心分解：
木の重心：その頂点を除いたとき、残ったグラフの連結成分のサイズが元のグラフのサイズの半分以下になる

重心で木を分解すると, 各頂点について, 分解の深さが高々 log{n} になるので, 全体で O(n\log{n})
*/

int main(){
    int n; cin >> n;
    vector<vector<int>> g(n);
    rep(i, 0, n-1){
        int u, v; cin >> u >> v;
        u--, v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    vector<int> a(n);
    rep(i, 0, n) cin >> a[i];

    ll ans = 0;
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

    auto dfs3 = [&](auto f, int pos, int pre=-1, int dep=1) -> void { // 1つ潜った状態から始めるので深さは１スタート
        ps.emplace_back(a[pos], dep);
        for(auto nxt: g[pos]){
            if(nxt == pre || used[nxt]) continue;
            f(f, nxt, pos, dep+1);
        }
    };

    auto centroid_decomposition = [&](auto cd, int v) -> void {
        int c = get_centroid(v);

        used[c] = true;
        map<int, ll> cnt;
        map<int, ll> sum;
        cnt[a[c]] = 1, sum[a[c]] = 0;
        for(auto u: g[c]){
            if(used[u]) continue;
            ps.clear();
            dfs3(dfs3, u);
            for(auto [col, dep]: ps){
                ans += sum[col]+(ll)dep*cnt[col];
            }
            for(auto [col, dep]: ps){
                sum[col] += dep;
                cnt[col] += 1;
            }
        }
        for(auto nxt: g[c]){
            if(used[nxt]) continue;
            cd(cd, nxt);
        }
    };
    centroid_decomposition(centroid_decomposition, 0);
    cout << ans << endl;

    
    return 0;
}