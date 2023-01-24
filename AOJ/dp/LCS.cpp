#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
const int MOD = 1000000007;
const int mod = 998244353;


/*

dp[i][j] = xのi文字目、yのj文字目までを使って作れる最大の最長共通部分列


dp[i][j] =  0                       (i == 0 or j == 0)
            dp[i-1][j-1]+1              (x[i] == y[j])
            max(dp[i-1][j], dp[i][j-1]) (x[i] != y[j])

*/


int main(){
    int q; cin >> q;
    vector<int> ans;
    while(q--){
        string x, y; cin >> x >> y;
        int nx = x.size(), ny = y.size();
        vector<vector<int>> dp(nx+1, vector<int>(ny+1));
        rep(i, 1, nx+1){
            rep(j, 1, ny+1){
                if(x[i-1] == y[j-1]){
                    dp[i][j] = dp[i-1][j-1]+1;
                }else{
                    dp[i][j] = max(dp[i][j-1], dp[i-1][j]);
                }
            }
        }
        ans.push_back(dp[nx][ny]);
    }
    for(auto aa: ans) cout << aa << endl;
}