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
constexpr ll INF = 9e18;

template<class t,class u> void chmax(t&a,u b){if(a<b)a=b;}
template<class t,class u> void chmin(t&a,u b){if(b<a)a=b;}

int main(){
    int n; cin >> n;
    ll k; cin >> k;
    vector<ll> a(n), b(n);
    rep(i, 0, n) cin >> a[i];
    rep(i, 0, n) cin >> b[i];
    vector<vector<bool>> dp(n, vector<bool>(2));
    dp[0][0] = dp[0][1] = 1;
    rep(i, 1, n){
        if(dp[i-1][0] && abs(a[i-1]-a[i]) <= k) dp[i][0] = true;
        if(dp[i-1][0] && abs(a[i-1]-b[i]) <= k) dp[i][1] = true;
        if(dp[i-1][1] && abs(b[i-1]-a[i]) <= k) dp[i][0] = true;
        if(dp[i-1][1] && abs(b[i-1]-b[i]) <= k) dp[i][1] = true;
    }
    if(dp[n-1][0] || dp[n-1][1]) cout << "Yes" << endl;
    else cout << "No" << endl;
    
    return 0;
}