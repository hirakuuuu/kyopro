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
        int u, v; cin >> u >> v;
        u--, v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }


    // vector<int> depth(n);
    // vector<int> sz(n, 1);
    // auto f = [&](auto self, int pos, int pre, int d) -> void {
    //     depth[pos] = d;
    //     for(auto nxt: g[pos]){
    //         if(nxt == pre) continue;
    //         self(self, nxt, pos, d+1);
    //         sz[pos] += sz[nxt];
    //     }
    // };
    // f(f, 0, -1, 0);

    int ans = IINF;
    rep(c, 0, n){
        // c が最初の１頂点の場合
        int x = (int)g[c].size();
        int y = IINF;
        
        // map<int, int> m_sz;
        // for(auto nc: g[c]){
        //     if(depth[c] < depth[nc]) m_sz[nc] = sz[nc];
        //     else m_sz[nc] = n+1-sz[nc];
        // }
        sort(g[c].begin(), g[c].end(), [&](auto a, auto b){
            return g[a].size() < g[b].size();
        });

        int m = g[c].size();
        rep(i, 0, m){
            y = g[g[c][i]].size()-1;
            if(y > 0){
                chmin(ans, n-(1+(x-i)+(x-i)*y));
            }
        }
    }
    cout << ans << endl;
    return 0;
}