#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
const int MOD = 1000000007;
const int mod = 998244353;

// 問題
// https://atcoder.jp/contests/dp/tasks/dp_p

vector<vector<int>> g(100005);
vector<vector<ll>> dp(100005, vector<ll>(2));

/**
 c = 0  白
 c = 1　黒
*/
ll dfs(int s, int pre, int c){
    if(dp[s][c] > 0) return dp[s][c];
    ll res = 1;
    for(auto ns: g[s]){
        if(ns == pre) continue;
        if(c == 0){
            res *= (dfs(ns, s, 0)+dfs(ns, s, 1));
        }else{
            res *= dfs(ns, s, 0);
        }
        res %= MOD;
    }

    return dp[s][c] = res;
}

int main(){
    int n; cin >> n;
    rep(i, 0, n-1){
        int x, y; cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    cout << (dfs(1, 0, 0)+dfs(1, 0, 1))%MOD << endl;

    return 0;
}