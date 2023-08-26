#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define rrep(i, a, n) for(int i = a; i >= n; i--)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
// constexpr ll MOD = 1000000007;
constexpr ll MOD = 998244353;
constexpr int IINF = 1001001001;
constexpr ll INF = 1LL<<60;

template<class t,class u> void chmax(t&a,u b){if(a<b)a=b;}
template<class t,class u> void chmin(t&a,u b){if(b<a)a=b;}

// 問題
// https://atcoder.jp/contests/abc317/tasks/abc317_c

vector<ll> dijk(int s, vector<vector<pll>> &g){
    priority_queue<pll, vector<pll>, greater<pll>> que;
    vector<ll> dist(100005, (1LL<<60));
    que.push(make_pair(0, s));
    dist[s] = 0;
    while(!que.empty()){
        pll q = que.top(); que.pop();
        ll d = q.first, u = q.second;
        if(dist[u] < d) continue;
        for(auto nq: g[u]){
            ll v = nq.first, cost = nq.second;
            if(dist[v] > d+cost){
                dist[v] = d+cost;
                que.push({dist[v], v});
            }
        }
    }
    return dist;
}





int main(){
    ll n, m; cin >> n >> m;
    vector<vector<pll>> g(n);
    rep(i, 0, m){
        ll a, b, c; cin >> a >> b >> c;
        a--, b--;
        g[a].push_back({b, c});
        g[b].push_back({a, c});
    }

    ll ans = 0;
    vector<vector<ll>> dist(1<<n, vector<ll>(n, -1));
    queue<pair<int, ll>> que;
    rep(i, 0, n){
        que.push({i, (1<<i)});
        dist[(1<<i)][i] = 0;
    }

    while(!que.empty()){
        auto [pos, s] = que.front(); que.pop();
        for(auto e: g[pos]){
            auto [np, nc] = e;
            if((s&(1<<np)) > 0) continue;
            chmax(dist[s+(1<<np)][np], dist[s][pos]+nc);
            que.push({np, s+(1<<np)});
        }
    }

    rep(i, 0, (1<<n)){
        rep(j, 0, n){
            chmax(ans, dist[i][j]);
        }
    }
    cout << ans << endl;







    
    return 0;
}