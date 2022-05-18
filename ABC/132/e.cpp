#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
const int MOD = 1000000007;
const int mod = 998244353;

// 問題
// https://atcoder.jp/contests/abc132/tasks/abc132_e

vector<vector<int>> g(100005);
vector<vector<int>> dist(100005, vector<int>(3, -1));

void bfs(int s){
    dist[s][0] = 0;
    queue<pii> que;
    que.push({s, 0});
    while(!que.empty()){
        pii q = que.front(); que.pop();
        for(auto nq: g[q.first]){
            if(dist[nq][(q.second+1)%3] >= 0) continue;
            dist[nq][(q.second+1)%3] = q.second+1;
            que.push({nq, q.second+1});
        }
    }
}

int main(){
    int n, m; cin >> n >> m;
    map<pii, int> exist;
    rep(i, 0, m){
        int u, v; cin >> u >> v;
        if(exist[{u, v}]) continue;
        exist[{u, v}] = 1;
        g[u].push_back(v);
    }
    int s, t; cin >> s >> t;
    bfs(s);
    if(dist[t][0] >= 0) cout << dist[t][0]/3 << endl;
    else cout << dist[t][0] << endl;

    return 0;
}