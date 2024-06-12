#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define rrep(i, a, n) for(int i = a; i >= n; i--)
#define inr(l, x, r) (l <= x && x < r)
#define ll long long
#define ld long double

// using mint = modint1000000007;
using mint = modint998244353;
constexpr int IINF = 1001001001;
constexpr ll INF = 9e18;

template<class t,class u> void chmax(t&a,u b){if(a<b)a=b;}
template<class t,class u> void chmin(t&a,u b){if(b<a)a=b;}

int main(){
    int n, s; cin >> n >> s;
    vector<int> a(n);
    rep(i, 0, n) cin >> a[i];

    vector<vector<mint>> dp(n+1, vector<mint>(s+1));
    dp[0][0] = 1;
    rep(i, 0, n){
        rep(k, 0, s+1){
            dp[i+1][k] += dp[i][k];
            if(k+a[i] <= s) dp[i+1][k+a[i]] += dp[i][k]/mint(2);
        }
    }
    cout << (dp[n][s]*mint(2).pow(n)).val() << endl;

    
    return 0;
}