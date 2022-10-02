#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
const int MOD = 1000000007;
const int mod = 998244353;

// 問題
// https://atcoder.jp/contests/abc271/tasks/abc271_d

int main(){
    int n, s; cin >> n >> s;
    vector<int> a(n+1), b(n+1);
    rep(i, 1, n+1) cin >> a[i] >> b[i];

    vector<vector<vector<bool>>> dp(n+1, vector<vector<bool>>(s+1, vector<bool>(2)));
    dp[0][0][0] = true;
    dp[0][0][1] = true;
    rep(i, 1, n+1){
        rep(j, 1, s+1){
            if(j >= a[i]){
                dp[i][j][0] = (dp[i-1][j-a[i]][0] or dp[i-1][j-a[i]][1]);
            }
            if(j >= b[i]){
                dp[i][j][1] = (dp[i-1][j-b[i]][0] or dp[i-1][j-b[i]][1]);
            }
        }
    }

    if(dp[n][s][0] or dp[n][s][1]){
        cout << "Yes" << endl;
        string ans = "";
        if(dp[n][s][0]) ans += 'H';
        else ans += 'T';

        int s_ = s;
        for(int i = n-1; i >= 1; i--){
            if(ans[n-i-1] == 'H'){
                if(dp[i][s_-a[i+1]][0]) ans += 'H';
                else ans +=  'T';  
                s_ -= a[i+1];
            }else{
                if(dp[i][s_-b[i+1]][0]) ans += 'H';
                else ans += 'T';
                s_ -= b[i+1];
            }
        }
        reverse(ans.begin(), ans.end());
        cout << ans << endl;
    }else{
        cout << "No" << endl;
    }
    
    return 0;
}