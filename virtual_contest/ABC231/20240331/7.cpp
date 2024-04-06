#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define rrep(i, a, n) for(int i = a; i >= n; i--)
#define inr(l, x, r) (l <= x && x < r)
#define ll long long
#define ld long double
#define pii pair<int, int>
#define pll pair<ll, ll>
// constexpr ll MOD = 1000000007;
constexpr ll MOD = 998244353;
constexpr int IINF = 1001001001;
constexpr ll INF = 1LL<<60;

template<class t,class u> void chmax(t&a,u b){if(a<b)a=b;}
template<class t,class u> void chmin(t&a,u b){if(b<a)a=b;}

vector<ll> dijk(int s, vector<vector<pll>> &g){
    priority_queue<pll, vector<pll>, greater<pll>> que;
    vector<ll> dist(g.size(), (1LL<<60));
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
    vector<ll> a(n), b(n);
    vector<ll> M;
    rep(i, 0, n){
        cin >> a[i];
        M.push_back((m-a[i])%m);
    }
    rep(i, 0, n){
        cin >> b[i];
        M.push_back(b[i]);
    }
    sort(M.begin(), M.end());
    M.erase(unique(M.begin(), M.end()), M.end());
    map<ll, ll> id;
    int ind = n;
    for(auto mm: M) id[mm] = ind++;
    vector<vector<pair<ll, ll>>> g(n+M.size());
    rep(i, 0, n){
        g[i].push_back({id[(m-a[i])%m], 0LL});
        g[id[b[i]]].push_back({i, 0LL});
    }
    rep(i, 0, M.size()){
        ll dist = (M[(i+1)%M.size()]-M[i]+m)%m;
        g[id[M[i]]].push_back({id[M[(i+1)%M.size()]], dist});
    }
    vector<ll> dist = dijk(0, g);
    cout << dist[n-1] << endl;

    return 0;
}