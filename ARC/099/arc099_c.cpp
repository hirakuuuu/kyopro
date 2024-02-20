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
// https://atcoder.jp/contests/arc099/tasks/arc099_c

class UnionFind {
    vector<ll> parent, maxi, mini;
    inline ll root(ll n){
        return (parent[n] < 0? n:parent[n] = root(parent[n]));
    }
public:
    UnionFind(ll n_ = 1): parent(n_, -1), maxi(n_), mini(n_){
        iota(maxi.begin(), maxi.end(), 0);
        iota(mini.begin(), mini.end(), 0);
    }

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
        maxi[x] = std::max(maxi[x],maxi[y]);
        mini[x] = std::min(mini[x],mini[y]);
    }

    inline ll min(ll x){
        return mini[root(x)];
    }

    inline ll max(int x){
        return mini[root(x)];
    }

    inline ll size(ll x){
        return (-parent[root(x)]);
    }

    inline ll operator[](ll x){
        return root(x);
    }

    inline void print(){
        rep(i, 0, (ll)parent.size()) cout << root(i) << " ";
        cout << endl;
    }

    void clear(){
        rep(i, 0, (ll)parent.size()){
            parent[i] = -1;
        }
        iota(maxi.begin(), maxi.end(), 0);
        iota(mini.begin(), mini.end(), 0);
    }
};

int main(){
    int n, m; cin >> n >> m;
    vector<vector<int>> adj(n, vector<int>(n));
    vector<vector<int>> g(n);
    rep(i, 0, m){
        int u, v; cin >> u >> v;
        u--, v--;
        adj[u][v] = adj[v][u] = 1;
    }
    UnionFind uf(n*2);
    rep(i, 0, n){
        rep(j, i+1, n){
            if(!adj[i][j]){
                uf.unite(i, j+n);
                uf.unite(i+n, j);
                g[i].push_back(j);
                g[j].push_back(i);
            }
        }
    }
    rep(i, 0, n){
        if(uf.same(i, i+n)){
            cout << -1 << endl;
            return 0;
        }
    }

    vector<bool> seen(n);
    auto dfs = [&](auto sfs, int pos, int pre, vector<int> &c) -> void {
        for(auto nxt: g[pos]){
            if(c[nxt] != -1 || nxt == pre) continue;
            c[nxt] = 1-c[pos];
            sfs(sfs, nxt, pos, c);
        }
    };
    vector<pair<int, int>> v;
    rep(i, 0, n){
        if(seen[i]) continue;
        vector<int> c(n, -1);
        c[i] = 0;
        dfs(dfs, i, -1, c);
        int total = 0, cnt = 0;
        rep(j, 0, n){
            if(c[j] != -1){
                seen[j] = true;
                total++;
                cnt += c[j];
            }
        }
        v.push_back({cnt, total-cnt});
    }
    int l = v.size();
    vector<vector<int>> dp(l+1, vector<int>(n+1));
    dp[0][0] = 1;
    rep(i, 1, l+1){
        rep(j, 0, n+1){
            if(j+v[i-1].first <= n) dp[i][j+v[i-1].first] |= dp[i-1][j];
            if(j+v[i-1].second <= n) dp[i][j+v[i-1].second] |= dp[i-1][j];
        }
    }
    int ans = IINF;
    rep(i, 0, n+1){
        if(dp[l][i]) chmin(ans, i*(i-1)/2+(n-i)*(n-i-1)/2);
    }
    cout << ans << endl;

    
    return 0;
}