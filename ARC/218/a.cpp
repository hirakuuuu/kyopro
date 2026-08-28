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
    int n, m; cin >> n >> m;
    vector<vector<int>> a(n, vector<int>(m));
    rep(i, 0, n){
        rep(j, 0, m){
            cin >> a[i][j]; a[i][j]--;
        }
    }

    vector<mint> dp(n*m), ndp(n*m);
    mint ans = 0;
    rep(i, 0, n){
        rep(j, 0, n*m){
            ndp[j] = dp[j]*m;
        }
        mint tot = mint(m).pow(i);
        rep(j, 0, m){
            ans += (tot-dp[a[i][j]])*mint(m).pow(n-1-i);
            ndp[a[i][j]] += tot-dp[a[i][j]];
        }
        swap(dp, ndp);

        // rep(j, 0, n*m){
        //     cout << dp[j].val() << ' ';
        // }
        // cout << endl;
        // cout << ans.val() << endl;
    }
    cout << ans.val() << endl;
    return 0;
}