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
    int n, m; cin >> n >> m;
    vector<int> a(m+1);
    rep(i, 1, m+1) cin >> a[i];
    rep(i, 2, n+1){
        vector<vector<int>> dp(m+1, vector<int>(n+1, IINF));
        rep(j, 1, n+1) dp[0][j] = abs(i-j);
        rep(j, 1, m+1){
            rep(k, 1, n+1){
                if(k != a[j] && k != a[j]+1){
                    chmin(dp[j][k], dp[j-1][k]);
                }else if(k == a[j]){
                    chmin(dp[j][k], dp[j-1][k+1]);
                }else{
                    chmin(dp[j][k], dp[j-1][k-1]);
                }
            }
            int mi = dp[j][1];
            rep(k, 2, n+1){
                mi++;
                chmin(dp[j][k], mi);
                chmin(mi, dp[j][k]);
            }
            mi = dp[j][n];
            rrep(k, n, 1){
                mi++;
                chmin(dp[j][k], mi);
                chmin(mi, dp[j][k]);
            }
        }
        cout << dp[m][1] << ' ';
    }
    cout << endl;

    return 0;
}