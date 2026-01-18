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
constexpr ll INF = 1e18;

template<class t,class u> void chmax(t&a,u b){if(a<b)a=b;}
template<class t,class u> void chmin(t&a,u b){if(b<a)a=b;}



// sを始点とする各頂点への距離の最小値を格納した配列を返す
vector<ll> dijk(int s, vector<vector<tuple<ll, ll, ll>>> &g){
    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> que;
    vector<ll> dist(g.size(), INF);
    que.push(make_pair(0, s));
    dist[s] = 0;
    while(!que.empty()){
        pair<ll, ll> q = que.top(); que.pop();
        ll d = q.first, u = q.second;
        if(dist[u] < d) continue;
        for(auto [v, k, cost]: g[u]){
            ll need = (k-d%k)%k;

            if(dist[v] > d+need+cost){
                dist[v] = d+need+cost;
                que.push({dist[v], v});
            }
        }
    }
    return dist;
}

int main(){
    int n, m; cin >> n >> m;
    int x, y; cin >> x >> y; x--, y--;
    vector<vector<tuple<ll, ll, ll>>> g(n);
    rep(i, 0, m){
        int a, b; cin >> a >> b; a--, b--;
        ll k, t; cin >> t >> k;
        g[a].push_back({b, k, t});
        g[b].push_back({a, k, t});
    }

    vector<ll> d = dijk(x, g);
    if(d[y] == INF) cout << -1 << endl;
    else cout << d[y] << endl;

    return 0;
}