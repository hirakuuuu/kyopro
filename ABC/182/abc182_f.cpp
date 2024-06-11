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
    int n;
    ll x; cin >> n >> x;
    vector<ll> a(n);
    rep(i, 0, n) cin >> a[i];

    vector<map<ll, ll>> dp(n+1);
    dp[0][x] = 1;
    rep(i, 0, n){
        if(i == n-1){
            for(auto [key, val]: dp[n-1]){
                dp[n][0] += val;
            }
        }else{
            for(auto [key, val]: dp[i]){
                dp[i+1][key-(key%a[i+1])] += val;
                if(key%a[i+1] > 0) dp[i+1][key+(a[i+1]-(key%a[i+1]))] += val;
            }
        }
    }
    cout << dp[n][0] << endl;

    
    return 0;
}