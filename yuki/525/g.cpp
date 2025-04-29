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
    vector<vector<int>> g(n);
    vector<int> x(m), y(m);
    rep(i, 0, m){
        cin >> x[i] >> y[i]; x[i]--, y[i]--;
        g[x[i]].push_back(y[i]);
        g[y[i]].push_back(x[i]);
    }
    vector<ll> A(n), FA(n);
    rep(i, 0, n) cin >> A[i], FA[i] = A[i];
    int q; cin >> q;
    vector<tuple<int, int, int>> query(q);
    rep(i, 0, q){
        int op; cin >> op;
        if(op == 1){
            int u, v; cin >> u >> v; u--, v--;
            g[u].push_back(v);
            g[v].push_back(u);
            query[i] = {op, u, v};
        }else if(op == 2){
            int p, val; cin >> p >> val; p--;
            query[i] = {op, p, val};
        }else{
            int c; cin >> c; c--;
            query[i] = {op, c, -1};
        }
    }

    vector<int> large(n);
    int thl = 350;
    rep(i, 0, n){
        sort(g[i].begin(), g[i].end());
        g[i].erase(unique(g[i].begin(), g[i].end()), g[i].end());
        if(g[i].size() >= thl){
            large[i] = true;
        }
    }

    vector<ll> sum(n), tot(n);
    map<pair<int, int>, bool> edge;
    vector<set<int>> ng(n);
    vector<set<int>> ng_large(n);
    rep(i, 0, m){
        sum[x[i]] += A[y[i]];
        sum[y[i]] += A[x[i]];
        edge[{x[i], y[i]}] = true;
        ng[x[i]].insert(y[i]);
        ng[y[i]].insert(x[i]);
        if(large[y[i]]) ng_large[x[i]].insert(y[i]);
        if(large[x[i]]) ng_large[y[i]].insert(x[i]);
    }


    rep(i, 0, q){
        auto [op, a, b] = query[i];
        if(op == 1){
            if(edge[{a, b}]){
                if(large[b]) sum[a] -= FA[b];
                else sum[a] -= A[b];
                if(large[a]) sum[b] -= FA[a];
                else sum[b] -= A[a];
                ng[a].erase(b);
                ng[b].erase(a);
                if(large[b]) ng_large[a].erase(b);
                if(large[a]) ng_large[b].erase(a);
            }else{
                if(large[b]) sum[a] += FA[b];
                else sum[a] += A[b];
                if(large[a]) sum[b] += FA[a];
                else sum[b] += A[a];
                ng[a].insert(b);
                ng[b].insert(a);
                if(large[b]) ng_large[a].insert(b);
                if(large[a]) ng_large[b].insert(a);
            }
            edge[{a, b}] = !edge[{a, b}];
        }else if(op == 2){
            if(large[a]){
                tot[a] -= A[a];
                tot[a] += b;
            }else{
                for(auto adj: ng[a]){
                    sum[adj] -= A[a];
                    sum[adj] += b;
                }
            }
            A[a] = b;
        }else{
            ll ans = sum[a];
            for(auto adj: ng_large[a]){
                ans += tot[adj];
            }
            cout << ans << endl;
        }
    }
    return 0;
}