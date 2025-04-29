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
    int n, k; cin >> n >> k;
    vector<vector<mint>> dp(3*n+1, vector<mint>(k+1));
    dp[1][0] = 1;
    rep(i, 2, 3*n+1){
        rep(j, 0, k+1){
            dp[i][j] += dp[i-1][j];
        }
        if((i%6 == 2 && i >= 8) || (i%6 == 5)){
            rep(j, 0, k){
                dp[i][j+1] += dp[i-3][j];
            }
        }else if((i%6 == 3 && i >= 9) || (i%6 == 0)){
            rep(j, 0, k){
                dp[i][j+1] += dp[i-5][j];
            }
        }
    }

    mint ans = 0;
    rep(i, 0, k+1) ans += dp[3*n][i];
    cout << ans.val() << endl;

    return 0;
}