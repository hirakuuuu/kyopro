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

vector<int> dh = {1, 1, 1, 0, 0, -1, -1, -1};
vector<int> dw = {1, 0, -1, 1, -1, 1, 0, -1};

int main(){
    int h, w, k; cin >> h >> w >> k;
    vector<pair<int, int>> obs(k);
    map<pair<int, int>, int> exist;
    rep(i, 0, k){
        cin >> obs[i].first >> obs[i].second;
        obs[i].first--, obs[i].second--;
        exist[obs[i]] = i;
    }
    UnionFind uf(k+4);

    rep(i, 0, k){
        rep(j, 0, 8){
            int nh = obs[i].first+dh[j], nw = obs[i].second+dw[j];
            // cout << obs[i].first << ' ' << obs[i].second << ' ' << nh << ' ' << nw << endl;
            if(nh == -1) uf.unite(i, k);
            if(nh == h) uf.unite(i, k+1);
            if(nw == -1) uf.unite(i, k+2);
            if(nw == w) uf.unite(i, k+3);
            if(exist.count({nh, nw})){
                uf.unite(i, exist[{nh, nw}]);
            }
        }
    }
    if(uf.same(k, k+1) || uf.same(k, k+2) || uf.same(k+1, k+3) || uf.same(k+2, k+3)){
        cout << "No" << endl;
    }else{
        cout << "Yes" << endl;
    }
    
    return 0;
}