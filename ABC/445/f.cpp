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
    int n, k; cin >> n >> k;
    vector<vector<ll>> c(n, vector<ll>(n));
    rep(i, 0, n){
        rep(j, 0, n){
            cin >> c[i][j];
        }
    }

    vector<vector<vector<ll>>> dp(30, vector<vector<ll>>(n, vector<ll>(n, INF)));
    rep(i, 0, n){
        rep(j, 0, n){
            dp[0][i][j] = c[i][j];
        }
    }
    rep(l, 1, 30){
        rep(i, 0, n){
            rep(j, 0, n){
                rep(kk, 0, n){
                    chmin(dp[l][i][j], dp[l-1][i][kk]+dp[l-1][kk][j]);
                }
            }
        }
    }

    rep(s, 0, n){
        vector<ll> dist(n, INF);
        dist[s] = 0;
        rep(i, 0, 30){
            if((k>>i)&1){
                vector<ll> ndist(n, INF);
                rep(j, 0, n){
                    rep(l, 0, n){
                        chmin(ndist[l], dist[j]+dp[i][j][l]);
                    }
                }
                swap(ndist, dist);
            }
        }
        cout << dist[s] << endl;
    }


    return 0;
}