#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define rrep(i, a, n) for(int i = a; i >= n; i--)
#define inr(l, x, r) (l <= x && x < r)
#define ll long long
#define ld long double
#define pii pair<int, int>
#define pll pair<ll, ll>
// constexpr ll MOD = 1000000007;
constexpr ll MOD = 998244353;
constexpr int IINF = 1001001001;
constexpr ll INF = 1LL<<60;

template<class t,class u> void chmax(t&a,u b){if(a<b)a=b;}
template<class t,class u> void chmin(t&a,u b){if(b<a)a=b;}

int dp[605][305][305];

int main(){
    int n, h; cin >> n >> h;
    vector<int> x(n+1); 
    rep(i, 1, n+1) cin >> x[i];
    vector<int> y(2*n+1);
    rep(i, 1, n+1){
        y[i] = x[i];
    }
    rep(i, n+1, 2*n+1){
        int j = n+(n+1-i)-1;
        y[i] = y[i-1]+(x[j+1]-x[j]);
    }


    vector<int> p(2*n+1), f(2*n+1);
    rep(i, 1, n) cin >> p[i] >> f[i];
    rep(i, n+1, 2*n){
        int j = n+(n+1-i)-1;
        p[i] = p[j];
        f[i] = f[j];
    }

    rep(i, 0, 605) rep(j, 0, 305) rep(k, 0, 305){
        dp[i][j][k] = IINF;
    }
    rep(j, 0, n+1) dp[0][j][h] = 0;
    rep(i, 0, 2*n){
        // i+1に到達したとき
        int d = y[i+1]-y[i];
        // 給油しない
        rep(k, d, h+1){
            chmin(dp[i+1][0][k-d], dp[i][0][k]);
        }
        
        if(i+1 <= n){
            rep(j, 1, n+1){
                if(i+1 == j){
                    rep(k, d, h+1){
                        chmin(dp[i+1][j][k-d], dp[i][j][k]);
                    }
                }else{
                    rep(k, d, h+1){
                        chmin(dp[i+1][j][k-d], dp[i][j][k]);
                        chmin(dp[i+1][j][min(k-d+f[i+1], h)], dp[i][j][k]+p[i+1]);
                    }
                }
            }
        }else{
            rep(j, 1, n+1){
                rep(k, d, h+1){
                    chmin(dp[i+1][j][k-d], dp[i][j][k]);
                    int tmp = n+(n+1-i-1)-1;
                    if(j == tmp) chmin(dp[i+1][j][min(k-d+f[i+1], h)], dp[i][j][k]+p[i+1]);
                }
            }
        }
    }
    int ans = IINF;
    rep(i, 0, n) rep(j, 0, h+1){
        chmin(ans, dp[2*n][i][j]);
    }
    if(ans == IINF) cout << -1 << endl;
    else cout << ans << endl;
    
    
    return 0;
}
