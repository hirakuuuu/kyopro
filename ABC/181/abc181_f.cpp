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
// https://atcoder.jp/contests/abc181/tasks/abc181_f

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
    int n; cin >> n;
    vector<int> x(n), y(n);
    rep(i, 0, n) cin >> x[i] >> y[i];
    vector<vector<int>> nail(205);
    rep(i, -99, 100){
        int j = i+99;
        rep(k, 0, n){
            if(x[k] == i){
                nail[j].push_back(y[k]);
            }
        }
        sort(nail[j].begin(), nail[j].end());
    }

    map<pair<int, int>, int> ind;
    rep(i, 0, n) ind[{x[i], y[i]}] = i;
    rep(i, n, n+199) ind[{i-n-99, 100}] = i;
    rep(i, n+199, n+398) ind[{i-n-298, -100}] = i;
    ind[{IINF, 100}] = n+398;
    ind[{IINF, -100}] = n+399;


    UnionFind uf(n+400);
    rep(i, -99, 100){
        uf.unite(ind[{IINF, 100}], ind[{i, 100}]);
        uf.unite(ind[{IINF, -100}], ind[{i, -100}]);
    }

    vector<tuple<double, int, int>> d;
    rep(i, 0, n){
        rep(j, i+1, n){
            double dist = (double)sqrt((x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j]));
            d.push_back({dist, i, j});
        }
    }

    rep(i, -99, 100){
        if(nail[i+99].size()){
            double dist = (double)(nail[i+99][0]+100);
            d.push_back({dist, ind[{i, nail[i+99][0]}], ind[{i, -100}]});
            dist = (double)(100-nail[i+99].back());
            d.push_back({dist, ind[{i, nail[i+99].back()}], ind[{i, 100}]});
        }
    }

    sort(d.begin(), d.end());
    int id = 0;
    double ans = 0.0;
    while(id < d.size() && !uf.same(ind[{IINF, 100}], ind[{IINF, -100}])){
        auto [dist, i, j] = d[id];
        id++;
        ans = dist;
        uf.unite(i, j);
    }

    printf("%.15f\n", ans/2.0);


    
    return 0;
}