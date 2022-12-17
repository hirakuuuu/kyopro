#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
const int MOD = 1000000007;
const int mod = 998244353;

template<class t,class u> void chmax(t&a,u b){if(a<b)a=b;}
template<class t,class u> void chmin(t&a,u b){if(b<a)a=b;}

// 問題
// https://atcoder.jp/contests/abc282/tasks/abc282_d

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

vector<vector<int>> g(200005);
vector<ll> c(200005), cnt(200005), seen(200005);

void dfs(int pos){
    if(seen[pos]) return;
    seen[pos] = 1;
    for(const auto npos: g[pos]){
        if(seen[npos]) continue;
        c[npos] = 1-c[pos];
        dfs(npos);
    }
}

int main(){
    ll n, m; cin >> n >> m;
    UnionFind uf(n+1);
    vector<int> u(m), v(m);
    rep(i, 0, m){
        cin >> u[i] >> v[i];
        g[u[i]].push_back(v[i]);
        g[v[i]].push_back(u[i]);
        cnt[u[i]]++;
        cnt[v[i]]++;
        uf.unite(u[i], v[i]);
    }
    rep(i, 1, n+1){
        dfs(i);
    }
    rep(i, 0, m){
        if(c[u[i]] == c[v[i]]){
            cout << 0 << endl;
            return 0;
        }
    }

    vector<vector<ll>> cnt_c(n+1, vector<ll>(2));
    rep(i, 1, n+1){
        cnt_c[uf[i]][c[i]]++;
    }

    ll ans = 0;
    rep(i, 1, n+1){
        ans += n-uf.size(i);
        ans += cnt_c[uf[i]][1-c[i]]-cnt[i];
    }
    cout << ans/2 << endl;

    return 0;
}