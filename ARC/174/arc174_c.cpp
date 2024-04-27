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
    int n; cin >> n;
    vector<vector<mint>> dp(2, vector<mint>(n+1));
    mint inv_n = mint(n).inv(), mn = n;
    dp[0][n] = dp[1][n] = 0;
    rrep(i, n-1, 0){
        mint c = mint(i)*inv_n;
        mint cc = (-c*c+1).inv();
        dp[0][i] = cc*(c+c*(-c+1)*dp[0][i+1]+(-c+1)*dp[1][i+1]);
        dp[1][i] = c*dp[0][i]+(-c+1)*(dp[0][i+1]);
    }
    cout << dp[0][0].val() << ' ' << dp[1][0].val() << endl;
    
    return 0;
}