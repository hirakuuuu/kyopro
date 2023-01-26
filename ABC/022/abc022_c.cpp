#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
const int MOD_NUM = 1000000007;
const int mod_num = 998244353;

template<class t,class u> void chmax(t&a,u b){if(a<b)a=b;}
template<class t,class u> void chmin(t&a,u b){if(b<a)a=b;}

// 問題
// https://atcoder.jp/contests/abc022/tasks/abc022_c

vector<vector<int>> g(305, vector<int>(305, -1));
vector<vector<int>> e(305, vector<int>(305, -1));
vector<bool> closed(45005);
vector<vector<int>> seen(305);

vector<ll> dijk(int s){
    priority_queue<vector<ll>, vector<vector<ll>>, greater<vector<ll>>> que;
    vector<ll> dist(100005, (1LL<<60));
    que.push({0, s, -1});
    dist[s] = 0;
    while(!que.empty()){
        vector<ll> q = que.top(); que.pop();
        ll d = q[0], u = q[1], pre = q[2];
        if(dist[u] < d) continue;
        if(pre != -1){
            seen[u] = seen[pre];
            seen[u].push_back(e[pre][u]);
        }
        rep(v, 0, 305){
            if(g[u][v] >= 0 and dist[v] > d+g[u][v]){
                dist[v] = d+g[u][v];
                que.push({dist[v], v, u});
            }
        }
    }
    return dist;
}

vector<ll> dijk_(int s){
    priority_queue<vector<ll>, vector<vector<ll>>, greater<vector<ll>>> que;
    vector<ll> dist(100005, (1LL<<60));
    que.push({0, s, -1});
    dist[s] = 0;
    while(!que.empty()){
        vector<ll> q = que.top(); que.pop();
        ll d = q[0], u = q[1], pre = q[2];
        if(dist[u] < d) continue;
        rep(v, 0, 305){
            if(g[u][v] >= 0 and !closed[e[u][v]] and dist[v] > d+g[u][v]){
                dist[v] = d+g[u][v];
                que.push({dist[v], v, u});
            }
        }
    }
    return dist;
}


int main(){
    int n, m; cin >> n >> m;
    rep(i, 0, m){
        int u, v, l; cin >> u >> v >> l;
        g[u][v] = g[v][u] = l;
        e[u][v] = e[v][u] = i;
    }

    vector<ll> dist = dijk(1);
    vector<ll> dist_;
    ll ans = 1LL<<60;
    rep(i, 2, n+1){
        if(dist[i] == 1LL<<60) continue;
        ll tmp = dist[i];
        fill(closed.begin(), closed.end(), false);
        for(auto s: seen[i]){
            closed[s] = true;
        }
        dist_ = dijk_(i);
        chmin(ans, tmp+dist_[1]);
    }

    if(ans != 1LL<<60) cout << ans << endl;
    else cout << -1 << endl;



    
    return 0;
}