#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
const int MOD = 1000000007;
const int mod = 998244353;

// 問題
// https://atcoder.jp/contests/abc183/tasks/abc183_f

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
    int n, q; cin >> n >> q;
    vector<int> c(n);
    rep(i, 0, n) cin >> c[i];

    UnionFind uf(n);
    vector<map<int, int>> cnt(n);
    rep(i, 0, n) cnt[i][c[i]]++;

    while(q--){
        int t; cin >> t;
        if(t == 1){
            int a, b; cin >> a >> b;
            a--; b--;
            int ra = uf[a], rb = uf[b];
            if(ra == rb) continue;
            uf.unite(a, b);
            int r = uf[a], pr = ra;
            if(rb != r) pr = rb;
            for(auto cc: cnt[pr]){
                cnt[r][cc.first] += cc.second;
            }
        }else{
            int x, y; cin >> x >> y;
            x--;
            cout << cnt[uf[x]][y] << endl;
        }
    }
    
    return 0;
}