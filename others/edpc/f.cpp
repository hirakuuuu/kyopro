#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
const int MOD = 1000000007;
const int mod = 998244353;

// 問題
// https://atcoder.jp/contests/edpc/tasks/dp_f

int main(){
    string s, t; cin >> s >> t;
    vector<vector<int>> dp(s.size()+1, vector<int>(t.size()+1));
    rep(i, 1, s.size()+1){
        rep(j, 1, t.size()+1){
            if(s[i-1] == t[j-1]) dp[i][j] = dp[i-1][j-1]+1;
            else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        }
    }

    string ans;
    int ss = s.size(), tt = t.size();
    int len = dp[ss][tt];
    while(len){
        if(s[ss-1] == t[tt-1]){
            ans += s[ss-1];
            ss--;
            tt--;
            len--;
        }else if(dp[ss][tt] == dp[ss-1][tt]) ss--;
        else tt--;
    }
    reverse(ans.begin(), ans.end());
    cout << ans << endl;
    return 0;
}