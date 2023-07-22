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
// https://atcoder.jp/contests/abc311/tasks/abc311_e

int main(){
    ll h, w, n; cin >> h >> w >> n;
    vector<int> a(n), b(n);
    rep(i, 0, n) cin >> a[i] >> b[i];

    vector<vector<ll>> dp(h+1, vector<ll>(w+1, 1));
    rep(i, 0, w+1) dp[0][i] = 0;
    rep(i, 0, h+1) dp[i][0] = 0;
    rep(i, 0, n){
        dp[a[i]][b[i]] = 0;
    }

    rep(i, 1, h+1){
        rep(j, 1, w+1){
           if(dp[i][j] == 0) continue;
           dp[i][j] = min({dp[i-1][j-1], dp[i-1][j], dp[i][j-1]})+1;
        }
    }


    ll ans = 0;
    rep(i, 1, h+1){
        rep(j, 1, w+1){
            ans += dp[i][j];
        }
    }

    cout << ans << endl;

    
    return 0;
}