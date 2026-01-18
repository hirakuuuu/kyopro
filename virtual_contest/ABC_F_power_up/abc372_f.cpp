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
// using mint2 = modint998244353;
constexpr int IINF = 1001001001;
constexpr ll INF = 9e18;
constexpr ll MOD = 998244353;

template<class t,class u> void chmax(t&a,u b){if(a<b)a=b;}
template<class t,class u> void chmin(t&a,u b){if(b<a)a=b;}


int main(){
    int n, m, k; cin >> n >> m >> k;
    vector<int> x(m), y(m);
    rep(i, 0, m){
        cin >> x[i] >> y[i], x[i]--, y[i]--;
    }

    vector<ll> dp(n);
    dp[0] = 1;
    rep(i, 0, k){
        vector<ll> pre(m);
        rep(j, 0, m){
            pre[j] = dp[(x[j]-i%n+n)%n];
        }
        rep(j, 0, m){
            dp[(y[j]-i%n-1+n)%n] += pre[j];
            dp[(y[j]-i%n-1+n)%n] %= MOD;
        }
    }
    ll ans = 0;
    rep(i, 0, n){
        ans += dp[i];
        ans %= MOD;
    }
    
    cout << ans << endl;
    


    return 0;
}