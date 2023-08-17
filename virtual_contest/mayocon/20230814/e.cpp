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

int main(){
    ll n; cin >> n;
    vector<ll> a(n);
    rep(i, 0, n) cin >> a[i];

    vector<ll> p(n);
    p[0] = 0;
    rep(i, 1, n){
        p[i] = p[i-1]+a[(i-1)/2];
    }

    vector<vector<ll>> dp(n+1, vector<ll>(n));
    rep(i, 2, n+1){
        rep(j, 0, i){
            chmax(dp[i][0], dp[i-1][j]);
        }
        rep(j, 1, i){
            dp[i][j] = dp[i-1][j-1]+a[(j-1)/2];
        }
    }

    ll ans = 0;
    rep(i, 0, n){
        chmax(ans, dp[n][i]);
    }
    cout << ans << endl;

    return 0;
}