#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define rrep(i, a, n) for(int i = a; i >= n; i--)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
const int MOD_NUM = 1000000007;
const int mod_num = 998244353;
const int iinf = 1001001001;

template<class t,class u> void chmax(t&a,u b){if(a<b)a=b;}
template<class t,class u> void chmin(t&a,u b){if(b<a)a=b;}

// 問題
// https://atcoder.jp/contests/abc298/tasks/abc298_e

ll power(ll a, ll b, ll m=998244353){
    ll res = 1;
    while(b > 0){
        if(b%2 == 1) res = res*a%m;
        a = a*a%m;
        b /= 2;
    }
    return res;
}

int main(){
    int n, a, b, p, q; cin >> n >> a >> b >> p >> q;
    vector<vector<ll>> dp_t(n+1, vector<ll>(n+1));
    vector<vector<ll>> dp_a(n+1, vector<ll>(n+1));
    dp_t[0][a] = 1;
    dp_a[0][b] = 1;

    rep(i, 1, n+1){
        rep(j, a, n){
            rep(k, 1, p+1){
                dp_t[i][min(n, j+k)] += dp_t[i-1][j]*power(p, mod_num-2)%mod_num;
                dp_t[i][min(n, j+k)] %= mod_num;
            }
        }
    }
    rep(i, 1, n+1){
        rep(j, b, n){
            rep(k, 1, q+1){
                dp_a[i][min(n, j+k)] += dp_a[i-1][j]*power(q, mod_num-2)%mod_num;
                dp_a[i][min(n, j+k)] %= mod_num;
            }
        }
    }
    
    ll ans = 0;
    rrep(i, n, 1){
        ans += dp_t[i][n]*dp_a[i][n];
        ans %= mod_num;
        dp_a[i-1][n] += dp_a[i][n];
        dp_a[i-1][n] %= mod_num;
    }
    cout << ans << endl;
    return 0;
}