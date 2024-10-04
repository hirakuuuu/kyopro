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
constexpr ll INF = 9e18;

template<class t,class u> void chmax(t&a,u b){if(a<b)a=b;}
template<class t,class u> void chmin(t&a,u b){if(b<a)a=b;}

class UnionFind {
    vector<ll> parent;
    inline ll root(ll n){
        return (parent[n] < 0? n:parent[n] = root(parent[n]));
    }
public:
    UnionFind(ll n_ = 1): parent(n_, -1){}

    inline bool same(ll x, ll y){
        return root(x) == root(y);
    }

    inline void unite(ll x, ll y){
        ll rx = root(x);
        ll ry = root(y);
        if(rx == ry) return;
        if(parent[rx] > parent[ry]) swap(rx, ry);
        parent[rx] += parent[ry];
        parent[ry] = rx;
    }

    inline ll size(ll x){
        return (-parent[root(x)]);
    }

    inline ll operator[](ll x){
        return root(x);
    }
};

int main(){
    int n, m; cin >> n >> m;
    vector<vector<int>> g(n);
    UnionFind uf(n);
    rep(i, 0, m){
        int u, v; cin >> u >> v;
        u--, v--;
        if(uf.same(u, v)) continue;
        uf.unite(u, v);
        g[u].push_back(v);
        g[v].push_back(u);
    }
    string s; cin >> s;
    vector<int> c(n);
    int r = 0;
    rep(i, 0, n) c[i] = s[i]-'0';

    // パスを求める
    // DFSで探索する過程で、偶奇があってないところが出てきたら、親に戻ることで調整できる
    // 最終的に偶奇が一致しない可能性があるのが、根だけであり、それは先頭を除くことで調整できる
    vector<int> ans;
    auto dfs = [&](auto self, int pos, int pre) -> void {
        ans.push_back(pos);
        c[pos] = 1-c[pos];
        for(auto nxt: g[pos]){
            if(nxt == pre) continue;
            self(self, nxt, pos);
            ans.push_back(pos);
            c[pos] = 1-c[pos];
        }
        if(c[pos] == 1 && pre != -1){
            ans.push_back(pre);
            c[pre] = 1-c[pre];
            ans.push_back(pos);
            c[pos] = 1-c[pos];
        }
    };
    dfs(dfs, r, -1);
    int start = 0;
    if(c[r] == 1) start = 1;
    cout << ans.size()-start << endl;
    rep(i, start, (int)ans.size()){
        cout << ans[i]+1 << ' ';
    }
    cout << endl;

    return 0;
}