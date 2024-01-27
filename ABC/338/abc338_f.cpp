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
// https://atcoder.jp/contests/abc338/tasks/abc338_f

vector<vector<pair<ll, ll>>> graph(30);
vector<ll> dijk(int s){
    priority_queue<vector<ll>, vector<vector<ll>>, greater<vector<ll>>> que;
    vector<ll> dist(30, 1e18);
    que.push({0, s, -1});
    dist[s] = 0;
    while(!que.empty()){
        vector<ll> q = que.top(); que.pop();
        ll d = q[0], u = q[1], p = q[2];
        if(dist[u] < d) continue;
        for(auto nq: graph[u]){
            ll v = nq.first, cost = nq.second;
            if(v == p || dist[v] <= d+cost) continue;
            dist[v] = d+cost;
            que.push({dist[v], v, u});
        }
    }
    return dist;
}

int main(){
    int n, m; cin >> n >> m;
    vector<int> g(n);
    vector<vector<ll>> e(n, vector<ll>(n));
    rep(i, 0, m){
        int u, v, w; cin >> u >> v >> w;
        u--, v--;
        g[u] += (1<<v);
        e[u][v] = w;
        graph[u].push_back({v, w});
    }
    vector<vector<ll>> dist(n);
    rep(i, 0, n) dist[i] = dijk(i);

    vector<vector<ll>> dp((1<<n), vector<ll>(n, 1e18));
    rep(i, 0, n) dp[1<<i][i] = 0;
    rep(i, 0, 1<<n){
        rep(j, 0, n){
            rep(k, 0, n){
                if((i>>j)&1 && !((i>>k)&1)){
                    if(dp[i][j] == 1e18 || dist[j][k] == 1e18) continue;
                    chmin(dp[i+(1<<k)][k], dp[i][j]+dist[j][k]);
                }
            }
        }
    }

    ll ans = 1e18;
    rep(i, 0, n) chmin(ans, dp[(1<<n)-1][i]);
    if(ans == 1e18) cout << "No" << endl;
    else cout << ans << endl;
    
    return 0;
}