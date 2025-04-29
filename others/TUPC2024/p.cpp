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
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        vector<ll> a(n);
        rep(i, 0, n) cin >> a[i];
        
        vector<vector<ll>> dp(n, vector<ll>(2, INF));
        dp[0][0] = 0;
        dp[0][1] = a[0];
        rep(i, 1, n){
            dp[i][0] = dp[i-1][1];
            dp[i][1] = min(dp[i-1][0], dp[i-1][1])+a[i];
        }
        cout << min(dp[n-1][0], dp[n-1][1]) << endl;
    }
    return 0;
}