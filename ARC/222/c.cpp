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
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        vector<vector<ll>> a(n, vector<ll>(n));
        rep(i, 0, n){
            rep(j, 0, n){
                cin >> a[i][j];
            }
        }
        vector<vector<ll>> d(n, vector<ll>(n));
        rep(i, 0, n){
            rep(j, 0, n){
                rep(k, 0, 4){
                    int ni = i+(k-1)%2, nj = j+(k-2)%2;
                    if(!inr(0, ni, n) || !inr(0, nj, n)) continue;
                    d[i][j] += a[ni][nj];
                }
            }
        }

        if(n == 2){
            vector<ll> sum(2);
            rep(i, 0, n){
                rep(j, 0, n){
                    sum[(i+j)%2] += a[i][j];
                }
            }
            rep(i, 0, n){
                rep(j, 0, n){
                    cout << sum[(i+j)%2] << ' ';
                }
                cout << endl;
            }
        }else{
            vector<vector<vector<ll>>> dp(n, vector<vector<ll>>(n, vector<ll>(n, -INF)));
            rep(k, 0, n){
                rep(j, 0, n){
                    dp[j][k][k] = 0;
                    if(k-1 >= 0) dp[j][k-1][k] = 0;
                    if(k+1 < n) dp[j][k+1][k] = 0;
                }
                rrep(j, k-2, 0){
                    rep(i, 0, n){
                        if(j == k-2){
                            if(inr(0, i+1, n)) chmax(dp[i][j][k], dp[i+1][j+1][k]+d[i][j]-a[i][j+1]);
                            if(inr(0, i-1, n)) chmax(dp[i][j][k], dp[i-1][j+1][k]+d[i][j]-a[i][j+1]);
                        }else{
                            if(inr(0, i+1, n)) chmax(dp[i][j][k], dp[i+1][j+1][k]+d[i][j]-a[i][j+1]-a[i+1][j]);
                            if(inr(0, i-1, n)) chmax(dp[i][j][k], dp[i-1][j+1][k]+d[i][j]-a[i][j+1]-a[i-1][j]);
                        }
                    }
                }
                rep(j, k+2, n){
                    rep(i, 0, n){
                        if(j == k-2){
                            if(inr(0, i+1, n)) chmax(dp[i][j][k], dp[i+1][j-1][k]+d[i][j]-a[i][j-1]);
                            if(inr(0, i-1, n)) chmax(dp[i][j][k], dp[i-1][j-1][k]+d[i][j]-a[i][j-1]);
                        }else{
                            if(inr(0, i+1, n)) chmax(dp[i][j][k], dp[i+1][j-1][k]+d[i][j]-a[i][j-1]-a[i+1][j]);
                            if(inr(0, i-1, n)) chmax(dp[i][j][k], dp[i-1][j-1][k]+d[i][j]-a[i][j-1]-a[i-1][j]);
                        }
                    }
                }

                rep(i, 0, n){
                    rep(j, 0, n){
                        cout << dp[i][j][k] << ' ';
                    }
                    cout << endl;
                }
                cout << endl;
            }
            vector<vector<ll>> sum(n, vector<ll>(2));
            rep(i, 0, n-2){
                rep(j, i, i+3){
                    rep(k, 0, n){
                        sum[i][(j+k)%2] += a[k][j];
                    }
                }
            }
            if(n == 3){
                rep(i, 0, n){
                    rep(j, 0, n){
                        cout << sum[0][(i+j)%2] << ' ';
                    }
                    cout << endl;
                }
            }else if(n == 4){
                rep(i, 0, n){
                    rep(j, 0, n){
                        ll tmp = sum[j][(i+j)%2];
                        if(j >= 1) chmin(tmp, sum[j-1][(i+j)%2]);
                        if(j <= n-2) chmin(tmp, sum[j+1][(i+j)%2]);
                        rep(k, 0, n-2){
                            if(inr(0, j+1, n)) chmin(tmp, dp[i][j+1][k]+sum[k][(i+j)%2]);
                            if(inr(0, j-1, n)) chmin(tmp, dp[i][j-1][k]+sum[k][(i+j)%2]);
                        }
                        cout << tmp << ' ';
                    }
                    cout << endl;
                }
            }
        }
    }
    
    return 0;
}