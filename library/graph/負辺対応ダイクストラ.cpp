#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
const int MOD = 1000000007;
const int mod = 998244353;

vector<ll> a(100005);
vector<vector<pll>> g(100005);

// sを始点とする各頂点への距離の最小値を格納した配列を返す
// 負の辺に対応するために、一つ前の要素を記録しておく
vector<ll> dijk(int s){
    priority_queue<vector<ll>, vector<vector<ll>>, greater<vector<ll>>> que;
    vector<ll> dist(100005, (1LL<<60));
    que.push({0, s, -1});
    dist[s] = 0;
    while(!que.empty()){
        vector<ll> q = que.top(); que.pop();
        ll d = q[0], u = q[1], p = q[2];
        if(dist[u] < d) continue;
        for(auto nq: g[u]){
            ll v = nq.first, cost = nq.second;
            if(v == p || dist[v] <= d+cost) continue;
            dist[v] = d+cost;
            que.push({dist[v], v, u});
        }
    }
    return dist;
}

int main(){
    int n, m; cin >> n >> m;
    rep(i, 0, m){
        int u, v, c; cin >> u >> v >> c;
        g[u].push_back({v, c});
        g[v].push_back({u, c});
    }

    vector<ll> d = dijk(1);
    rep(i, 1, n+1){
        cout << d[i] << endl;
    }
    
    return 0;
}