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
    int n, m; cin >> n >> m;
    int l, s, t; cin >> l >> s >> t;
    vector<vector<pair<int, int>>> g(n);
    rep(i, 0, m){
        int u, v; cin >> u >> v; u--, v--;
        int c; cin >> c;
        g[u].push_back({v, c});
    }

    vector<int> ok(n);
    auto f = [&](auto self, int pos, int len, int cost) -> void {
        if(len == l){
            if(inr(s, cost, t+1)) ok[pos] = 1;
            return;
        }
        for(auto [nxt, c]: g[pos]){
            self(self, nxt, len+1, cost+c);
        }
    };
    f(f, 0, 0, 0);

    rep(i, 0, n){
        if(ok[i]) cout << i+1 << ' ';
    }
    cout << endl;
    return 0;
}