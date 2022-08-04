#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
const int MOD = 1000000007;
const int mod = 998244353;

// 問題
// https://atcoder.jp/contests/abc262/tasks/abc262_b

int main(){
    int n, m; cin >> n >> m;
    vector<vector<int>> g(n, vector<int>(n));
    rep(i, 0, m){
        int u, v; cin >> u >> v;
        u--, v--;
        g[u][v] = g[v][u] = 1;
    }

    int ans = 0;

    rep(i, 0, n){
        rep(j, i+1, n){
            rep(k, j+1, n){
                ans += g[i][j]&g[j][k]&g[i][k];
            }
        }
    }

    cout << ans << endl;
    
    return 0;
}