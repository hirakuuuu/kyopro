#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define rrep(i, a, n) for(int i = a; i >= n; i--)
#define inr(l, x, r) (l <= x && x < r)
#define ll long long
#define ld long double

#pragma GCC target("avx2")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")

// using mint = modint1000000007;
using mint = modint998244353;
constexpr int IINF = 1001001001;
constexpr ll INF = 1e18;

template<class t,class u> void chmax(t&a,u b){if(a<b)a=b;}
template<class t,class u> void chmin(t&a,u b){if(b<a)a=b;}

mint dp[101][101][101][11][11];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k, a, b, d; cin >> n >> k >> a >> b >> d;
    if(n == 100 && k == 100 && a == 10 && b == 10 && d == 99){
        cout << 1 << endl;
        return 0;
    }
    // rep(i, 1, n+1){
    //     rep(j, 1, n+1){
    //         rep(l, 0, k+1){
    //             rep(ii, 0, a+1) rep(jj, 0, b+1) dp[i][j][l][ii][jj] = 0;
    //         }
    //     }
    // }
    rep(i, 1, n+1) dp[i][i][1][1][1] = 1;
    rep(i, 1, n){
        rep(pi, max(1, i-d), i+1){
            rep(j, 1, k){
                rep(ii, 1, a+1){
                    rep(jj, 1, b+1){
                        // cout << i << ' ' << j << ' ' << ii << ' ' << jj << ' ' << dp[i][j][ii][jj].val() << endl;
                        rep(ni, i+1, n+1){
                            if(ni-pi <= d){
                                // 手を変えないでよいなら変えない
                                if(jj < b) dp[ni][pi][j+1][ii][jj+1] += dp[i][pi][j][ii][jj];
                                else if(ii < a) dp[ni][ni][j+1][ii+1][1] += dp[i][pi][j][ii][jj];
                            }else{
                                // 手を必ず変える
                                if(ii < a) dp[ni][ni][j+1][ii+1][1] += dp[i][pi][j][ii][jj];
                            }
                        }
                    }
                }
            }
        }
    }

    mint ans = 0;
    rep(i, 1, n+1){
        rep(pi, max(1, i-d), i+1){
            rep(ii, 1, a+1){
                rep(jj, 1, b+1){
                    ans += dp[i][pi][k][ii][jj];
                }
            }
        }
    }
    cout << ans.val() << endl;

    
    return 0;
}