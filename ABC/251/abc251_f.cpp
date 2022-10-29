#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
const int MOD = 1000000007;
const int mod = 998244353;

// 問題
// https://atcoder.jp/contests/abc251/tasks/abc251_f

vector<vector<int>> g(200005);
vector<pii> t1, t2;
vector<int> seen(200005);

void dfs(int pos){
    seen[pos] = 1;
    for(auto &nxt: g[pos]){
        if(seen[nxt]) continue;
        t1.push_back({pos, nxt});
        dfs(nxt);
    }
}

void bfs(int start){
    queue<int> que;
    que.push(start);
    seen[start] = 1;
    while(!que.empty()){
        int q = que.front(); que.pop();
        for(auto &nxt: g[q]){
            if(seen[nxt]) continue;
            t2.push_back({q, nxt});
            que.push(nxt);
            seen[nxt] = 1;
        }
    }
}

int main(){
    int n, m; cin >> n >> m;
    rep(i, 0, m){
        int u, v; cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    // dfs木
    dfs(1);

    fill(seen.begin(), seen.end(), 0);

    // bfs木
    bfs(1);

    for(auto &tt: t1){
        cout << tt.first << " " << tt.second << "\n";
    }
    for(auto &tt: t2){
        cout << tt.first << " " << tt.second << "\n";
    }
    
    return 0;
}