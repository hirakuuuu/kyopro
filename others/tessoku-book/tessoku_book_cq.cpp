#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
const int MOD = 1000000007;
const int mod = 998244353;

// 問題
// https://atcoder.jp/contests/tessoku-book/tasks/tessoku_book_cq

int main(){
    int n, s; cin >> n >> s;
    vector<int> a(n+1);
    rep(i, 1, n+1) cin >> a[i];

    vector<vector<bool>> dp(n+1, vector<bool>(s+1));
    dp[0][0] = true;
    rep(i, 1, n+1){
        rep(j, 0, s+1){
            if(j >= a[i]){
                dp[i][j] = (dp[i-1][j-a[i]] or dp[i-1][j]);
            }else{
                dp[i][j] = dp[i-1][j];
            }
        }
    }

    if(dp[n][s]){
        int pos = n, total = s;
        vector<int> ans;
        while(pos > 0 and total > 0){
            while(dp[pos-1][total]) pos--;
            ans.push_back(pos);
            total -= a[pos];
        }
        reverse(ans.begin(), ans.end());
        cout << ans.size() << endl;
        rep(i, 0, ans.size()){
            if(i > 0) cout << ' ';
            cout << ans[i];
        }
        cout << endl;
    }else{
        cout << -1 << endl;
    }

    return 0;
}