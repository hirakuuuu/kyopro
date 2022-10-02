#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
const int MOD = 1000000007;
const int mod = 998244353;

// 問題
// https://atcoder.jp/contests/tessoku-book/tasks/tessoku_book_q

int main(){
    int n; cin >> n;
    vector<int> a(n+1), b(n+1);
    rep(i, 2, n+1) cin >> a[i];
    rep(i, 3, n+1) cin >> b[i];

    vector<int> dp(n+1, 1000000007);
    dp[0] = 0;
    dp[1] = 0;
    dp[2] = a[2];
    rep(i, 3, n+1){
        dp[i] = min(dp[i-1]+a[i], dp[i-2]+b[i]);
    }

    vector<int> ans;
    int pos = n;
    while(pos > 0){
        if(dp[pos]-a[pos] == dp[pos-1]){
            ans.push_back(pos);
            pos--;
        }else if(dp[pos]-b[pos] == dp[pos-2]){
            ans.push_back(pos);
            pos -= 2;
        }
    }

    reverse(ans.begin(), ans.end());
    cout << ans.size() << endl;
    rep(i, 0, ans.size()){
        if(i > 0) cout << ' ';
        cout << ans[i];
    }
    cout << endl;
    
    return 0;
}