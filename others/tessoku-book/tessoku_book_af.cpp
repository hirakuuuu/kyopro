#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
const int MOD = 1000000007;
const int mod = 998244353;

// 問題
// https://atcoder.jp/contests/tessoku-book/tasks/tessoku_book_af

int main(){
    int n, a, b; cin >> n >> a >> b;
    vector<int> dp(n+1);

    rep(i, 1, n+1){
        if(i >= a and dp[i-a] == 0) dp[i] = 1;
        if(i >= b and dp[i-b] == 0) dp[i] = 1;
    }

    if(dp[n] == 1) cout << "First" << endl;
    else cout << "Second" << endl;
    
    return 0;
}