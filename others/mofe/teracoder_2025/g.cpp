#include <bits/stdc++.h>
// #include <atcoder/all>
using namespace std;
// using namespace atcoder;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define rrep(i, a, n) for(int i = a; i >= n; i--)
#define inr(l, x, r) (l <= x && x < r)
#define ll long long
#define ld long double

#pragma GCC target("avx2")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")

// using mint = modint1000000007;
// using mint = modint998244353;
constexpr int IINF = 1001001001;
constexpr ll INF = 1e18;

template<class t,class u> void chmax(t&a,u b){if(a<b)a=b;}
template<class t,class u> void chmin(t&a,u b){if(b<a)a=b;}

// sを始点とする各頂点への距離の最小値を格納した配列を返す
vector<int> dijk(int s, vector<vector<pair<int, int>>> &g){
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> que;
    vector<int> dist(g.size(), IINF);
    que.push(make_pair(0, s));
    dist[s] = 0;
    while(!que.empty()){
        pair<int, int> q = que.top(); que.pop();
        int d = q.first, u = q.second;
        if(dist[u] < d) continue;
        for(auto nq: g[u]){
            int v = nq.first, cost = nq.second;
            if(dist[v] > d+cost){
                dist[v] = d+cost;
                que.push({dist[v], v});
            }
        }
    }
    return dist;
}


int main(){
    ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, m; cin >> n >> m;
    vector<vector<pair<int, int>>> g(n);
    
    rep(i, 0, m){
        int a, b; cin >> a >> b;
        int c; cin >> c;
        a--, b--;
        g[a].emplace_back(b, c);
        g[b].emplace_back(a, c);
    }

    vector<int> d = dijk(0, g);
    rep(i, 0, d[n-1]){
        cout << "EHHO\n";
    }

    return 0;
}