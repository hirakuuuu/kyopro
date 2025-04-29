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
    vector<int> h(n);
    rep(i, 0, n) cin >> h[i];

    vector<vector<int>> dp(n, vector<int>(3005, 1));
    int ans = 1;
    rep(i, 1, n){
        rep(j, 0, i){
            if(h[i] != h[j]) continue;
            dp[i][i-j] = dp[j][i-j]+1;
        }
        rep(j, 0, n){
            // cout << dp[i][j] << ' ';
            chmax(ans, dp[i][j]);
        }
        // cout << endl;
    }
    cout << ans << endl;
    
    
    return 0;
}