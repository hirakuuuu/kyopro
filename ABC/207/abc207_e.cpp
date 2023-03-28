#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define rrep(i, a, n) for(int i = a; i >= n; i--)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
const int MOD = 1000000007;
const int mod_num = 998244353;
const int iinf = 1001001001;

template<class t,class u> void chmax(t&a,u b){if(a<b)a=b;}
template<class t,class u> void chmin(t&a,u b){if(b<a)a=b;}

// 問題
// https://atcoder.jp/contests/abc207/tasks/abc207_e

int main(){
    ll n; cin >> n;
    vector<ll> a(n+1), sa(n+1);
    rep(i, 1, n+1) cin >> a[i];
    rep(i, 1, n+1) sa[i] = sa[i-1] + a[i];

    vector<vector<ll>> sm(n+1, vector<ll>(n+1));
    vector<vector<ll>> fi(n+1, vector<ll>(n+1));
    rep(i, 1, n+1){
        vector<ll> f(n);
        rep(j, 1, n+1){
            sm[i][j] = sa[j]%i;
            fi[i][j] = f[sm[i][j]];
            f[sm[i][j]] = j;
        }
    }

    vector<vector<ll>> dp(n+1, vector<ll>(n+1));
    rep(i, 1, n+1){
        dp[1][i] = 1;
    }
    rep(i, 2, n+1){
        rep(j, 1, n+1){
            dp[i][j] = (dp[i-1][fi[i][j]]+dp[i][fi[i][j]])%MOD;
        }
    }

    // rep(i, 1, n+1){
    //     rep(j, 1, n+1){
    //         cout << dp[i][j] << ' ';
    //     }
    //     cout << endl;
    // }

    ll ans = 0;
    rep(i, 1, n+1){
        ans += dp[i][n];
        ans %= MOD;
    }
    cout << ans << endl;
    
    return 0;
}