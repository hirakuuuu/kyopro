#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
const int MOD = 1000000007;
const int mod = 998244353;

// 問題
// https://atcoder.jp/contests/abc266/tasks/abc266_f

vector<vector<int>> g(200005);

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
    vector<int> u(n), v(n);
    vector<int> cnt(n);
    rep(i, 0, n){
        cin >> u[i] >> v[i];
        u[i]--;
        v[i]--;
        cnt[u[i]]++;
        cnt[v[i]]++;
        g[u[i]].push_back(v[i]);
        g[v[i]].push_back(u[i]);
    }

    priority_queue<int> que;
    rep(i, 0, n){
        if(cnt[i] == 1) que.push(i);
    }

    vector<bool> isclosed(n, true);

    while(!que.empty()){
        int q = que.top(); que.pop();
        isclosed[q] = false;
        for(auto gg: g[q]){
            if(cnt[gg] >= 2){
                cnt[gg]--;
                if(cnt[gg] == 1) que.push(gg);
            }
        }
    }

    UnionFind tree(n);
    rep(i, 0, n){
        if(isclosed[u[i]] and isclosed[v[i]]) continue;
        tree.unite(u[i], v[i]);
    }

    int q; cin >> q;
    while(q--){
        int x, y; cin >> x >> y;
        if(tree.same(x-1, y-1)){
            printf("Yes\n");
        }else{
            printf("No\n");
        }
    }


    
    return 0;
}