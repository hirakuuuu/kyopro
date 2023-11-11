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
// https://atcoder.jp/contests/abc328/tasks/abc328_f


vector<ll> rel(200005);
vector<vector<int>> g(200005);
vector<bool> seen(200005);
map<pair<int, int>, ll> cost;

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

void dfs(int pos, int pre){
    for(auto npos: g[pos]){
        if(pos == pre) continue;
        if(seen[npos]) continue;
        seen[npos] = true;
        rel[npos] += rel[pos]-cost[{pos, npos}];
        dfs(npos, pos); 
    }
}

int main(){
    int n, q; cin >> n >> q;
    vector<ll> a(q), b(q), d(q);
    rep(i, 0, q){
        cin >> a[i] >> b[i] >> d[i];
        a[i]--, b[i]--;
        if(a[i] > b[i]){
            swap(a[i], b[i]);
            d[i] = -d[i];
        }

    }
    vector<int> ans;
    UnionFind uf(n);
    vector<int> nxt;
    rep(i, 0, q){
        if(uf.same(a[i], b[i])){
            nxt.push_back(i);
        }else{
            uf.unite(a[i], b[i]);
            ans.push_back(i);
            g[a[i]].push_back(b[i]);
            g[b[i]].push_back(a[i]);
            cost[{a[i], b[i]}] = d[i];
            cost[{b[i], a[i]}] = -d[i];
        }
    }
    rep(i, 0, n){
        if(seen[i]) continue;
        seen[i] = true;
        dfs(i, -1);
    }
    for(auto i: nxt){
        //cout << i << ' ' << rel[a[i]] << ' ' << rel[b[i]] << ' ' << d[i] << endl;
        if(rel[a[i]] - rel[b[i]] == d[i]){
            ans.push_back(i);
        }
    }
    sort(ans.begin(), ans.end());

    for(auto aa: ans){
        cout << aa+1 << ' ';
    }
    cout << endl;
    
    return 0;
}