#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define rrep(i, a, n) for(int i = a; i >= n; i--)
#define inr(l, x, r) (l <= x && x < r)
#define ll long long
#define ld long double

// using mint = modint1000000007;
using mint = modint998244353;
constexpr int IINF = 1001001001;
constexpr ll INF = 9e18;

template<class t,class u> void chmax(t&a,u b){if(a<b)a=b;}
template<class t,class u> void chmin(t&a,u b){if(b<a)a=b;}

int main(){
    int n, x, y; cin >> n >> x >> y;
    vector<int> a(n), b(n);
    rep(i, 0, n) cin >> a[i] >> b[i];
    vector<vector<int>> dp(301, vector<int>(301, IINF));
    dp[0][0] = 0;
    rep(i, 0, n){
        vector<vector<int>> dp_ = dp;
        rep(j, 0, 301){
            rep(k, 0, 301){
                chmin(dp[min(x, j+a[i])][min(y, k+b[i])], dp_[j][k]+1);
            }
        }
    }
    if(dp[x][y] == IINF) cout << -1 << endl;
    else cout << dp[x][y] << endl;

    return 0;
}