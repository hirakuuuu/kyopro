#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define rrep(i, a, n) for(int i = a; i >= n; i--)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define tll tuple<ll, ll, ll>
// constexpr ll MOD = 1000000007;
constexpr ll MOD = 998244353;
constexpr int IINF = 1001001001;
constexpr ll INF = 1LL<<60;

template<class t,class u> void chmax(t&a,u b){if(a<b)a=b;}
template<class t,class u> void chmin(t&a,u b){if(b<a)a=b;}

// 問題
// https://atcoder.jp/contests/abc143/tasks/abc143_e

ll n, m, l;
vector<vector<pll>> g;
vector<pll> dijk(int s){
    priority_queue<tll, vector<tll>, greater<tll>> que;
    vector<pll> dist(100005, {(1LL<<60), 0});
    que.push({0, -l, s});
    dist[s] = {0, -l};
    while(!que.empty()){
        tll q = que.top(); que.pop();
        auto [cnt, energy, u] = q;
        energy = -energy;
        if(dist[u] < make_pair(cnt, -energy)) continue;
        for(auto nq: g[u]){
            ll v = nq.first, cost = nq.second;
            if(cost > energy){
                if(dist[v] > make_pair(cnt+1, -(l-cost))){
                    dist[v] = make_pair(cnt+1, -(l-cost));
                    que.push({cnt+1, -(l-cost), v});
                }
            }else{
                if(dist[v] > make_pair(cnt, -(energy-cost))){
                    dist[v] = make_pair(cnt, -(energy-cost));
                    que.push({cnt, -(energy-cost), v});
                }
            }
        }
    }
    return dist;
}

int main(){
    cin >> n >> m >> l;
    g.resize(n);
    vector<ll> a(m), b(m), c(m);
    rep(i, 0, m){
        cin >> a[i] >> b[i] >> c[i];
        if(c[i] > l) continue;
        a[i]--, b[i]--;
        g[a[i]].push_back({b[i], c[i]});
        g[b[i]].push_back({a[i], c[i]});
    } 

    vector<vector<pll>> dist(n);
    rep(i, 0, n){
        dist[i] = dijk(i);
    }

    int q; cin >> q;
    while(q--){
        ll s, t; cin >> s >> t;
        s--, t--;
        if(dist[s][t].first != INF) cout << dist[s][t].first << endl;
        else cout << -1 << endl;
    }



    
    return 0;
}