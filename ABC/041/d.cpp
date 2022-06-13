#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
const int MOD = 1000000007;
const int mod = 998244353;

// 問題
// https://atcoder.jp/contests/abc041/tasks/abc041_d

vector<vector<bool>> bad(17, vector<bool>(17, false));

int main(){
    int n, m; cin >> n >> m;
    rep(i, 0, m){
        int x, y; cin >> x >> y;
        x--, y--;
        bad[y][x] = true;
    }

    vector<ll> dp((1<<n)+1);
    dp[0] = 1;
    rep(i, 0, 1<<n){
        rep(j, 0, n){
            if(!(i&(1<<j))){
                bool ok = true;
                rep(k, 0, n){
                    if(i&(1<<k) and bad[k][j]) ok = false;
                }
                if(ok) dp[i+(1<<j)] += dp[i];
            }
        }
    }
    cout << dp[(1<<n)-1] << endl;
    
    return 0;
}