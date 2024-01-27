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
    int n, m, k; cin >> n >> m >> k;
    vector<int> a(n+1), b(m+1);
    rep(i, 1, n+1) cin >> a[i];
    rep(i, 1, m+1) cin >> b[i];
    vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(m+1, vector<int>(2)));
    dp[0][0][0] = dp[0][0][1] = 0;
    rep(i, 0, n+1){
        rep(j, 0, m+1){
            if(i < n) dp[i+1][j][0] = max(dp[i][j][0]+(a[i]!=a[i+1] ? 1: 0), dp[i][j][1]+(b[j]!=a[i+1] ? 1: 0));
            if(j < m) dp[i][j+1][1] = max(dp[i][j][0]+(a[i]!=b[j+1] ? 1: 0), dp[i][j][1]+(b[j]!=b[j+1] ? 1: 0));
        }
    }
    cout << max(dp[n][m][0], dp[n][m][1]) << endl;
    return 0;
}