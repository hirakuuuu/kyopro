#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
const int MOD = 1000000007;
const int mod = 998244353;

// 問題
// https://atcoder.jp/contests/abc264/tasks/abc264_e

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
    int n, m, e; cin >> n >> m >> e;
    vector<int> u(e), v(e);
    rep(i, 0, e){
        cin >> u[i] >> v[i];
        u[i]--;
        v[i]--;
    }

    int q; cin >> q;
    vector<int> queri(q), x(e);
    rep(i, 0, q){
        int xi; cin >> xi;
        queri[i] = xi-1;
        x[xi-1] = 1;
    }

    UnionFind town(n+1);
    rep(i, 0, e){
        if(x[i]) continue;
        if(n <= u[i]) continue;
        if(n <= v[i]) v[i] = n;
        town.unite(u[i], v[i]);
    }

    stack<int> ans;
    ans.push(town.size(n)-1);

    reverse(queri.begin(), queri.end());
    rep(i, 0, q-1){
        if(n > u[queri[i]]){
            if(n <= v[queri[i]]) v[queri[i]] = n;
            town.unite(u[queri[i]], v[queri[i]]);
        }
        ans.push(town.size(n)-1);
    }

    while(!ans.empty()){
        int a = ans.top(); ans.pop();
        printf("%d\n", a);
    }

    
    return 0;
}