#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
const int MOD = 1000000007;
const int mod = 998244353;

// 問題
// https://atcoder.jp/contests/abc202/tasks/abc202_e

vector<vector<int>> g(200005), in_depth(200005);
vector<int> depth(200005), in(200005), out(200005);

void dfs(int s, int &io){
    in[s] = io;
    in_depth[depth[s]].push_back(io);
    io++;
    for(auto &ns: g[s]){
        depth[ns] = depth[s]+1;
        dfs(ns, io);
    }
    out[s] = io;
    io++;
}

int main(){
    int n; cin >> n;
    rep(i, 2, n+1){
        int p; cin >> p;
        g[p].push_back(i);
    }
    int io = 0;
    dfs(1, io);
    int q; cin >> q;
    while(q--){
        int u, d; cin >> u >> d;
        int cnt = lower_bound(in_depth[d].begin(), in_depth[d].end(), out[u])-lower_bound(in_depth[d].begin(), in_depth[d].end(), in[u]);
        cout << cnt << "\n";
    }
    
    return 0;
}