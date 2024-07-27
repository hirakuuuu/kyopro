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
constexpr ll INF = 9e18;

template<class t,class u> void chmax(t&a,u b){if(a<b)a=b;}
template<class t,class u> void chmin(t&a,u b){if(b<a)a=b;}

/*
海とつながるかどうかは union-find で管理できる. 
より小さいところから遷移してくるのが漏れてなければよいので,
自分が浸る時刻になったときに隣接４マスの値が小さいところから遷移させれば漏れがない
最終的に海とつながってる連結成分のサイズを引けばよい
*/

class UnionFind {
    vector<ll> parent;
    inline ll root(ll n){
        return (parent[n] < 0? n:parent[n] = root(parent[n]));
    }
public:
    UnionFind(ll n_ = 1): parent(n_, -1){}

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
    }

    inline ll size(ll x){
        return (-parent[root(x)]);
    }

    inline ll operator[](ll x){
        return root(x);
    }
};

int main(){
    int h, w, y; cin >> h >> w >> y;
    vector<vector<int>> a(h, vector<int>(w));
    rep(i, 0, h){
        rep(j, 0, w){
            cin >> a[i][j];
        }
    }
    vector<vector<pair<int, int>>> g(y+1);
    rep(i, 0, h){
        rep(j, 0, w){
            if(a[i][j] > y) continue;
            g[a[i][j]].push_back({i, j});
        }
    }

    auto id = [&](int i, int j) -> int {
        return i*w+j+1;
    };
    UnionFind uf(h*w+1);
    int total = h*w;
    rep(i, 1, y+1){
        for(auto [ci, cj]: g[i]){
            if(ci == 0 || cj == 0 || ci == h-1 || cj == w-1){
                uf.unite(0, id(ci, cj));
            }
            rep(k, 0, 4){
                int ni = ci+(k-1)%2, nj = cj+(k-2)%2;
                if(!inr(0, ni, h) || !inr(0, nj, w)) continue;
                if(a[ni][nj] <= a[ci][cj]) uf.unite(id(ni, nj), id(ci, cj));
            }
        }
        cout << total+1-uf.size(0) << endl;

    }

    
    return 0;
}