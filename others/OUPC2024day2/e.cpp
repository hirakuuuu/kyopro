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


int main(){
    int n, k; cin >> n >> k;
    vector<ll> a(n);
    rep(i, 0, n) cin >> a[i];
    vector<ll> s(k);
    rep(i, 0, k) cin >> s[i];

    vector<ll> dp(k);
    rep(i, 0, k){
        dp[i] = abs(a[0]-s[i]);
    }

    rep(i, 1, n){
        vector<ll> ndp(k);
        rep(j, 0, k){
            // a[i] -> s[j] にする
            
        }
    }
    return 0;
}