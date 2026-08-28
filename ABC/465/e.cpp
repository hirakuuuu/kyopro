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

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    string s; cin >> s;
    int n = (int)s.size();

    vector<vector<vector<mint>>> dp(1<<10, vector<vector<mint>>(2, vector<mint>(3)));
    vector<vector<vector<mint>>> eq(1<<10, vector<vector<mint>>(2, vector<mint>(3)));
    // dp[0][0][0] = 1;
    rep(i, 1, s[0]-'0') dp[1<<i][(i==3)][i%3] = 1;
    eq[1<<(s[0]-'0')][(s[0]=='3')][(s[0]-'0')%3] = 1;

    rep(i, 1, n){
        int num = s[i]-'0';
        vector<vector<vector<mint>>> ndp(1<<10, vector<vector<mint>>(2, vector<mint>(3)));
        vector<vector<vector<mint>>> neq(1<<10, vector<vector<mint>>(2, vector<mint>(3)));
        rep(j, 0, 10){
            if(j > 0) ndp[1<<j][(j==3)][j%3] += 1;
            rep(ii, 1, 1<<10){
                rep(jj, 0, 2){
                    rep(kk, 0, 3){
                        int ni = ii|(1<<j);
                        int nj = (jj||(j==3) ? 1 : 0);
                        int nk = (kk+j)%3;
                        // cout << ii << ' ' << jj << ' ' << kk << ' ' << j << ": " << ni << ' ' << nj << ' ' << nk << endl;
                        ndp[ni][nj][nk] += dp[ii][jj][kk];
                        if(j < num) ndp[ni][nj][nk] += eq[ii][jj][kk];
                        if(j == num) neq[ni][nj][nk] += eq[ii][jj][kk];
                    }
                }
            }
        }

        swap(dp, ndp);
        swap(eq, neq);
    }

    mint ans = 0;
    rep(i, 1, 1<<10){
        rep(j, 0, 2){
            rep(k, 0, 3){
                if(__builtin_popcount(i) == 3 && !j && k != 0){
                    // cout << i << ' ' << j << ' ' << k << ' ' << dp[i][j][k].val() << ' ' << eq[i][j][k].val() << endl;
                    ans += dp[i][j][k]+eq[i][j][k];
                }
                if(__builtin_popcount(i) != 3 && j && k != 0){
                    // cout << i << ' ' << j << ' ' << k << ' ' << dp[i][j][k].val() << ' ' << eq[i][j][k].val() << endl;
                    ans += dp[i][j][k]+eq[i][j][k];
                }
                if(__builtin_popcount(i) != 3 && !j && k == 0){
                    // cout << i << ' ' << j << ' ' << k << ' ' << dp[i][j][k].val() << ' ' << eq[i][j][k].val() << endl;

                    ans += dp[i][j][k]+eq[i][j][k];
                }
            }
        }
    }
    cout << ans.val() << endl;
    return 0;
}