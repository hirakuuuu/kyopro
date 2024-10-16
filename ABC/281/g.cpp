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
BFS木として考える
- 距離0の頂点の集合 := {1}
- 距離最大の頂点の集合 := {N}
- 2~n-1 についてはこの間の数で埋めるとする
- そうすると必要な辺が自明になる
- あとはDP（combination は漸化式で作れる）
*/

int main(){
    int n, m; cin >> n >> m;
    mint::set_mod(m);
    vector<vector<mint>> comb(n+1, vector<mint>(n+1));
    rep(i, 0, n+1){
        comb[i][0] = 1;
        rep(j, 1, i+1){
            comb[i][j] = comb[i-1][j-1]+comb[i-1][j];
        }
    }
    vector<vector<mint>> dp(n+1, vector<mint>(n+1));
    dp[1][1] = 1;
    rep(i, 2, n){
        // i 頂点で 1 から最も遠い頂点の集合の位数が j である場合
        rep(j, 1, i+1){
            // i-j からの遷移
            rep(k, 1, i-j+1){
                dp[i][j] += dp[i-j][k]*(mint(2).pow(k)-1).pow(j)*comb[n-1-(i-j)][j];
            }
            dp[i][j] *= mint(2).pow(j*(j-1)/2);
        }
    }
    mint ans = 0;
    rep(i, 1, n){
        ans += dp[n-1][i]*(mint(2).pow(i)-1);
    }
    cout << ans.val() << endl;
    return 0;
}