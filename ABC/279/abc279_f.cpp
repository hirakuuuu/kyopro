#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
const int MOD = 1000000007;
const int mod = 998244353;

// 問題
// https://atcoder.jp/contests/abc279/tasks/abc279_f

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
        // if(parent[rx] > parent[ry]) swap(rx, ry);
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
    int n, q; cin >> n >> q;
    map<pii, int> m;
    vector<pii> mi;
    vector<vector<int>> op(q, vector<int>(3));
    vector<int> cnt_t1(n);
    int cnt_t2 = 0;
    rep(i, 0, q){
        int t, x; cin >> t >> x;
        x--;
        if(t == 1){
            int y; cin >> y;
            y--;
            cnt_t1[y]++;
            op[i][0] = t;
            op[i][1] = x;
            op[i][2] = y;
        }else if(t == 2){
            cnt_t2++;
            op[i][0] = t;
            op[i][1] = x;
        }else{
            op[i][0] = t;
            op[i][1] = x;
        }
    }

    int id = 0;
    rep(i, 0, n){
        rep(j, 0, cnt_t1[i]+1){
            m[{i, j}] = id;
            mi.push_back({i, j});
            id++;
        }
    }
    rep(i, 0, n+cnt_t2+1){
        m[{n+i, 0}] = id;
        mi.push_back({n+i, 0});
        id++;
    }
    
    UnionFind uf(id+1);
    rep(i, 0, n){
        uf.unite(m[{i, cnt_t1[i]}], m[{n+i, 0}]);
    }

    int k = n;

    rep(i, 0, q){
        if(op[i][0] == 1){
            uf.unite(m[{op[i][1], cnt_t1[op[i][1]]}], m[{op[i][2], cnt_t1[op[i][2]]}]);
            cnt_t1[op[i][2]]--;
        }else if(op[i][0] == 2){
            // cout << op[i][1] << ' ' << n+k << endl;
            uf.unite(m[{op[i][1], cnt_t1[op[i][1]]}], m[{n+k, 0}]);
            k++;
        }else{
            // cout << n+op[i][1] << ' ' << endl;
            cout << mi[uf[m[{n+op[i][1], 0}]]].first+1 << endl;
        }
    }




    
    return 0;
}