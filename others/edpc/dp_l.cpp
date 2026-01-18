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
    int n; cin >> n;
    vector<ll> a(n);
    rep(i, 0, n) cin >> a[i];

    vector<vector<ll>> dp(n+1, vector<ll>(n+1));
    rep(len, 1, n+1){
        rep(l, 0, n){
            int r = l+len;
            if(r > n) break;

            if((n+len)%2 == 0){
                dp[l][r] = max(dp[l+1][r]+a[l], dp[l][r-1]+a[r-1]);
            }else{
                // cout << l << ' ' << r << endl;
                dp[l][r] = min(dp[l+1][r]-a[l], dp[l][r-1]-a[r-1]);
            }
        }
    }
    cout << dp[0][n] << endl;
    return 0;
}