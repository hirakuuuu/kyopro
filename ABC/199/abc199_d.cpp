#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define rrep(i, a, n) for(int i = a; i >= n; i--)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
const int MOD = 1000000007;
const int mod = 998244353;
const int iinf = 1001001001;

template<class t,class u> void chmax(t&a,u b){if(a<b)a=b;}
template<class t,class u> void chmin(t&a,u b){if(b<a)a=b;}

// 問題
// https://atcoder.jp/contests/abc199/tasks/abc199_d

/*
- 1色で塗れるか→辺があるかどうか
- 2色で塗れるか→(奇数個の頂点からなる閉路がなければ)2^連結成分の個数
- 2,3色で塗れるか→色0で塗る頂点をビット全探索
                 連結な頂点があればダメ
　　　　　　　　 その頂点と頂点に接続する辺を削除、
                 残った頂点を2色で塗る方法を考える
- 計算量削減→先に、隣り合ってる頂点を含まない様な組みを全列挙
*/


// ここから
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
// ここまで

// 繰り返し二乗法
ll power(ll a, ll b){
    ll res = 1;
    while(b > 0){
        if(b%2 == 1) res = res*a;
        a = a*a;
        b /= 2;
    }
    return res;
}

int n, m;
vector<int> g[25];
int e[25][25];


int main(){
    cin >> n >> m;
    rep(i, 0, n) rep(j, 0, n) e[i][j] = 0;
    rep(i, 0, m){
        int u, v; cin >> u >> v;
        u--, v--;
        g[u].push_back(v);
        g[v].push_back(u);
        e[u][v] = e[v][u] = 1;
    }

    ll ans = 0;
    rep(i, 0, 1<<n){
        // 選んだ頂点に隣接しているものがあるかを確認
        bool f1 = true;
        rep(j, 0, n){
            for(auto k: g[j]){
                if((i&(1<<j)) and (i&(1<<k))){
                    f1 = false;
                    break;
                }
            }
            if(!f1) break;
        }
        if(!f1) continue;

        // 選ばれなかった頂点が二部グラフを成すかを判定
        bool f2 = true;
        UnionFind uf(n), uf_2(2*n);
        rep(j, 0, n){
            for(auto k: g[j]){
                if(!(i&(1<<j)) and !(i&(1<<k))){
                    uf.unite(j, k);
                    uf_2.unite(2*j, 2*k+1);
                    uf_2.unite(2*j+1, 2*k);
                }
            }
        }
        rep(j, 0, n){
            if(uf_2.same(2*j, 2*j+1)){
                f2 = false;
                break;
            }
        }
        if(!f2) continue;
        

        // 連結成分の個数を数える
        set<ll> cnt;
        rep(j, 0, n){
            if(!(i&(1<<j))) cnt.insert(uf[j]);
        }

        ans += power(2, cnt.size());
    }

    cout << ans << endl;
    
    
    return 0;
}