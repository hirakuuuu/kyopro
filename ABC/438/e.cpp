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
    int n, q; cin >> n >> q;
    vector<int> a(n);
    rep(i, 0, n){
        cin >> a[i];
        a[i]--;
    }

    vector<vector<pair<int, ll>>> dp(31, vector<pair<int, ll>>(n));
    rep(i, 0, n){
        dp[0][i] = {a[i], i+1};
    }
    rep(i, 1, 31){
        rep(j, 0, n){
            dp[i][j] = {dp[i-1][dp[i-1][j].first].first, dp[i-1][j].second+dp[i-1][dp[i-1][j].first].second};
        }
    }

    while(q--){
        int t, b; cin >> t >> b; b--;
        ll ans = 0;
        int tmp = b;
        rep(j, 0, 31){
            if((t>>j)&1){
                ans += dp[j][tmp].second;
                tmp = dp[j][tmp].first;
            }
        }
        cout << ans << endl;
    }


    return 0;
}