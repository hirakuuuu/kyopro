#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
const int MOD = 1000000007;
const int mod = 998244353;

// 問題
// https://atcoder.jp/contests/abc276/tasks/abc276_b

int main(){
    int n, m; cin >> n >> m;
    vector<vector<int>> g(n+1);
    rep(i, 0, m){
        int a, b; cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    rep(i, 1, n+1){
        cout << g[i].size();
        sort(g[i].begin(), g[i].end());
        for(auto &gg: g[i]){
            cout << ' ' << gg;
        }
        cout << '\n';
    }
    
    return 0;
}