#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
const int MOD = 1000000007;
const int mod = 998244353;

// 問題
// https://atcoder.jp/contests/abc270/tasks/abc270_c

vector<vector<int>> g(200005);
vector<int> path;

bool dfs(int s, int pre, int y){
    if(s == y){
        path.push_back(s);
        return true;
    }

    for(auto ns: g[s]){
        if(ns == pre) continue;
        if(dfs(ns, s, y)){
            path.push_back(s);
            return true;
        }
    }

    return false;

}

int main(){
    int n, x, y; cin >> n >> x >> y;

    rep(i, 0, n-1){
        int u, v; cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    bool f = dfs(x, -1, y);
    rep(i, 0, path.size()){
        if(i) cout << " ";
        cout << path[path.size()-i-1];
    }
    cout << endl;



    
    return 0;
}