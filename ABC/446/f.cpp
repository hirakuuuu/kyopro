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
    rep(i, 0, m){
        int u, v; cin >> u >> v; u--, v--;
        if(u == v) continue;
        g[u].push_back(v);
    }
    rep(i, 0, n){
        sort(g[i].begin(), g[i].end());
        g[i].erase(unique(g[i].begin(), g[i].end()), g[i].end());
    }
    vector<int> seen(n, -1);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> que;
    que.push({0, 0});
    seen[0] = 0;
    while(!que.empty()){
        auto [d, q] = que.top(); que.pop();
        if(seen[q] != d) continue;
        for(auto nq: g[q]){
            if(seen[nq] != -1) continue;
            seen[nq] = max(nq, d);
            que.push({seen[nq], nq});
        }
    }

    vector<int> ans(n, -1);
    ans[0] = (int)g[0].size();
    int mx = 0;
    set<int> s;
    rep(i, 0, (int)g[0].size()) s.insert(g[0][i]);
    rep(i, 1, n){
        if(seen[i] == -1) break;
        chmax(mx, seen[i]);
        rep(j, 0, (int)g[i].size()){
            if(g[i][j] > i) s.insert(g[i][j]);
        }
        if(s.count(i)) s.erase(s.find(i));
        if(mx <= i) ans[i] = (int)s.size();
    }

    rep(i, 0, n){
        cout << ans[i] << endl;
    }
    return 0;
}