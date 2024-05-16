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

/*

*/


int main(){
    int n; cin >> n;
    vector<vector<int>> g(n);
    rep(i, 0, n-1){
        int a, b; cin >> a >> b;
        a--, b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    vector<int> sz(n);
    auto dfs = [&](auto self, int pos, int pre) -> void {
        sz[pos] = 1;
        for(auto nxt: g[pos]){
            if(nxt == pre) continue;
            self(self, nxt, pos);
            sz[pos] += sz[nxt];
        }
    };
    dfs(dfs, 0, -1);
    ll ans = 0;
    rep(i, 0, n){
        ans += (ll)sz[i]*(n-sz[i]);
    }
    cout << ans << endl;


    return 0;
}