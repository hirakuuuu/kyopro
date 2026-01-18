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
    vector<vector<int>> g(n);
    rep(i, 0, m){
        int u, v; cin >> u >> v; u--, v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    vector<int> a(n);
    rep(i, 0, n){
        cin >> a[i];
    }
    vector<int> b(k);
    rep(i, 0, k){
        cin >> b[i];
    }

    vector<int> dist(n, IINF);
    dist[0] = 0;
    if(a[0] == b[0]) dist[0] = 1;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> que;
    que.push({dist[0], 0});
    while(!que.empty()){
        auto [d, pre] = que.top(); que.pop();
        // cout << pre << ' ' << dist[pre] << ' ' << d << endl;
        if(dist[pre] < d) continue;
        for(auto nxt: g[pre]){
            int cost = 0;
            if(d < k && b[d] == a[nxt]) cost = 1;
            // cout << nxt << ' ' << dist[nxt] << ' ' << d+cost << endl;
            if(dist[nxt] <= d+cost) continue;
            dist[nxt] = d+cost;
            que.push({d+cost, nxt});
        }
    }
    // rep(i, 0, n){
    //     cout << dist[i] << endl;
    // }
    if(dist[n-1] == k) cout << "Yes" << endl;
    else cout << "No" << endl;

    return 0;
}