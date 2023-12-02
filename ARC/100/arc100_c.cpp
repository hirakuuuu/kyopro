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
// https://atcoder.jp/contests/arc100/tasks/arc100_c

/*
高速ゼータ変換

*/

int main(){
    int n; cin >> n;
    vector<ll> a(1<<n);
    rep(i, 0, 1<<n) cin >> a[i];

    vector<vector<pair<ll, ll>>> dp(1<<n, vector<pair<ll, ll>>(n+1));
    rep(i, 0, 1<<n) dp[i][0] = {a[i], 0LL};

    rep(j, 0, n){
        rep(i, 0, 1<<n){
            if((i>>j)&1){
                auto [M1, m1] = dp[i&~(1<<j)][j];
                auto [M2, m2] = dp[i][j];
                dp[i][j+1] = {max(M1, M2), max({min(M1, M2), m1, m2})};
            }else{
                dp[i][j+1] = dp[i][j];
            }
        }
    }

    ll ans = 0;
    rep(i, 1, 1<<n){
        chmax(ans, dp[i][n].first+dp[i][n].second);
        cout << ans << '\n';
    }
    
    return 0;
}