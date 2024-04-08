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

vector<ll> dijkstra(int s, vector<vector<tuple<ll, ll, ll>>> &g){
    vector<ll> dist(g.size(), INF);
    dist[s] = 0;
    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> que;
    que.push({0LL, s});
    while(!que.empty()){
        auto [cost, now] = que.top(); que.pop();
        if(cost > dist[now]) continue;
        for(auto [nxt, time, K]: g[now]){
            ll start = (K-cost%K)%K;
            if(cost+start+time >= dist[nxt]) continue;
            dist[nxt] = cost+start+time;
            que.push({dist[nxt], nxt});
        }
    }
    return dist;
}


int main(){
    ll n, m, x, y; cin >> n >> m >> x >> y;
    x--, y--;
    vector<vector<tuple<ll, ll, ll>>> g(n);
    rep(i, 0, m){
        ll a, b, t, k; cin >> a >> b >> t >> k;
        a--, b--;
        g[a].push_back({b, t, k});
        g[b].push_back({a, t, k});
    }
    vector<ll> ans = dijkstra(x, g);
    // rep(i, 0, n){
    //     cout << ans[i] << endl;
    // }
    if(ans[y] == INF) cout << -1 << endl;
    else cout << ans[y] << endl;
    return 0;
}