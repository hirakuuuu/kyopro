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
constexpr ll INF = 9e18;

template<class t,class u> void chmax(t&a,u b){if(a<b)a=b;}
template<class t,class u> void chmin(t&a,u b){if(b<a)a=b;}

int main(){
    int n; cin >> n;
    vector<ll> a(1<<n);
    rep(i, 0, 1<<n) cin >> a[i];

    vector<pair<ll, ll>> dp(1<<n);
    rep(i, 0, 1<<n) dp[i] = {a[i], 0};
    rep(i, 0, n){
        rep(x, 0, 1<<n){
            if((x>>i)&1){
                auto [a1, a2] = dp[x];
                auto [b1, b2] = dp[x-(1<<i)];
                if(a1 < b1) swap(a1, b1);
                dp[x] = {a1, max({a2, b1, b2})};
            }
        }
    }
    
    ll ans = 0;
    rep(i, 1, 1<<n){
        chmax(ans, dp[i].first+dp[i].second);
        cout << ans << endl; 
    }
    return 0;
}