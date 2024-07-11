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
    ll n, k; cin >> n >> k;
    vector<mint> dp(2);
    mint mn = n, mt = 2;
    mint p = (mn*mn-2*mn+2)/(mn*mn), q = mt/(mn*mn);
    dp[0] = 1;
    rep(i, 0, k){
        vector<mint> dp_ = dp;
        dp[0] = p*dp_[0]+q*(dp_[1]*(n-1));
        dp[1] = p*dp_[1]+q*(dp_[1]*(n-2)+dp_[0]);
    }
    mint ans = dp[0]+dp[1]*(n*(n+1)/2-1);
    cout << ans.val() << endl;
    
    return 0;
}