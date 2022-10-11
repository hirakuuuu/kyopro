#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
const int MOD = 1000000007;
const int mod = 998244353;

// 問題
// https://atcoder.jp/contests/abc183/tasks/abc183_e

int main(){
    int h, w; cin >> h >> w;
    vector<string> field(h+1);
    rep(i, 0, w+1) field[0] += '#';
    rep(i, 1, h+1){
        cin >> field[i];
        field[i] = '#'+field[i];
    }

    vector<vector<ll>> dp(h+1, vector<ll>(w+1));
    vector<vector<ll>> x(h+1, vector<ll>(w+1));
    vector<vector<ll>> y(h+1, vector<ll>(w+1));
    vector<vector<ll>> z(h+1, vector<ll>(w+1));
    dp[1][1] = 1;

    rep(i, 1, h+1){
        rep(j, 1, w+1){
            if(i*j == 1) continue;
            if(field[i][j] == '.'){
                x[i][j] = x[i][j-1]+dp[i][j-1];
                y[i][j] = y[i-1][j]+dp[i-1][j];
                z[i][j] = z[i-1][j-1]+dp[i-1][j-1];
                dp[i][j] = x[i][j]+y[i][j]+z[i][j];
                dp[i][j] %= MOD;
            }
        }
    }

    cout << dp[h][w] << endl;
    
    return 0;
}