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
vector<ll> dijk(int s, vector<vector<pair<ll, ll>>> &g){
    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> que;
    vector<ll> dist(g.size(), INF);
    que.push(make_pair(0, s));
    dist[s] = 0;
    while(!que.empty()){
        pair<ll, ll> q = que.top(); que.pop();
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
    int n, m; cin >> n >> m;
    vector<int> x(m), y(m);
    vector<ll> c(m);
    rep(i, 0, m){
        cin >> x[i] >> y[i] >> c[i]; x[i]--, y[i]--;
    }

    if(x[0] == y[0]){
        cout << c[0] << endl;
        return 0;
    }

    vector<vector<pair<ll, ll>>> g(n);
    rep(i, 0, m){
        if(x[i] == y[i]) continue;
        g[x[i]].push_back({y[i], c[i]});
    }
    vector<ll> dist = dijk(y[0], g);
    if(dist[x[0]] == INF) cout << -1 << endl;
    else cout << dist[x[0]]+c[0] << endl;



    
    return 0;
}