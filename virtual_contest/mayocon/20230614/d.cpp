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

int main(){
    ll n, k, d; cin >> n >> k >> d;
    vector<ll> a(n+1);
    rep(i, 1, n+1) cin >> a[i];

    vector<vector<vector<ll>>> dp(n+1, vector<vector<ll>>(k+1, vector<ll>(d, -1)));
    dp[0][0][0] = 0;
    rep(i, 1, n+1){
        dp[i][0][0] = 0;
        rep(j, 0, k+1){
            rep(l, 0, d){
                chmax(dp[i][j][l], dp[i-1][j][l]);
                if(j < k && dp[i-1][j][l] >= 0){
                    chmax(dp[i][j+1][(l+a[i])%d], dp[i-1][j][l]+a[i]);
                }
            }
        }
    }

    cout << dp[n][k][0] << endl;
    
    return 0;
}