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
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, l; cin >> n >> l;
    vector<int> a(n);
    long double sum = 0;
    rep(i, 0, n) cin >> a[i], sum += a[i];
    
    vector<vector<vector<long double>>> dp(2*n+1, vector<vector<long double>>(n+1, vector<long double>(l+1)));
    dp[0][0][l] = 1.0;
    rep(i, 0, 2*n){
        rep(j, 0, n+1){
            if(i < j) continue;
            if(2*n-i < j) continue;
            if((i-j)%2 == 1) continue;
            rep(k, 1, l+1){
                // cout << i << ' ' << j << ' ' << k << ' ' << setprecision(20) <<  dp[i][j][k] << endl;

                // 1枚目をめくってそろう
                if(j > 0){
                    long double p = (long double)j/(2*n-i);
                    dp[i+1][j-1][k] += dp[i][j][k]*p;
                }
                // 2枚めくってそろう
                if(2*n-i >= 2 && (n-(i-j)/2-j) >= 1){
                    long double p = (long double)(2*n-i-j)/(2*n-i);
                    long double q = (long double)1/(2*n-i-1);
                    dp[i+2][j][k] += dp[i][j][k]*p*q;
                }
                // 2枚めくって, 2枚目がそろう
                if(2*n-i >= 2 && 2*n-i-j > 0){
                    long double p = (long double)(2*n-i-j)/(2*n-i);
                    long double q = (long double)j/(2*n-i-1);
                    if(k-1 > 0) dp[i+2][j][k-1] += dp[i][j][k]*p*q;
                    else dp[i+1][j+1][k-1] += dp[i][j][k]*p*q;
                }
                // そろわない
                if(2*n-i >= 2 && (n-(i-j)/2-j) >= 2){
                    long double p = (long double)(2*n-i-j)/(2*n-i);
                    long double q = (long double)(2*n-i-1-j-1)/(2*n-i-1);
                    dp[i+2][j+2][k-1] += dp[i][j][k]*p*q;
                }


            }
        }
    }

    // rep(i, 1, l+1){
    //     rep(j, 0, n+1){
    //         cout << 2*n << ' ' << j << ' ' << i << ' ' << dp[2*n][j][i] << endl;
    //     }
    // }

    long double ans = 0.0;
    // ライフ > 0
    rep(i, 1, l+1){
        // cout << i << ' ' << setprecision(20) << dp[2*n][0][i] << endl;
        ans += dp[2*n][0][i]*sum;
    }
    // ライフ = 0
    rep(i, 0, 2*n+1){
        rep(j, 0, n+1){
            if(i < j) continue;
            if(2*n-i < j) continue;
            if((i-j)%2 == 1) continue;
            int cnt = (i-j)/2;
            long double e = sum*cnt/n;
            // cout << i << ' ' << j << ' ' << setprecision(20) << dp[i][j][0] << ' ' << cnt << endl;
            ans += dp[i][j][0]*e;
        }
    }
    cout << setprecision(20) << ans << endl;
    return 0;
}