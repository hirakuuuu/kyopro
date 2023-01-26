#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
const int MOD_NUM = 1000000007;
const int mod_num = 998244353;

template<class t,class u> void chmax(t&a,u b){if(a<b)a=b;}
template<class t,class u> void chmin(t&a,u b){if(b<a)a=b;}

// 問題
// https://atcoder.jp/contests/abc270/tasks/abc270_f

/*
- 最小全域木を構築したい
- 辺の本数はO(n^2+m)ある→クラスカルじゃ無理
- とりあえず、空港と港のうち、コストが小さい方を採用して、採用しなかった方でもっともコストが小さいやつを採用すれば、全部連結にはなる

- 島 i に空港を建設する　⇔　島 n+1 と連結になる
- 島 i に港を建設する　⇔　島 n+2 と連結になる
- これを n+1, n+2 をそれぞれ含めるか、含めないかの４通りですべて連結にするために必要なコストを計算する。
*/

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
    vector<ll> x(n+1), y(n+1);
    rep(i, 1, n+1) cin >> x[i];
    rep(i, 1, n+1) cin >> y[i];

    vector<ll> z(m), a(m), b(m);

    rep(i, 0, m) cin >> a[i] >> b[i] >> z[i];

    ll ans = 1LL<<60;
    UnionFind uf(n+3);
    vector<vector<ll>> ah(3);
    vector<vector<ll>> path;
    rep(i, 1, n+1){
        path.push_back({x[i], 0, i, 0});
    }
    rep(i, 1, n+1){
        path.push_back({y[i], 1, i, 0});
    }
    rep(i, 0, m){
        path.push_back({z[i], 2, a[i], b[i]});
    }

    sort(path.begin(), path.end());
    rep(k, 0, 4){
        uf.clear();
        ll tmp = 0;
        rep(i, 0, 2*n+m){
            if(path[i][1] == 0 and k%2 > 0 and !uf.same(path[i][2], n+1)){
                uf.unite(path[i][2], n+1);
                tmp += path[i][0];
            }
            if(path[i][1] == 1 and k/2 > 0 and !uf.same(path[i][2], n+2)){
                uf.unite(path[i][2], n+2);
                tmp += path[i][0];
            }
            if(path[i][1] == 2 and !uf.same(path[i][2], path[i][3])){
                uf.unite(path[i][2], path[i][3]);
                tmp += path[i][0];
            }
        }
        if(uf.size(1) == n+k/2+k%2) chmin(ans, tmp);
    }
    cout << ans << endl;

    return 0;
}