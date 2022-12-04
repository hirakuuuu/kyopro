#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
const int MOD = 1000000007;
const int mod = 998244353;

// 問題
// https://atcoder.jp/contests/arc056/tasks/arc056_b

vector<vector<int>> g(200005);
vector<bool> able(200005);
vector<int> seen(200005, 1e9);


// sを始点とする各頂点への距離の最小値を格納した配列を返す
vector<ll> dijk(int s){
    priority_queue<pll> que;
    vector<ll> dist(200005, 0);
    que.push(make_pair(s, s));
    dist[s] = s;
    while(!que.empty()){
        pll q = que.top(); que.pop();
        ll d = q.first, u = q.second;
        if(dist[u] > d) continue;
        for(auto v: g[u]){
            if(dist[v] < min(d, (ll)v)){
                dist[v] = min(d, (ll)v);
                que.push({dist[v], v});
            }
        }
    }
    return dist;
}


int main(){
    int n, m, s; cin >> n >> m >> s;
    rep(i, 0, m){
        int u, v; cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    vector<ll> dist = dijk(s);
    rep(i, 1, n+1){
        if(dist[i] == i) cout << i << endl;
    }
    
    return 0;
}