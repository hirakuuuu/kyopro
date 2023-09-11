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

int main(){
    int t; cin >> t;
    while(t--){
        int n, m; cin >> n >> m;
        vector<int> c(n);
        rep(i, 0, n) cin >> c[i];

        vector<vector<int>> g(n);
        rep(i, 0, m){
            int u, v; cin >> u >> v;
            u--, v--;
            g[u].push_back(v);
            g[v].push_back(u);
        }

        vector<vector<int>> dist(n, vector<int>(n, -1));
        dist[0][n-1] = 0;
        queue<pair<int, int>> que;
        que.push({0, n-1});
        while(!que.empty()){
            auto [t, a] = que.front(); que.pop();
            for(auto nt: g[t]){
                for(auto na: g[a]){
                    if(dist[nt][na] != -1) continue;
                    if(c[nt] == c[na]) continue;
                    dist[nt][na] = dist[t][a]+1;
                    que.push({nt, na});
                }
            }
        }
        cout << dist[n-1][0] << '\n';
    }
    return 0;
}