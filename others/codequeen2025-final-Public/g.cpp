#include <bits/stdc++.h>
// #include <atcoder/all>
using namespace std;
// using namespace atcoder;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define rrep(i, a, n) for(int i = a; i >= n; i--)
#define inr(l, x, r) (l <= x && x < r)
#define tl tuple<ll, ll, ll>
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
    vector<ll> dist(g.size(), (1LL<<60));
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
    int n, m, k; cin >> n >> m >> k;
    k -= 2;
    vector<int> a(k);
    int dummy; cin >> dummy;
    rep(i, 0, k){
        cin >> a[i]; a[i]--;
    }
    cin >> dummy;


    vector<vector<pair<ll, ll>>> g(n);
    vector<int> u(m), v(m);
    vector<ll> cost(m);
    rep(i, 0, m){
        cin >> u[i] >> v[i]; u[i]--, v[i]--;
        cin >> cost[i];
        g[u[i]].push_back({v[i], cost[i]});
        g[v[i]].push_back({u[i], cost[i]});

        if(u[i] == 0) u[i] = n;
        if(v[i] == n-1) v[i] = n+1;
    }

    vector<ll> d0 = dijk(0, g);
    vector<ll> dn = dijk(n-1, g);

    ll ans = INF;
    rep(_, 0, 100){
        vector<int> s1, s2;
        rep(i, 0, k){
            if(rand()%2 == 0) s1.push_back(a[i]);
            else s2.push_back(a[i]);
        }
        if(s1.empty() || s2.empty()) continue;

        vector<vector<pair<ll, ll>>> ng(n+2);
        rep(i, 0, s1.size()){
            ng[0].push_back({s1[i], d0[s1[i]]});
        }
        rep(i, 0, s2.size()){
            ng[s2[i]].push_back({n-1, dn[s2[i]]});
        }
        rep(i, 0, m){
            ng[u[i]].push_back({v[i], cost[i]});
            ng[v[i]].push_back({u[i], cost[i]});
        }

        vector<ll> d = dijk(0, ng);
        chmin(ans, d[n-1]);
    }
    cout << ans << endl;


    return 0;
}