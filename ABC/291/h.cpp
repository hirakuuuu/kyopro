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
constexpr ll INF = 1e18;

template<class t,class u> void chmax(t&a,u b){if(a<b)a=b;}
template<class t,class u> void chmin(t&a,u b){if(b<a)a=b;}

int main(){
    int n; cin >> n;
    vector<vector<int>> g(n);
    rep(i, 0, n-1){
        int a, b; cin >> a >> b;
        a--, b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    // 重心分解（centroid decomposition）
    vector<bool> used(n); // 重心として除いているかどうか
    vector<int> sz(n);    // 部分木のサイズ

    auto get_centroid = [&](int v=0) {
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

    // auto dfs3 = [&](auto f, int pos, int pre=-1, int dep=1) -> void { // 1つ潜った状態から始めるので深さは１スタート
    //     for(auto nxt: g[pos]){
    //         if(nxt == pre || used[nxt]) continue;
    //         f(f, nxt, pos, dep+1);
    //     }
    // };

    vector<int> p(n, -2);
    auto centroid_decomposition = [&](auto cd, int v=0) -> int {
        int c = get_centroid(v);

        used[c] = true;
        for(auto u: g[c]){
            if(used[u]) continue;
            int nc = cd(cd, u);
            p[nc] = c;
        }
        return c;
    };
    centroid_decomposition(centroid_decomposition);
    

    rep(i, 0, n){
        cout << p[i]+1 << ' ';
    }
    cout << endl;
    return 0;
}