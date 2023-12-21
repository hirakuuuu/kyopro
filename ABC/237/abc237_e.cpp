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
// https://atcoder.jp/contests/abc237/tasks/abc237_e
// sを始点とする各頂点への距離の最小値を格納した配列を返す
vector<vector<pair<ll, ll>>> g(200005);
vector<ll> dijk(int s){
    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> que;
    vector<ll> dist(200005, (1LL<<60));
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
    vector<ll> h(n);
    rep(i, 0, n) cin >> h[i];
    rep(i, 0, m){
        int u, v; cin >> u >> v;
        u--, v--;
        if(h[u] >= h[v]){
            g[u].push_back({v, 0});
            g[v].push_back({u, h[u]-h[v]});
        }else{
            g[u].push_back({v, h[v]-h[u]});
            g[v].push_back({u, 0});
        }
    }
    vector<ll> dist = dijk(0);
    ll ans = 0;
    rep(i, 0, n){
        chmax(ans, max(0LL, h[0]-h[i])-dist[i]);
    }
    cout << ans << endl;
    
    return 0;
}