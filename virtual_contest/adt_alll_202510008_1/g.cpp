#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define rep(i, a, n) for(ll i = a; i < n; i++)
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
    int n; cin >> n;
    vector<ll> a(n);
    rep(i, 0, n) cin >> a[i];
    mint ans = 0;
    rep(l, 1, n+1){
        // l 個取ると決める
        vector<vector<mint>> dp(l+1, vector<mint>(l));
        dp[0][0] = 1;
        rep(i, 0, n){
            vector<vector<mint>> ndp = dp;
            ndp[1][a[i]%l] += 1;
            rep(j, 1, l){
                rep(k, 0, l){
                    ndp[j+1][(k+a[i])%l] += dp[j][k];
                }
            }
            swap(ndp, dp);

        }
        ans += dp[l][0];
    }

    cout << ans.val() << endl;

    
    return 0;
}