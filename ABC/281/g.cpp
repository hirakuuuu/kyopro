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
// using mint = modint998244353;
using mint = modint;
constexpr int IINF = 1001001001;
constexpr ll INF = 1e18;

template<class t,class u> void chmax(t&a,u b){if(a<b)a=b;}
template<class t,class u> void chmin(t&a,u b){if(b<a)a=b;}

/*
n-1 頂点の単純連結無向グラフを作り、１からの距離が最も遠い点と n をくっつけるとしてもよい

*/

int main(){
    int n, m; cin >> n >> m;
    mint::set_mod(m);
    vector<vector<mint>> two(n+1, vector<mint>(n+1)); // two[j][k] = (mint(2).pow(j)-1).pow(j);
    rep(j, 0, n+1){
        rep(k, 0, n+1){
            two[j][k] = (mint(2).pow(k)-1).pow(j);
        }
    }
    vector<vector<mint>> dp(n+1, vector<mint>(n+1));
    dp[1][1] = dp[2][1] = 1;
    rep(i, 3, n+1){
        // i 頂点で 1 から最も遠い頂点の集合の位数が j である場合
        rep(j, 1, i){
            // i-j からの遷移
            rep(k, 1, i-j+1){
                dp[i][j] += dp[i-j][k]*two[j][k];
            }
        }
        rep(j, 1, n+1){
            cout << dp[i][j].val() << ' ';
        }
        cout << endl;
    }
    return 0;
}