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
    ll n, m; cin >> n >> m;
    assert(n <= 3000);
    vector<ll> a(n);
    rep(i, 0, n) cin >> a[i];
    a.push_back(0);
    a.push_back(m+1);
    sort(a.begin(), a.end());

    vector<vector<ll>> dp(n+2, vector<ll>(n+2));
    vector<vector<ll>> mx(n+2, vector<ll>(n+2)); // mx[l][r] = max(dp[l][?]+dp[?][r]);
    rep(i, 0, n+2) dp[i][i] = 0;
    rep(i, 0, n+1) dp[i][i+1] = 0;
    rep(k, 2, n+2){
        rep(l, 0, n+2){
            if(l+k >= n+2) continue;
            chmax(dp[l][l+k], dp[l][l+1]+dp[l+1][l+k]+a[l+k]-a[l]);
            chmax(dp[l][l+k], dp[l][l+k-1]+dp[l+k-1][l+k]+a[l+k]-a[l]);
        }
    }

    cout << dp[0][n+1] << endl;

    return 0;
}