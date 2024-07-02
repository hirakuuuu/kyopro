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
    int n, m, k; cin >> n >> m >> k;
    UnionFind uf(n);
    vector<int> a(m), b(m), c(k), d(k);
    rep(i, 0, m){
        cin >> a[i] >> b[i];
        a[i]--, b[i]--;
        uf.unite(a[i], b[i]);
    }
    rep(i, 0, k){
        cin >> c[i] >> d[i];
        c[i]--, d[i]--;
    }

    vector<int> ans(n);
    rep(i, 0, n) ans[i] = uf.size(i)-1;
    rep(i, 0, m){
        ans[a[i]]--;
        ans[b[i]]--;
    }
    rep(i, 0, k){
        if(uf.same(c[i], d[i])){
            ans[c[i]]--;
            ans[d[i]]--;
        }
    }
    rep(i, 0, n){
        cout << ans[i] << ' ';
    }
    cout << endl;

    return 0;
}