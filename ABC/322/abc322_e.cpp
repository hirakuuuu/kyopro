#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define rrep(i, a, n) for(int i = a; i >= n; i--)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
// constexpr ll MOD = 1000000007;
constexpr ll MOD = 998244353;
constexpr int IINF = 1001001001;
constexpr ll INF = 1LL<<60;

template<class t,class u> void chmax(t&a,u b){if(a<b)a=b;}
template<class t,class u> void chmin(t&a,u b){if(b<a)a=b;}

// 問題
// https://atcoder.jp/contests/abc322/tasks/abc322_e

ll dp[105][6][6][6][6][6];

int main(){
    int n, k, p; cin >> n >> k >> p;
    vector<ll> c(n+1);
    vector<vector<int>> a(n+1, vector<int>(5));
    rep(i, 1, n+1){
        cin >> c[i];
        rep(j, 0, k) cin >> a[i][j];
    }
    rep(i, 0, n+1){
        rep(j1, 0, 6) rep(j2, 0, 6) rep(j3, 0, 6) rep(j4, 0, 6) rep(j5, 0, 6){
            dp[i][j1][j2][j3][j4][j5] = 1e18;
        }
    }

    dp[0][0][0][0][0][0] = 0;
    rep(i, 1, n+1){
        rep(j1, 0, 6) rep(j2, 0, 6) rep(j3, 0, 6) rep(j4, 0, 6) rep(j5, 0, 6){
            chmin(dp[i][j1][j2][j3][j4][j5], dp[i-1][j1][j2][j3][j4][j5]);
            int k1 = min(5, j1+a[i][0]);
            int k2 = min(5, j2+a[i][1]);
            int k3 = min(5, j3+a[i][2]);
            int k4 = min(5, j4+a[i][3]);
            int k5 = min(5, j5+a[i][4]);
            chmin(dp[i][k1][k2][k3][k4][k5], dp[i-1][j1][j2][j3][j4][j5]+c[i]);
        }
    }

    vector<int> mini(5);
    rep(i, 0, k) mini[i] = p;


    ll ans = 1e18;
    rep(j1, mini[0], 6) rep(j2, mini[1], 6) rep(j3, mini[2], 6) rep(j4, mini[3], 6) rep(j5, mini[4], 6){
        chmin(ans, dp[n][j1][j2][j3][j4][j5]);
    }
    if(ans != 1e18) cout << ans << endl;
    else cout << -1 << endl;

    


    
    return 0;
}