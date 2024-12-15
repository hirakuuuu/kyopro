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
    int n, m; cin >> n >> m;
    vector<int> d(n);
    rep(i, 0, n) cin >> d[i];
    vector<vector<int>> g(n);
    map<pair<int, int>, int> eid;
    rep(i, 0, m){
        int u, v; cin >> u >> v; u--, v--;
        g[u].push_back(v);
        g[v].push_back(u);
        eid[{u, v}] = eid[{v, u}] = i;
    }

    vector<int> to(n, IINF);
    rep(u, 0, n){
        int mi = IINF;
        for(auto v: g[u]){
            if(d[u] >= d[v]){
                if(d[v] <= mi && v < to[u]){
                    to[u] = v;
                    mi = d[v];
                }
            }
        }
        if(to[u] == IINF){
            cout << -1 << endl;
            return 0;
        }
    }

    vector<int> id(n);
    iota(id.begin(), id.end(), 0);
    sort(id.begin(), id.end(), [&](int i, int j){
        return d[i] < d[j];
    });

    // vector<bool> seen(n);
    vector<int> col(n, -1), weight(m, 1e9);
    rep(i, 0, n){
        int u = id[i];
        if(col[u] != -1) continue;
        if(d[u] == d[to[u]]){
            weight[eid[{u, to[u]}]] = d[u];
            if(col[to[u]] != -1){
                col[u] = 1-col[to[u]];
            }else{
                col[u] = 0;
                col[to[u]] = 1;
            }
        }else{
            col[u] = col[to[u]];
            weight[eid[{u, to[u]}]] = d[u]-d[to[u]];
        }
    }

    rep(i, 0, n) cout << (col[i] ? "B" : "W");
    cout << endl;
    rep(i, 0, m) cout << weight[i] << endl;
    
    return 0;
}