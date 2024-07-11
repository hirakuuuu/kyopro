#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define rrep(i, a, n) for(int i = a; i >= n; i--)
#define inr(l, x, r) (l <= x && x < r)
#define ll long long
#define ld long double

using mint = modint1000000007;
// using mint = modint998244353;
constexpr int IINF = 1001001001;
constexpr ll INF = 9e18;

template<class t,class u> void chmax(t&a,u b){if(a<b)a=b;}
template<class t,class u> void chmin(t&a,u b){if(b<a)a=b;}

int main(){
    int n, k; cin >> n >> k;
    vector<mint> dp(k+1);
    dp[k] = 1;
    mint ans = k;
    rrep(i, k-1, 1){
        dp[i] = mint(k/i).pow(n);
        for(int j = i+i; j <= k; j += i){
            dp[i] -= dp[j];
        }
        ans += dp[i]*i;
    }
    cout << ans.val() << endl;
    return 0;
}