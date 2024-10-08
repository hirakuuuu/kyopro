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
    int n, k; cin >> n >> k;
    vector<int> a(n), b(n);
    rep(i, 0, n) cin >> a[i] >> b[i];
    vector<pair<ll, ll>> f(n);
    rep(i, 0, n) f[i] = {a[i], b[i]};
    sort(f.begin(), f.end(), [](const pair<ll, ll>& fi, const pair<ll, ll>& fj){
        return (fi.first-1)*fj.second < (fj.first-1)*fi.second;
    });

    vector<vector<ll>> dp(n+1, vector<ll>(k+1));
    rep(i, 0, n+1) dp[i][0] = 1;
    rep(i, 1, n+1){
        rep(j, 0, k+1){
            chmax(dp[i][j], dp[i-1][j]);
            if(j > 0) chmax(dp[i][j], f[i-1].first*dp[i-1][j-1]+f[i-1].second);
        }
    }
    cout << dp[n][k] << endl;
    return 0;
}