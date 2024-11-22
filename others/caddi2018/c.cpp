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
正と負を切り替えるポイントを全探索する
このとき, 4倍するのを１回の操作として、広義単調増加にするのにかかる操作回数が計算できれば良い
これは dp[i][x] := a[i] -> a[i]*4^x としたときに, [i, n) を広義単調増加にするのにかかる操作回数の最小値 
としたDPが求まればよい. 
x は十分大きくなりえるが, x >= 15 のときは, 4^15 > 10^9 より, 
前の値に対する捜査が１回増えるごとに、後ろの値もすべてもう１回ずつ操作する必要が出てくるので, 
dp[i][x] = dp[i][15]+(x-15)*(n-i+1) として計算できる 
*/

int main(){
    int n; cin >> n;
    vector<ll> a(n);
    rep(i, 0, n) cin >> a[i];

    const int m = 15;

    vector<vector<ll>> dp(n, vector<ll>(m+1)), pd(n, vector<ll>(m+1));
    {
        rep(x, 0, m+1) dp[n-1][x] = x;
        rrep(i, n-2, 0) rep(x, 0, m+1){
            // a[i]*4^x <= a[i+1]*4^y となる最小の y を求める
            ll y = 0;
            if(a[i] >= a[i+1]){
                y = x;
                ll tmp = 1;
                while((a[i]+tmp-1)/tmp > a[i+1]) tmp *= 4, y++;
            }else{
                y = x;
                ll tmp = 1;
                while(a[i] <= a[i+1]/tmp) tmp *= 4, y--;
                y++;
                chmax(y, 0);
            }
            // cout << a[i] << ' ' << x << ' ' << a[i+1] << ' ' << y << endl;
            if(y <= m) dp[i][x] = dp[i+1][y]+x;
            else dp[i][x] = dp[i+1][m]+(n-1-i)*(y-m)+x;
        }
    }
    {
        rep(i, 0, n) a[i] *= 2;
        rep(x, 0, m+1) pd[0][x] = x;
        rep(i, 1, n) rep(x, 0, m+1){
            // a[i]*4^x <= a[i-1]*4^y となる最小の y を求める
            ll y = 0;
            if(a[i] >= a[i-1]){
                y = x;
                ll tmp = 1;
                while((a[i]+tmp-1)/tmp > a[i-1]) tmp *= 4, y++;
            }else{
                y = x;
                ll tmp = 1;
                while(a[i] <= a[i-1]/tmp) tmp *= 4, y--;
                y++;
                chmax(y, 0);
            }
            // cout << a[i] << ' ' << x << ' ' << a[i-1] << ' ' << y << endl;
            if(y <= m) pd[i][x] = pd[i-1][y]+x;
            else pd[i][x] = pd[i-1][m]+(y-m)*i+x;
        }
    }

    ll ans = min(dp[0][0]*2, pd[n-1][0]*2+n);
    rep(i, 1, n) chmin(ans, pd[i-1][0]*2+i+dp[i][0]*2);
    cout << ans << endl;
    
    return 0;
}