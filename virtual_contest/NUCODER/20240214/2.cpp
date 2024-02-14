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
    vector<ll> t(n+1), x(n+1), a(n+1);
    rep(i, 1, n+1){
        cin >> t[i] >> x[i] >> a[i];
    }
    vector<ll> dp(n+1, -1);
    dp[0] = 0;
    rep(i, 1, n+1){
        rep(j, 1, 51){
            if(i-j < 0) break;
            if(dp[i-j] != -1 && abs(x[i-j]-x[i]) <= t[i]-t[i-j]) chmax(dp[i], dp[i-j]+a[i]);
        }
    }
    ll ans = 0;
    rep(i, 1, n+1) chmax(ans, dp[i]);
    cout << ans << endl;
    


    return 0;
}