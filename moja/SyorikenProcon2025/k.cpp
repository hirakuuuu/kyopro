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
constexpr ll MOD = 4736947;

template<class t,class u> void chmax(t&a,u b){if(a<b)a=b;}
template<class t,class u> void chmin(t&a,u b){if(b<a)a=b;}

int main(){
    int n, m; cin >> n >> m;
    vector<int> c(n);
    rep(i, 0, n){
        cin >> c[i]; c[i]--;
    }

    vector<int> dp(n, IINF);
    dp[0] = 0;

    int k; cin >> k;
    rep(i, 0, k){
        int t; cin >> t; t--;
        vector<int> ndp(n, IINF);
        int mi = IINF;
        rep(j, 0, 2*n){
            chmin(mi, dp[j%n]);
            if(c[j%n] == t){
                chmin(ndp[j%n], mi);
            }
            mi++;
        }
        rrep(j, 2*n-1, 0){
            chmin(mi, dp[j%n]);
            if(c[j%n] == t){
                chmin(ndp[j%n], mi);
            }
            mi++;
        }
        swap(dp, ndp);
        // rep(j, 0, n){
        //     cout << dp[j] << ' ';
        // }
        // cout << endl;
    }

    int ans = IINF;
    rep(i, 0, n) chmin(ans, dp[i]);
    cout << ans << endl;

    return 0;
}