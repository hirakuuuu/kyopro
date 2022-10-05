#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
const int MOD = 1000000007;
const int mod = 998244353;

// 問題
// https://atcoder.jp/contests/tessoku-book/tasks/tessoku_book_y

int main(){
    int h, w; cin >> h >> w;
    vector<string> a(h);
    rep(i, 0, h) cin >> a[i];

    vector<vector<ll>> dp(h, vector<ll>(w)); 
    dp[0][0] = 1;

    rep(i, 0, h){
        rep(j, 0, w){
            if(a[i][j] == '.'){
                if(i > 0) dp[i][j] += dp[i-1][j];
                if(j > 0) dp[i][j] += dp[i][j-1];
            }
        }
    }   

    cout << dp[h-1][w-1] << endl;
    return 0;
}