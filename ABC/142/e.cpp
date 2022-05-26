#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
const int MOD = 1000000007;
const int mod = 998244353;

// 問題
// https://atcoder.jp/contests/abc142/tasks/abc142_e

int main(){
    int n, m; cin >> n >> m;
    vector<vector<int>> dp(m+1, vector<int>(1<<n, 1<<30));
    vector<pii> key(m+1);
    rep(i, 1, m+1){
        cin >> key[i].first;
        int b; cin >> b;
        rep(j, 0, b){
            int k; cin >> k;
            key[i].second += 1<<(k-1);
        }
    }

    dp[0][0] = 0;
    rep(i, 1, m+1){
        rep(j, 0, 1<<n){
            dp[i][j] = min(dp[i][j], dp[i-1][j]);
            dp[i][j|key[i].second] = min(dp[i][j|key[i].second], dp[i-1][j]+key[i].first);
        }
    }
    int ans = 0;
    rep(i, 0, n) ans += 1<<i;
    if(dp[m][ans] == 1<<30) cout << -1 << endl;
    else cout << dp[m][ans] << endl;
    
    return 0;
}