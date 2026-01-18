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
    vector<int> x(n);
    rep(i, 0, n) cin >> x[i];
    vector<vector<pair<int, int>>> g(n);
    rep(i, 0, n-1){
        int u, v, w; cin >> u >> v >> w;
        u--, v--;
        g[u].push_back({v, w});
        g[v].push_back({u, w});
    }

    auto f = [&](auto self, int pos, int pre) -> ll {
        ll res = 0;
        for(auto [nxt, w]: g[pos]){
            if(nxt == pre) continue;
            res += self(self, nxt, pos);
            x[pos] += x[nxt];
            res += (ll)abs(x[nxt])*w;
        }
        // cout << pos << ' ' << x[pos] << ' ' << res << endl;
        return res;
    };
    cout << f(f, 0, -1) << endl;
    return 0;
}