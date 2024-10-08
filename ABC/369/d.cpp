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
    vector<ll> a(n);

    vector<ll> dp(2);
    dp[0] = 0;
    dp[1] = -INF;
    rep(i, 0, n){
        cin >> a[i];
        vector<ll> dp_ = dp;
        chmax(dp_[0], dp[1]+a[i]*2); 
        chmax(dp_[1], dp[0]+a[i]); 
        swap(dp, dp_);
    }
    cout << max(dp[0], dp[1]) << endl;
    return 0;
}