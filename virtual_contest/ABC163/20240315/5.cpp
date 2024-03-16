#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(ll i = a; i < n; i++)
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
// 

int main(){
    int n; cin >> n;
    vector<ll> a(n);
    vector<pair<ll, ll>> b(n);
    rep(i, 0, n){
        cin >> a[i];
        b[i] = {a[i], i};
    }
    sort(b.rbegin(), b.rend());

    vector<vector<ll>> dp(n+1, vector<ll>(n+1, -INF));
    dp[0][0] = 0;
    rep(i, 0, n){
        rep(j, 0, i+1){
            if(dp[i][j] < 0) continue;
            ll pos = b[i].second;
            if(pos-j >= 0) chmax(dp[i+1][j+1], dp[i][j]+b[i].first*(pos-j));
            if(n-1-(i-j)-pos >= 0) chmax(dp[i+1][j], dp[i][j]+b[i].first*(n-1-(i-j)-pos));
        }
    }
    ll ans = 0;
    rep(i, 0, n+1) chmax(ans, dp[n][i]);
    cout << ans << endl;


    
    return 0;
}