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
// https://atcoder.jp/contests/zone2021/tasks/zone2021_e

vector<int> dijk(vector<vector<pair<int, int>>> &g, int s){
    priority_queue<pii, vector<pii>, greater<pii>> que;
    vector<int> dist(g.size(), 1e9);
    que.push(make_pair(0, s));
    dist[s] = 0;
    while(!que.empty()){
        pii q = que.top(); que.pop();
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
    int r, c; cin >> r >> c;
    vector<vector<pair<int, int>>> g(r*c+c+100);
    rep(i, 1, r+1){
        rep(j, 1, c){
            int a; cin >> a;
            g[i*c+j].push_back({i*c+j+1, a});
            g[i*c+j+1].push_back({i*c+j, a});
        }
    }
    rep(i, 1, r){
        rep(j, 1, c+1){
            int b; cin >> b;
            g[i*c+j].push_back({(i+1)*c+j, b});
        }
    }
    rep(i, 1, r+1){
        rep(j, 1, c+1){
            rep(k, 1, i){
                g[i*c+j].push_back({(i-k)*c+j, 1+k});
            }
        }
    }

    vector<int> ans = dijk(g, c+1);
    cout << ans[r*c+c] << endl;
    
    return 0;
}