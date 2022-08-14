#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
const int MOD = 1000000007;
const int mod = 998244353;

// 問題
// https://atcoder.jp/contests/abc264/tasks/abc264_f

int main(){
    ll h, w; cin >> h >> w;
    vector<ll> r(h+1), c(w+1);
    rep(i, 1, h+1) cin >> r[i];
    rep(i, 1, w+1) cin >> c[i];
    vector<vector<ll>> a(h+1, vector<ll>(w+1)), b(h+1, vector<ll>(w+1));
    rep(i, 1, h+1){
        string A; cin >> A;
        rep(j, 1, w+1){
            a[i][j] = A[j-1]-'0';
            b[i][j] = a[i][j]^1;
        }
    }

    vector<vector<vector<vector<ll>>>> dp(h+1, vector<vector<vector<ll>>>(w+1, vector<vector<ll>>(2, vector<ll>(2, (1LL<<60)))));
    rep(r1, 0, 2){
        int c1 = (a[1][1]^r1);
        dp[1][1][0][c1] = r[1]*r1+c[1]*c1;
        dp[1][1][1][r1] = r[1]*r1+c[1]*c1;
    }

    vector<ll> dh = {1, 0}, dw = {0, 1};

    rep(i, 1, h+1){
        rep(j, 1, w+1){
            rep(d, 0, 2){
                rep(l, 0, 2){
                    ll ni = i+dh[d], nj = j+dw[d];
                    if(h < ni or w < nj) continue;
                    ll flip = a[ni][nj]^l;
                    ll cost = 0;
                    if(d == 0) cost = r[ni]*flip;
                    else cost = c[nj]*flip;

                    rep(nd, 0, 2){
                        ll nl = l;
                        if(d != nd) nl = flip;
                        dp[ni][nj][nd][nl] = min(dp[ni][nj][nd][nl], dp[i][j][d][l]+cost);
                    }
                }
            }
        }
    }

    ll ans = (1LL<<60);

    rep(d, 0, 2){
        rep(l, 0, 2){
            ans = min(ans, dp[h][w][d][l]);
        }
    }

    rep(i, 1, h+1){
        rep(j, 1, w+1){
            rep(d, 0, 2){
                rep(l, 0, 2) dp[i][j][d][l] = (1LL<<60);
            }
        }
    }

    rep(r1, 0, 2){
        int c1 = (b[1][1]^r1);
        dp[1][1][0][c1] = r[1]*r1+c[1]*c1;
        dp[1][1][1][r1] = r[1]*r1+c[1]*c1;
    }

    rep(i, 1, h+1){
        rep(j, 1, w+1){
            rep(d, 0, 2){
                rep(l, 0, 2){
                    ll ni = i+dh[d], nj = j+dw[d];
                    if(h < ni or w < nj) continue;
                    ll flip = b[ni][nj]^l;
                    ll cost = 0;
                    if(d == 0) cost = r[ni]*flip;
                    else cost = c[nj]*flip;

                    rep(nd, 0, 2){
                        ll nl = l;
                        if(d != nd) nl = flip;
                        dp[ni][nj][nd][nl] = min(dp[ni][nj][nd][nl], dp[i][j][d][l]+cost);
                    }
                }
            }
        }
    }

    rep(d, 0, 2){
        rep(l, 0, 2){
            ans = min(ans, dp[h][w][d][l]);
        }
    }


    cout << ans << endl;
    
    return 0;
}