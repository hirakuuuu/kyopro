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
// https://atcoder.jp/contests/abc345/tasks/abc345_e

int main(){
    int n, k; cin >> n >> k;
    vector<ll> c(n+1), v(n+1);
    rep(i, 1, n+1){
        cin >> c[i] >> v[i];
    }
    vector<vector<ll>> dp(n+1, vector<ll>(k+1, -INF));
    vector<ll> mx(k+1, -INF);
    mx[0] = 0;
    dp[0][0] = 0;
    rep(i, 1, n+1){
        rep(j, max(0, i-k-1), i){
            if(c[j] == c[i]) continue;
            rep(l, i-j-1, k+1){
                chmax(dp[i][l], dp[j][l-(i-j-1)]+v[i]);
            }
        }
    }
    ll ans = -INF;
    rep(i, 1, n+1){
        rep(j, 0, k+1){
            if(n-i == k-j) chmax(ans, dp[i][j]);
        }
    }
    if(ans != -INF) cout << ans << endl;
    else cout << -1 << endl;

    
    return 0;
}