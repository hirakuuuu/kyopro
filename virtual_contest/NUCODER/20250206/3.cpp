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
constexpr ll INF = 1e18;

template<class t,class u> void chmax(t&a,u b){if(a<b)a=b;}
template<class t,class u> void chmin(t&a,u b){if(b<a)a=b;}

int main(){
    int n, m, k; cin >> n >> m >> k;

    vector<mint> dp(m+1);
    rep(i, 1, m+1) dp[i] = 1;
    rep(i, 1, n){
        mint tot = 0;
        rep(j, 1, m+1) tot += dp[j];
        vector<mint> ndp(m+1);
        ndp[0] = tot;

        rep(j, 1, m+1){
            if(k > 0){
                ndp[max(1, j-k+1)] -= dp[j];
                if(j+k <= m) ndp[j+k] += dp[j];
            }
        }
        rep(j, 1, m+1){
            ndp[j] += ndp[j-1];
        }
        swap(dp, ndp);
        // rep(j, 0, m+1){
        //     cout << dp[j].val() << endl;
        // }
    }

    mint ans = 0;
    rep(i, 1, m+1) ans += dp[i];
    cout << ans.val() << endl;
    return 0;
}