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
    int n, m; cin >> n >> m;
    vector<int> a(n), b(m);
    rep(i, 0, n) cin >> a[i];
    rep(i, 0, m) cin >> b[i];
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    vector<vector<ll>> dp(n+1, vector<ll>(m+1, INF));
    dp[0][0] = 0;
    rep(i, 0, n){
        dp[i+1][0] = 0;
        rep(j, 0, m){
            chmin(dp[i+1][j+1], min(dp[i][j+1], dp[i][j]+abs(a[i]-b[j])));
        }
    }
    cout << dp[n][m] << endl;
    return 0;
}