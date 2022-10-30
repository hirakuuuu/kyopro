#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
const int MOD = 1000000007;
const int mod = 998244353;

// 問題
// https://atcoder.jp/contests/abc245/tasks/abc245_f


vector<int> ans(200005), seen(200005);
vector<vector<int>> g(200005);
bool dfs(int pos){
    if(ans[pos] == 1) return true;
    if(ans[pos] == -1) return false;
    seen[pos] = 1;
    for(auto npos: g[pos]){
        if(ans[npos] == 1){
            ans[pos] = 1;
            seen[pos] = 0;
            return true;
        }
        if(seen[npos] == 1){
            ans[pos] = 1;
            seen[pos] = 0;
            return true;
        }
        if(dfs(npos)){
            ans[pos] = 1;
            seen[pos] = 0;
            return true;
        }
    }
    seen[pos] = 0;
    ans[pos] = -1;
    return false;
}

int main(){
    int n, m; cin >> n >> m;
    vector<int> u(m), v(m);
    rep(i, 0, m){
        cin >> u[i] >> v[i];
        g[u[i]].push_back(v[i]);
    }
    int cnt = 0;
    rep(i, 1, n+1){
        if(dfs(i)) cnt++;
    }
    cout << cnt << endl;
    return 0;
}