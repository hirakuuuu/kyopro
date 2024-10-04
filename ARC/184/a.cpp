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
インタラクティブは落ち着いて、実装する
条件の書き忘れで、かなり詰まったので、落ち着いてやってくれ
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
    int n, m, q; cin >> n >> m >> q;    
    auto query = [&](int x, int y) -> bool { // 同種かどうかを判定
        q--;
        assert(q >= 0);
        assert(inr(1, x, n+1) && inr(1, y, n+1) && x != y);
        cout << "? " << x << ' ' << y << endl;
        int res; cin >> res;
        return !res;
    };

    int g = 50, k = n/g; // 20個ずつ50グループに分ける. 
    UnionFind uf(n); // 各グループでの判定結果を union-find で管理
    
    rep(i, 0, g-1){ // 1~49 グループについて、代表元とそれ以外の同種判定
        int x = i*k;
        rep(y, x+1, x+k){
            if(query(x+1, y+1)) uf.unite(x, y);
        }
    }

    vector<int> ans;
    
    rep(i, 0, g-1){
        int x = i*k;
        if(uf.size(x) == m){ // 代表元と同種が10個しかなかったら、このグループに全部集まっている
            assert(ans.size() == 0);
            int nx = 0; // nx は本物
            if(i == 0) nx = k;
            assert(uf.size(nx) == k);

            // 代表元が本物かどうかで判定
            if(query(x+1, nx+1)){
                rep(y, x, x+k){
                    if(!uf.same(x, y)) ans.push_back(y);
                }
            }else{
                rep(y, x, x+k){
                    if(uf.same(x, y)) ans.push_back(y);
                }
            }
        }else if(uf.size(x) > m){ // 代表元と同種が 11 個以上　→ 異種判定されたものは偽物
            rep(y, x, x+k){
                if(!uf.same(x, y)) ans.push_back(y);
            }
        }else{ // 代表元と異種が 11 個以上 → 同種判定されたものは偽物
            rep(y, x, x+k){
                if(uf.same(x, y)) ans.push_back(y);
            }
        }
    }

    if(ans.size() == 0){ // ここまで偽物0個 → 最後のグループの半分が偽物
        // 19回で処理
        int x = (g-1)*k;
        rep(y, x+1, x+k-1){ // 18枚は普通に聞く
            if(query(x+1, y+1)) uf.unite(x, y);
        }
        if(uf.size(x) < m) uf.unite(x, x+k-1); // 最後の1枚はそれまでの結果からわかる
        assert(uf.size(x) == m);
        
        if(query(x+1, 1)){ // 代表元が本物かどうかで場合分け
            rep(y, x, x+k){
                if(!uf.same(x, y)) ans.push_back(y);
            }
        }else{
            rep(y, x, x+k){
                if(uf.same(x, y)) ans.push_back(y);
            }
        }
        assert(ans.size() == m);
    }else if(ans.size() < m){ // 最後のグループに偽物がある場合 この判定をしないでWAでた
        // 代表元との判定で、どっちかに偏る
        int x = (g-1)*k;
        rep(y, x+1, x+k){
            if(query(x+1, y+1)) uf.unite(x, y);
        }
        if(uf.size(x) > m){
            rep(y, x, x+k){
                if(!uf.same(x, y)) ans.push_back(y);
            }
        }else{
            rep(y, x, x+k){
                if(uf.same(x, y)) ans.push_back(y);
            }
        }
    }

    assert(ans.size() == m);
    cout << '!';
    rep(i, 0, m) cout << ' ' << ans[i]+1;
    cout << endl;

    
    return 0;
}