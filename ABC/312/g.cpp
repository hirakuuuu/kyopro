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
        int u, v; cin >> u >> v; u--, v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    vector<ll> sz(n);
    vector<ll> num(n);
    auto f = [&](auto self, int pos, int pre) -> void {
        ll tmp = 0;
        ll sum = 0;
        sz[pos]++;
        for(auto nxt: g[pos]){
            if(nxt == pre) continue;
            self(self, nxt, pos);
            tmp += sum*sz[nxt];
            sum += sz[nxt];
            sz[pos] += sz[nxt];
        }
        num[pos] = tmp;
        return;
    };


    f(f, 0, -1);
    rep(i, 0, n){
        num[i] += (sz[i]-1)*(n-sz[i]);
    }
    ll ans = (ll)n*(n-1)*(n-2)/6;
    rep(i, 0, n) ans -= num[i];
    cout << ans << endl;
    return 0;
}