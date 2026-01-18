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
constexpr ll INF = 1e18;

template<class t,class u> void chmax(t&a,u b){if(a<b)a=b;}
template<class t,class u> void chmin(t&a,u b){if(b<a)a=b;}



int main(){
    int n, a, b, p, q; cin >> n >> a >> b >> p >> q;
    vector<vector<vector<mint>>> dp(2, vector<vector<mint>>(n+1, vector<mint>(n+1)));
    dp[0][a][b] = 1;
    rep(i, a, n){
        rep(j, b, n){
            rep(k, 1, p+1){
                dp[1][min(i+k, n)][j] += dp[0][i][j]/p;
            }
            rep(k, 1, q+1){
                dp[0][i][min(j+k, n)] += dp[1][i][j]/q;
            }
        }
    }

    mint ans = 0;
    rep(i, 0, 2){
        rep(j, 0, n){
            ans += dp[i][n][j];
        }
    }
    cout << ans.val() << endl;
    return 0;
}