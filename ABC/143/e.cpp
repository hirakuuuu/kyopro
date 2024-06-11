#include <bits/stdc++.h>
// #include <atcoder/all>
using namespace std;
// using namespace atcoder;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define rrep(i, a, n) for(int i = a; i >= n; i--)
#define inr(l, x, r) (l <= x && x < r)
#define ll long long
#define ld long double

// using mint = modint1000000007;
// using mint = modint998244353;
constexpr int IINF = 1001001001;
constexpr ll INF = 9e18;

template<class t,class u> void chmax(t&a,u b){if(a<b)a=b;}
template<class t,class u> void chmin(t&a,u b){if(b<a)a=b;}

// sを始点とする各頂点への距離の最小値を格納した配列を返す
vector<pair<ll, ll>> dijk(int s, ll l, vector<vector<pair<ll, ll>>> &g){
    priority_queue<pair<pair<ll, ll>, ll>, vector<pair<pair<ll, ll>, ll>>, greater<pair<pair<ll, ll>, ll>>> que;
    vector<pair<ll, ll>> dist(g.size(), {INF, INF});
    que.push({{0LL, -l}, (ll)s});
    dist[s] = {0LL, -l};
    while(!que.empty()){
        pair<pair<ll, ll>, ll> q = que.top(); que.pop();
        ll cnt = q.first.first, rest = q.first.second;
        ll u = q.second;
        rest *= -1;
        if(dist[u] < q.first) continue;
        for(auto nq: g[u]){
            ll v = nq.first, cost = nq.second;
            if(l < cost) continue;
            if(rest < cost){
                if(dist[v] > make_pair(cnt+1, -(l-cost))){
                    dist[v] = {cnt+1, -(l-cost)};
                    que.push({dist[v], v});
                }
            }else{
                if(dist[v] > make_pair(cnt, -(rest-cost))){
                    dist[v] = {cnt, -(rest-cost)};
                    que.push({dist[v], v});
                }
            }
        }
    }
    return dist;
}

int main(){
    int n, m, l; cin >> n >> m >> l;
    vector<vector<pair<ll, ll>>> g(n);
    rep(i, 0, m){
        int a, b, c; cin >> a >> b >> c;
        a--, b--;
        g[a].push_back({b, c});
        g[b].push_back({a, c});
    }
    vector<vector<pair<ll, ll>>> d(n);
    rep(i, 0, n){
        d[i] = dijk(i, l, g);
    }
    int q; cin >> q;
    while(q--){
        int u, v; cin >> u >> v;
        u--, v--;
        if(d[u][v].first == INF) cout << -1 << endl;
        else cout << d[u][v].first << endl;
    }

    
    return 0;
}