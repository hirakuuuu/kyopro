#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define rrep(i, a, n) for(int i = a; i >= n; i--)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
constexpr ll MOD = 1000000007;
constexpr int IINF = 1001001001;
constexpr ll INF = 1LL<<60;

template<class t,class u> void chmax(t&a,u b){if(a<b)a=b;}
template<class t,class u> void chmin(t&a,u b){if(b<a)a=b;}

// 問題
// https://atcoder.jp/contests/arc108/tasks/arc108_d

int main(){
    int n; cin >> n;
    vector<int> c(4);
    rep(i, 0, 4){
        char C; cin >> C;
        c[i] = C-'A';
    }

    vector<int> l(4), r(4);
    rep(i, 0, 4){
        l[i] = (i&2)+c[i];
        r[i] = c[i]*2+(i&1);
    }

    vector<vector<vector<ll>>> dp(n+1, vector<vector<ll>>(n+1, vector<ll>(4)));
    dp[2][2][1] = 1;
    rep(i, 2, n){
        rep(j, 2, i+1){
            rep(k, 0, 4){
                dp[i+1][j][l[k]] += dp[i][j][k];
                dp[i+1][j][l[k]] %= MOD;
                dp[i+1][j+1][r[k]] += dp[i][j][k];
                dp[i+1][j][r[k]] %= MOD;

                if(i > 2) dp[i+1][j][k] += dp[i][j][k];
                dp[i+1][j][k] %= MOD;
            }
        }
    }


    rep(i, 0, n+1){
        rep(j, 0, 4){
            cout << dp[n][i][j] << ' ';
        }
        cout << endl;
    }
    
    ll ans = 0;
    rep(i, 0, 4){
        rep(j, 2, n+1){
            ans += dp[n][n][i];
            ans %= MOD;
        }
    }


    cout << ans << endl;
    return 0;
}