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
using mint = modint998244353;
constexpr int IINF = 1001001001;
constexpr ll INF = 1e18;

template<class t,class u> void chmax(t&a,u b){if(a<b)a=b;}
template<class t,class u> void chmin(t&a,u b){if(b<a)a=b;}

mint dp[41][41][41][11][11];

int main(){
    int n, m; cin >> n >> m;
    vector<string> s(n);
    rep(i, 0, n) cin >> s[i];

    rep(i, 0, 41) rep(j, 0, 41) rep(k, 0, 41) rep(l, 0, 11) rep(r, 0, 11){
        dp[i][j][k][l][r] = 0;
        if(i == m && k-j <= 1) dp[i][j][k][l][r] = 1;
        if(j == k) dp[i][j][k][l][r] = 1;
    }

    rrep(i, m-1, 0){
        rep(g, 1, n+1){
            rep(l, 0, n+1){
                int r = l+g;
                if(r > n) break;
                rep(j, 0, 11) rep(k, j+1, 11){
                    // dp[i][l][r][j][k]
                    if(s[l][i] == '?'){
                        rep(o, j, k) rep(nr, l+1, r+1){
                            if(s[nr-1][i] != '?' && s[nr-1][i]-'0' != o) break;
                            dp[i][l][r][j][k] += dp[i+1][l][nr][0][10]*dp[i][nr][r][o+1][k];
                        }
                    }else{
                        int tmp = s[l][i]-'0';
                        if(inr(j, tmp, k)){
                            rep(nr, l+1, r+1){
                                if(s[nr-1][i] != '?' && s[nr-1][i]-'0' != tmp) break;
                                dp[i][l][r][j][k] += dp[i+1][l][nr][0][10]*dp[i][nr][r][tmp+1][k];
                            }
                        }
                    }
                    // cout << i << ' ' << l << ' ' << r << ' ' << j << ' ' << k << ' ' << dp[i][l][r][j][k].val() << endl;
                }
            }
        }
    }
    cout << dp[0][0][n][0][10].val() << endl;

    

    
    return 0;
}