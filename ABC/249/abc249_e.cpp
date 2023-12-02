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
// https://atcoder.jp/contests/abc249/tasks/abc249_e

ll power(ll a, ll b, ll m=MOD){
    ll res = 1;
    while(b > 0){
        if(b%2 == 1) res = res*a%m;
        a = a*a%m;
        b /= 2;
    }
    return res;
}

int main(){
    ll n, p; cin >> n >> p;
    vector<vector<ll>> dp(n+1, vector<ll>(n+1));
    vector<vector<ll>> sum(n+5, vector<ll>(n+5));
    dp[0][0] = (power(25, p-2, p)*26)%p;
    rep(i, 1, n+1) sum[0][i] = dp[0][0];
    vector<ll> ten = {1, 10, 100, 1000, 10000, 100000};
    rep(i, 1, n+1){
        rep(j, 1, n+1){
            rep(k, 1, 5){
                if(i-k-1 < 0) continue;
                ll x = max(0LL, j-(ten[k-1]-1)), y = max(0LL, j-(ten[k]-1));
                dp[i][j] += (sum[i-k-1][x]-sum[i-k-1][y]+p)*25;
                dp[i][j] %= p;
            }
            sum[i][j+1] = sum[i][j]+dp[i][j];
            sum[i][j+1] %= p;
        }
    }

    ll ans = 0;
    rep(i, 1, n){
        ans += dp[i][n];
        ans %= p;
    }
    cout << ans << endl;
    
    return 0;
}