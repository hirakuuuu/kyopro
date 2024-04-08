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

int main(){
    int n; cin >> n;
    vector<ld> p(n);
    rep(i, 0, n) cin >> p[i];

    vector<ld> dp(n+1, 0.0);
    dp[0] = 1.0;
    rep(i, 0, n){
        vector<ld> dp_ = dp;
        rep(j, 0, n+1){
            dp[j] = dp_[j]*(1.0-p[i]);
            if(j > 0) dp[j] += dp_[j-1]*p[i];
        }
    }
    ld ans = 0;
    rep(i, 0, n+1){
        if(i > n-i) ans += dp[i];
    }
    cout << setprecision(20) << ans << endl;
    return 0;
}