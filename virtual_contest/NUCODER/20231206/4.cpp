#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define rrep(i, a, n) for(int i = a; i >= n; i--)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
// constexpr ll MOD = 1000000007;
constexpr ll MOD = 998244353;
constexpr int IINF = 1001001001;
constexpr ll INF = 1LL<<60;

template<class t,class u> void chmax(t&a,u b){if(a<b)a=b;}
template<class t,class u> void chmin(t&a,u b){if(b<a)a=b;}

// 問題
// 

double dp[105][105][105];

int main(){
    int a, b, c; cin >> a >> b >> c;
    dp[a][b][c] = 1.0;
    rep(i, a, 100){
        rep(j, b, 100){
            rep(k, c, 100){
                dp[i+1][j][k] += (double)dp[i][j][k]*i/(i+j+k);
                dp[i][j+1][k] += (double)dp[i][j][k]*j/(i+j+k);
                dp[i][j][k+1] += (double)dp[i][j][k]*k/(i+j+k);
            }
        }
    }
    

    double ans = 0.0;
    rep(i, a, 101){
        rep(j, b, 101){
            rep(k, c, 101){
                if(i == 100 || j == 100 || k == 100){
                    ans += dp[i][j][k]*(abs(a-i)+abs(b-j)+abs(c-k));
                }
            }
        }
    }
    printf("%.10f\n", ans);
    return 0;
}