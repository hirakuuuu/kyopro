#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define rrep(i, a, n) for(int i = a; i >= n; i--)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
// constexpr ll MOD = 1000000007;
constexpr ll MOD = 998244353;
constexpr int IINF = 1001001001;
constexpr ll INF = 1LL<<60;

template<class t,class u> void chmax(t&a,u b){if(a<b)a=b;}
template<class t,class u> void chmin(t&a,u b){if(b<a)a=b;}

// 問題
// https://atcoder.jp/contests/abc341/tasks/abc341_f

int main(){
    int n, m; cin >> n >> m;
    vector<vector<int>> g(n);
    rep(i, 0, m){
        int u, v; cin >> u >> v;
        u--, v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    vector<ll> w(n), a(n);
    rep(i, 0, n) cin >> w[i];
    rep(i, 0, n) cin >> a[i];
    vector<vector<int>> g_(n), rev(n);
    rep(i, 0, n){
        for(auto c: g[i]){
            if(w[i] > w[c]){
                g_[i].push_back(c);
            }
        }
    }

    swap(g_, g);
    auto dfs = [&](auto sfs, int pos, vector<bool> &seen, vector<ll> &v) -> void{
        if(seen[pos]) return;
        seen[pos] = true;
        for(auto nxt: g[pos]){
            sfs(sfs, nxt, seen, v);
        }
        
        vector<vector<ll>> dp(g[pos].size(), vector<ll>(w[pos]));
        if(g[pos].size() == 0){
            v[pos] = 1;
            return;
        }
        rep(i, w[g[pos][0]], w[pos]) dp[0][i] = v[g[pos][0]];
        rep(i, 1, g[pos].size()){
            rep(j, 0, w[pos]){
                if(j-w[g[pos][i]] >= 0) dp[i][j] = max(dp[i-1][j], dp[i-1][j-w[g[pos][i]]]+v[g[pos][i]]);
                else dp[i][j] = dp[i-1][j];
            }
        }
        v[pos] = dp[g[pos].size()-1][w[pos]-1]+1;
    };
    ll ans = 0;
    vector<ll> v(n);
    vector<bool> seen(n);
    rep(i, 0, n){
        dfs(dfs, i, seen, v);
    }
    rep(i, 0, n){
        ans += v[i]*a[i];
    }
    cout << ans << endl;

    







    return 0;
}