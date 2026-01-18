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

int main(){
    int t; cin >> t;
    map<pair<int, int>, int> dist;
    map<pair<int, int>, int> eid;
    while(t--){
        int n, k; cin >> n >> k;
        vector<vector<int>> g(n);
        eid.clear();
        vector<pair<int, int>> edges;
        rep(i, 0, n-1){
            int u, v; cin >> u >> v;
            u--, v--;
            if(u > v) swap(u, v);
            g[u].push_back(v);
            g[v].push_back(u);
            eid[{u, v}] = 2*i;
            edges.push_back({u, v});
            eid[{v, u}] = 2*i+1;
            edges.push_back({v, u});
        }

        dist.clear();
        queue<pair<int, int>> que;
        rep(i, 0, 2*n-2){
            if(edges[i].second == 0){
                dist[{i, 0}] = 0;
                que.push({i, 0});
            }
        }
        while(!que.empty()){
            auto [q, d] = que.front(); que.pop();
            int v = edges[q].second;
            for(auto nq: g[v]){
                int id = eid[{v, nq}];
                if(dist.count({id, (d+1)%k})) continue;
                if(d > 0 && edges[q].first == nq) continue;
                dist[{id, (d+1)%k}] = dist[{q, d}]+1;
                que.push({id, (d+1)%k});
            }
        }

        vector<int> ans(n, IINF);
        rep(i, 0, 2*n-2){
            if(!dist.count({i, 0})) continue;
            chmin(ans[edges[i].second], dist[{i, 0}]/k);
        }
        rep(i, 1, n){
            if(ans[i] == IINF) cout << -1 << ' ';
            else cout << ans[i] << ' ';
        }
        cout << endl;
    }
    
    return 0;
}