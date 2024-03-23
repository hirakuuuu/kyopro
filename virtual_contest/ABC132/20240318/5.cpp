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
    int n, m; cin >> n >> m;
    vector<vector<int>> g(n);
    rep(i, 0, m){
        int u, v; cin >> u >> v;
        u--, v--;
        g[u].push_back(v);
    }
    vector<vector<int>> dist(n, vector<int>(3, -1));
    int s, t; cin >> s >> t;
    s--, t--;
    dist[s][2] = 0;
    queue<pair<int, int>> que;
    que.push({s, 2});
    while(!que.empty()){
        auto [q, r] = que.front(); que.pop();
        int nr = (r+1)%3;
        for(auto nq: g[q]){
            if(dist[nq][nr] != -1) continue;
            dist[nq][nr] = dist[q][r]+1;
            que.push({nq, nr});
        }
    }
    if(dist[t][2] != -1) cout << dist[t][2]/3 << endl;
    else cout << -1 << endl;
    return 0;
}