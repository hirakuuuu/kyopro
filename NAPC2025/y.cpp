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
    
    vector<vector<ll>> a(n, vector<ll>(n, INF));
    rep(i, 0, m){
        int u, v; cin >> u >> v; u--, v--;
        ll w; cin >> w;
        a[u][v] = a[v][u] = -w;
    }

    vector<ll> dp(1<<n, -INF);
    vector<bool> mx(1<<n, true);
    dp[0] = 0;
    rep(i, 0, 1<<n){
        if(dp[i] == -INF) continue;
        rep(j, 0, n){
            if((i>>j)&1) continue;
            rep(k, j+1, n){
                if(~(i>>k)&1 && a[j][k] != INF){
                    chmax(dp[i+(1<<j)+(1<<k)], dp[i]+a[j][k]);
                    mx[i] = false;
                }
            }
        }
    }
    
    ll ans = -INF;
    rep(i, 0, 1<<n){
        if(mx[i]) chmax(ans, dp[i]);
    }
    cout << -ans << endl;
    return 0;
}