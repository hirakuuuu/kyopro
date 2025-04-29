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
vector<vector<ll>> dijk(int s, ll x, vector<vector<pair<ll, ll>>> &g1, vector<vector<pair<ll, ll>>> &g2){
    priority_queue<pair<ll, pair<int, int>>, vector<pair<ll, pair<int, int>>>, greater<pair<ll, pair<int, int>>>> que;
    vector<vector<ll>> dist(g1.size(), vector<ll>(2, INF));
    que.push({0LL, {s, 0}});
    dist[s][0] = 0;
    while(!que.empty()){
        auto [d, q] = que.top(); que.pop();
        auto [u, t] = q;
        if(dist[u][t] < d) continue;
        for(auto [v, cost]: g1[u]){
            if(t == 0){
                if(dist[v][t] > d+cost){
                    dist[v][t] = d+cost;
                    que.push({dist[v][t], {v, t}});
                }
            }else{
                if(dist[v][1-t] > d+cost+x){
                    dist[v][1-t] = d+cost+x;
                    que.push({dist[v][1-t], {v, 1-t}});
                }    
            }
        }
        for(auto [v, cost]: g2[u]){
            if(t == 1){
                if(dist[v][t] > d+cost){
                    dist[v][t] = d+cost;
                    que.push({dist[v][t], {v, t}});
                }
            }else{
                if(dist[v][1-t] > d+cost+x){
                    dist[v][1-t] = d+cost+x;
                    que.push({dist[v][1-t], {v, 1-t}});
                }    
            }
        }
    }
    return dist;
}


int main(){
    int n, m; cin >> n >> m;
    ll x; cin >> x;
    vector<vector<pair<ll, ll>>> g1(n);
    vector<vector<pair<ll, ll>>> g2(n);
    rep(i, 0, m){
        int u, v; cin >> u >> v;
        u--, v--;
        g1[u].push_back({v, 1});
        g2[v].push_back({u, 1});
    }

    vector<vector<ll>> d = dijk(0, x, g1, g2);
    cout << min(d[n-1][0], d[n-1][1]) << endl;
    return 0;
}