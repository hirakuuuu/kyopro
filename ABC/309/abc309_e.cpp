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
// https://atcoder.jp/contests/abc309/tasks/abc309_e

int main(){
    ll n, m; cin >> n >> m;
    vector<vector<ll>> g(n+1);
    rep(i, 2, n+1){
        int p; cin >> p;
        g[p].push_back(i);
    }

    vector<ll> ins(n+1, -1);
    rep(i, 0, m){
        ll x, y; cin >> x >> y;
        chmax(ins[x], y);
    }

    vector<ll> dp(n+1, -1);
    rep(i, 1, n+1){
        chmax(dp[i], ins[i]);
        if(dp[i] <= 0) continue;
        for(auto c: g[i]){
            chmax(dp[c], dp[i]-1);
        }
    }

    int ans = 0;
    rep(i, 1, n+1){
        if(dp[i] >= 0) ans++;
    }

    cout << ans << endl;

    
    return 0;
}