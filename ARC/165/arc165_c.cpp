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
// https://atcoder.jp/contests/arc165/tasks/arc165_c

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
    ll n, m; cin >> n >> m;
    vector<ll> a(m), b(m), w(m);
    vector<vector<pair<ll, ll>>> g(n);
    vector<vector<ll>> weight(n);
    rep(i, 0, m){
        cin >> a[i] >> b[i] >> w[i];
        a[i]--, b[i]--;
        g[a[i]].push_back({b[i], w[i]});
        g[b[i]].push_back({a[i], w[i]});
        weight[a[i]].push_back(w[i]);
        weight[b[i]].push_back(w[i]);
    }

    rep(i, 0, n){
        sort(weight[i].begin(), weight[i].end());
    }

    ll ok = 1, ng = INF;
    while(ng-ok > 1){
        ll mid = (ok+ng)/2;
        UnionFind uf(2*n);
        rep(i, 0, m){
            if(w[i] >= mid) continue;
            uf.unite(2*a[i], 2*b[i]+1);
            uf.unite(2*a[i]+1, 2*b[i]);
        }
        bool f1 = true;
        rep(i, 0, n){
            if(uf.same(2*i, 2*i+1)){
                f1 = false;
                break;
            }
        }

        bool f2 = true;
        rep(i, 0, n){
            if(weight[i].size() < 2) continue;
            if(weight[i][0] < mid && weight[i][1] < mid && weight[i][0]+weight[i][1] < mid){
                f2 = false;
                break;   
            }
        }

        if(f1 && f2) ok = mid;
        else ng = mid;
    }

    cout << ok << endl;
    
    return 0;
}