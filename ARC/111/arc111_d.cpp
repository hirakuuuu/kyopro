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
// https://atcoder.jp/contests/arc111/tasks/arc111_d

struct Edge{
    int to;
    int id;
    int dir;
};

int main(){
    int n, m; cin >> n >> m;
    vector<int> a(m), b(m);
    vector<vector<Edge>> g(n);
    rep(i, 0, m){
        cin >> a[i] >> b[i];
        a[i]--, b[i]--;
        g[a[i]].push_back({b[i], i, 0});
        g[b[i]].push_back({a[i], i, 1});
    }
    vector<int> c(n);
    rep(i, 0, n) cin >> c[i];

    vector<int> ans(m, -1);
    rep(i, 0, m){
        if(c[a[i]] == c[b[i]]) continue;
        if(c[a[i]] > c[b[i]]) ans[i] = 0;
        if(c[a[i]] < c[b[i]]) ans[i] = 1;
    }

    auto dfs = [&](auto f, auto v) -> void {
        for(auto e: g[v]){
            if(ans[e.id] != -1) continue;
            ans[e.id] = e.dir;
            f(f, e.to);
        }
    };

    rep(i, 0, n) dfs(dfs, i);

    rep(i, 0, m){
        if(ans[i]) cout << "<-" << endl;
        else cout << "->" << endl;
    }
    
    return 0;
}