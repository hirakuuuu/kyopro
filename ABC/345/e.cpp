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

/*
同じ色が隣接してはならない → それまでの状態であって，スコアが最大の二色があれば十分
*/

int main(){
    int n, k; cin >> n >> k;
    vector<ll> c(n+1), v(n+1);
    rep(i, 1, n+1) cin >> c[i] >> v[i];

    ll dp[505][2][2];
    rep(i, 0, 505) rep(j, 0, 2){
        dp[i][j][0] = -1;
        dp[i][j][1] = -INF;
    }
    dp[0][0][0] = 0, dp[0][0][1] = 0;
    rep(i, 1, n+1){
        rrep(j, k, 1){
            // 取り除かない場合を dp[0][0] に格納
            if(dp[j][0][0] != c[i]){
                dp[j][0][0] = c[i];
                dp[j][0][1] += v[i];
            }else{
                dp[j][0][0] = c[i];
                dp[j][0][1] = dp[j][1][1]+v[i];
            }
            dp[j][1][0] = -1;
            dp[j][1][1] = -INF;

            // 取り除く場合
            rep(kk, 0, 2){
                if(dp[j-1][kk][1] >= dp[j][0][1]){
                    if(dp[j-1][kk][0] != dp[j][0][0]){
                        // 異なる色なら 1 に移す
                        dp[j][1][0] = dp[j][0][0];
                        dp[j][1][1] = dp[j][0][1];
                    }
                    // dp[j][0] を更新
                    dp[j][0][0] = dp[j-1][kk][0];
                    dp[j][0][1] = dp[j-1][kk][1];
                }else if((dp[j-1][kk][1] >= dp[j][1][1]) && (dp[j-1][kk][0] != dp[j][0][0])){
                    dp[j][1][0] = dp[j-1][kk][0];
                    dp[j][1][1] = dp[j-1][kk][1];
                }
            }
        }
        if(dp[0][0][0] != c[i]){
            dp[0][0][0] = c[i];
            dp[0][0][1] += v[i];
        }else{
            dp[0][0][1] = -INF;
        }
    }


    ll ans = dp[k][0][1];
    if(ans < 0) ans = -1;
    cout << ans << endl;
    
    return 0;
}