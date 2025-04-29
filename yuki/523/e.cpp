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
    ll n, d, k; cin >> n >> d >> k;
    vector<ll> a(n);
    rep(i, 0, n) cin >> a[i];
    vector<ll> c(n);
    rep(i, 0, n) cin >> c[i];

    vector<vector<ll>> dp(d+1, vector<ll>(k+1, -INF));
    dp[0][0] = 0;
    rep(i, 0, n){
        rrep(j, d, 1){
            rrep(l, k, 0){
                if(dp[j-1][l] == -INF) continue;
                chmax(dp[j][min(k, (ll)c[i]+l)], dp[j-1][l]+a[i]);
            }
        }

        // rep(j, 0, d+1){
        //     rep(l, 0, k+1){
        //         cout << dp[j][l] << ' ';
        //     }
        //     cout << endl;
        // }
        // cout << endl;
    }
    if(dp[d][k] == -INF) cout << "No" << endl;
    else cout << dp[d][k] << endl;
    return 0;
}