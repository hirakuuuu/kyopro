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

int main(){
    int n; cin >> n;
    vector<ll> a(n);

    rep(i, 0, n){
        cin >> a[i];
    }

    ll ans = INF;
    ll sum_a = 0;
    vector<ll> sa(n+1);
    rep(i, 0, n){
        sum_a += a[i];
        sa[i+1] = sa[i]+a[i];
    }

    ll m = 0, l = 0;
    if(sum_a >= 0){
        m = sum_a%n;
        l = sum_a/n;
    }else{
        m = (n+sum_a%n)%n;
        l = (sum_a+n-1)/n-1;
    }

    vector<vector<ll>> dp(n+1, vector<ll>(n+1, INF));
    dp[0][0] = 0;
    rep(i, 1, n){
        rep(j, 0, i){
            ll tmp_a = a[i-1]+(sa[i-1]-(j*(l+1)+(i-1-j)*l));
            if(tmp_a >= l) chmin(dp[i][j], dp[i-1][j]+(tmp_a-l));
            else chmin(dp[i][j], dp[i-1][j]+(l-tmp_a));
            if(tmp_a >= l+1) chmin(dp[i][j+1], dp[i-1][j]+(tmp_a-l+1));
            else chmin(dp[i][j+1], dp[i-1][j]+(l+1-tmp_a));
        }
        //if(_ == 1) cout << dp[i][0] << ' ' << dp[i][1] << ' ' << dp[i][2] << endl;
    }
    if(m == 0) chmin(ans, dp[n-1][m]);
    else chmin(ans, min(dp[n-1][m-1], dp[n-1][m]));
    cout << ans << endl;




    
    return 0;
}