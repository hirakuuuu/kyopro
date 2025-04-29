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
constexpr ll INF = 4e18;

template<class t,class u> void chmax(t&a,u b){if(a<b)a=b;}
template<class t,class u> void chmin(t&a,u b){if(b<a)a=b;}

/*
単純パスの個数は O((n-1)!) で今回の制約だと列挙できる．
単純パスの列挙は DFS で可能
*/

int main(){
    int n, m; cin >> n >> m;
    vector<vector<pair<int, ll>>> g(n);
    rep(i, 0, m){
        int u, v; cin >> u >> v; u--, v--;
        ll w; cin >> w;
        g[u].push_back({v, w});
        g[v].push_back({u, w});
    }

    vector<int> seen(n);
    seen[0] = true;
    auto f = [&](auto self, int pos, ll tmp) -> ll {
        if(pos == n-1){
            return tmp;
        }

        ll res = INF;
        for(auto [nxt, w]: g[pos]){
            if(seen[nxt]) continue;
            seen[nxt] = true;
            chmin(res, self(self, nxt, (tmp^w)));
            seen[nxt] = false;
        }
        return res;
    };
    cout << f(f, 0, 0) << endl;

    
    return 0;
}