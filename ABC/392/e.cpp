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
        maxi[rx] = std::max(maxi[rx],maxi[ry]);
        mini[rx] = std::min(mini[rx],mini[ry]);
    }

    inline ll min(ll x){
        return mini[root(x)];
    }

    inline ll max(int x){
        return maxi[root(x)];
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
    vector<int> a(m), b(m);
    vector<int> can;
    UnionFind uf(n);
    rep(i, 0, m){
        cin >> a[i] >> b[i]; a[i]--, b[i]--;
        if(uf.same(a[i], b[i])){
            can.push_back(i);
        }else{
            uf.unite(a[i], b[i]);
        }
    }

    vector<vector<int>> can_r(n);
    for(auto id: can){
        can_r[uf[a[id]]].push_back(id);
    }
    vector<int> root_id(n);
    iota(root_id.begin(), root_id.end(), 0);
    sort(root_id.begin(), root_id.end(), [&](auto i, auto j){
        return can_r[i].size() > can_r[j].size();
    });

    vector<tuple<int, int, int>> ans;
    vector<int> can_use;
    for(auto id: can_r[root_id[0]]){
        can_use.push_back(id);
    }
    rep(i, 1, n){
        if(can_use.empty()) break;
        if(uf.same(uf[a[can_use.back()]], root_id[i])) continue;
        ans.push_back({can_use.back(), a[can_use.back()], root_id[i]});
        uf.unite(root_id[i], uf[a[can_use.back()]]);
        can_use.pop_back();
        for(auto id: can_r[root_id[i]]){
            can_use.push_back(id);
        }
    }

    cout << ans.size() << endl;
    for(auto [id, u, v]: ans){
        cout << id+1 << ' ' << u+1 << ' ' << v+1 << endl;
    }

    return 0;
}