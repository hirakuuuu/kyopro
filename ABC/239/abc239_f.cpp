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
// https://atcoder.jp/contests/abc239/tasks/abc239_f

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
    vector<int> d(n);
    int sum_d = 0;
    rep(i, 0, n){
        cin >> d[i];
        sum_d += d[i];
    }

    if(sum_d != 2*(n-1)){
        cout << -1 << endl;
        return 0;
    }

    UnionFind uf(n);
    rep(i, 0, m){
        int a, b; cin >> a >> b;
        a--, b--;
        d[a]--, d[b]--;
        if(d[a] < 0 || d[b] < 0 || uf.same(a, b)){
            cout << -1 << endl;
            return 0;
        } 
        uf.unite(a, b);
    }

    vector<vector<int>> tmp(n);
    rep(i, 0, n){
        rep(j, 0, d[i]) tmp[uf[i]].push_back(i);
    }

    vector<vector<int>> c2;
    vector<int> c1;
    rep(i, 0, n){
        if(tmp[i].size() == 1) c1.push_back(tmp[i][0]);
        else if(tmp[i].size() >= 2) c2.push_back(tmp[i]);
    }

    vector<pair<int, int>> ans;
    for(auto v: c2){
        rep(i, 0, v.size()-1){
            if(c1.empty()){
                cout << -1 << endl;
                return 0;
            }
            ans.push_back({c1.back(), v[i]});
            uf.unite(c1.back(), v[i]);
            c1.pop_back();
        }
        c1.push_back(v.back());
    }

    if(c1.size() != 2){
        cout << -1 << endl;
        return 0;
    }
    ans.push_back({c1[0], c1[1]});
    uf.unite(c1[0], c1[1]);

    if(uf.size(0) != n){
        cout << -1 << endl;
        return 0;
    }

    for(auto aa: ans){
        cout << aa.first+1 << ' ' << aa.second+1 << endl;
    }


    return 0;
}