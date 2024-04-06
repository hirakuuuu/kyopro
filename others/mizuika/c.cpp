#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define rrep(i, a, n) for(int i = a; i >= n; i--)
#define inr(l, x, r) (l <= x && x < r)
#define ll long long
#define ld long double
#define pii pair<int, int>
#define pll pair<ll, ll>
// constexpr ll MOD = 1000000007;
constexpr ll MOD = 998244353;
constexpr int IINF = 1001001001;
constexpr ll INF = 1LL<<60;

template<class t,class u> void chmax(t&a,u b){if(a<b)a=b;}
template<class t,class u> void chmin(t&a,u b){if(b<a)a=b;}

vector<ll> dijk(int s, vector<vector<pll>> &g){
    priority_queue<pll, vector<pll>, greater<pll>> que;
    vector<ll> dist(g.size(), (1LL<<60));
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
    int n, m; cin >> n >> m;
    vector<int> c(m);
    vector<ll> d(m);
    rep(i, 0, m) cin >> c[i];
    rep(i, 0, m) cin >> d[i];
    vector<vector<int>> a(m);
    rep(i, 0, m){
        a[i].resize(c[i]);
        rep(j, 0, c[i]){
            cin >> a[i][j];
            a[i][j]--;
        }
    }
    vector<vector<pair<ll, ll>>> g(n+m);
    rep(i, 0, m){
        int doumei = i+n;
        rep(j, 0, c[i]){
            g[a[i][j]].push_back({doumei, 0LL});
            g[doumei].push_back({a[i][j], d[i]});
        }
    }
    vector<ll> dist = dijk(0, g);
    rep(i, 1, n){
        if(dist[i] == INF) cout << -1 << endl;
        else cout << dist[i] << endl;
    }


    return 0;
}