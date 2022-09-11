#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
const int MOD = 1000000007;
const int mod = 998244353;

// 問題
// https://atcoder.jp/contests/dp/tasks/dp_g

vector<vector<int>> g(100005);
vector<int> dp(100005, 0);
vector<bool> flag(100005);

int f(int x){
    if(flag[x]) return dp[x];
    flag[x] = true;

    for(auto nx: g[x]){
        dp[x] = max(f(nx)+1, dp[x]);
    }

    return dp[x];
}

int main(){
    int n, m; cin >> n >> m;
    rep(i, 0, m){
        int x, y; cin >> x >> y;
        g[x].push_back(y);
    }

    int ans = 0;

    rep(i, 1, n+1){
        ans = max(f(i), ans);
    }

    cout << ans << endl;
    
    return 0;
}