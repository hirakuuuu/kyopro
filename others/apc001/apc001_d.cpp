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
// https://atcoder.jp/contests/apc001/tasks/apc001_d

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
    vector<ll> a(n);
    rep(i, 0, n) cin >> a[i];
    UnionFind uf(n);
    rep(i, 0, m){
        int x, y; cin >> x >> y;
        uf.unite(x, y);
    }
    set<ll> par;
    rep(i, 0, n){
        par.insert(uf[i]);
    }
    if(par.size() == 1){
        cout << 0 << endl;
        return 0;
    }else if(2*(par.size()-1) > n){
        cout << "Impossible" << endl;
        return 0;
    }
    ll sum = 0;
    rep(i, 0, n) sum += a[i];
    ll mx = 0;
    vector<vector<ll>> node(n);
    rep(i, 0, n){
        node[uf[i]].push_back(a[i]);
    }
    priority_queue<ll> que;
    rep(i, 0, n){
        sort(node[i].begin(), node[i].end());
        rep(j, 1, node[i].size()){
            que.push(node[i][j]);
        }
    }


    rep(i, 0, n-2*(par.size()-1)){
        if(que.empty()) break;
        sum -= que.top(); que.pop();
    }
    cout << sum << endl;

    
    return 0;
}