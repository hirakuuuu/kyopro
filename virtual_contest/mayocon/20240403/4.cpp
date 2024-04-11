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
// 

int main(){
    int n, m, k; cin >> n >> m >> k;
    vector<vector<pair<int, int>>> g(n);
    rep(i, 0, m){
        int u, v, a; cin >> u >> v >> a;
        u--, v--;
        g[u].push_back({v, a});
        g[v].push_back({u, a});
    }

    vector<int> s(n);
    rep(i, 0, k){
        int b; cin >> b;
        b--;
        s[b] = 1;
    }

    queue<pair<int, int>> que;
    que.push({0, 1});
    vector<vector<ll>> dist(n, vector<ll>(2, INF));
    dist[0][1] = 0;
    while(!que.empty()){
        auto [pos, sw] = que.front(); que.pop();
        for(auto [nxt, st]: g[pos]){
            if(st != sw) continue;
            if(dist[nxt][sw] != INF) continue;
            dist[nxt][sw] = dist[pos][sw]+1;
            que.push({nxt, sw});
        }
        if(s[pos]){
            for(auto [nxt, st]: g[pos]){
                if(st == sw) continue;
                if(dist[nxt][1-sw] != INF) continue;
                dist[nxt][1-sw] = dist[pos][sw]+1;
                que.push({nxt, 1-sw});
            }
        }
    }
    
    ll ans = min(dist[n-1][0], dist[n-1][1]);
    if(ans == INF) cout << -1 << endl;
    else cout << ans << endl;

    return 0;
}