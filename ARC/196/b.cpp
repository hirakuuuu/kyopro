#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define rrep(i, a, n) for(int i = a; i >= n; i--)
#define inr(l, x, r) (l <= x && x < r)
#define ll long long
#define ld long double

// using mint = modint1000000007;
using mint = modint998244353;
constexpr int IINF = 1001001001;
constexpr ll INF = 1e18;

template<class t,class u> void chmax(t&a,u b){if(a<b)a=b;}
template<class t,class u> void chmin(t&a,u b){if(b<a)a=b;}

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
        maxi[rx] = std::max(maxi[rx],maxi[ry]);
        mini[rx] = std::min(mini[rx],mini[ry]);
    }

    inline ll min(ll x){
        return mini[root(x)];
    }

    inline ll max(int x){
        return maxi[root(x)];
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

template<class T>
class WeightedUnionFind {
    vector<int> parent, maxi, mini;
    vector<T> diff_weight;

    inline int root(int n){
        if (parent[n] < 0) {
            return n;
        } else {
            int r = root(parent[n]);
            diff_weight[n] ^= diff_weight[parent[n]]; // 累積和をとる
            return parent[n] = r;
        }
    }
public:
    WeightedUnionFind(ll n_ = 1, ll init_w = 0): parent(n_, -1), maxi(n_), mini(n_), diff_weight(n_){
        iota(maxi.begin(), maxi.end(), 0);
        iota(mini.begin(), mini.end(), 0);
        for(int i = 0; i < n_; i++) diff_weight[i] = init_w;
    }

    inline bool same(int x, int y){
        return root(x) == root(y);
    }

    inline void unite(int x, int y, T w){
        // x, y それぞれについて、rootとの重みの差分を補正
        w ^= weight(x);
        w ^= weight(y);

        // x, y がすでにつながっていたら何もしない
        int rx = root(x);
        int ry = root(y);
        if(rx == ry) return;

        // サイズが大きい方に小さい方をくっつけるようにする
        // それに合わせてｗの符号も判定する
        if(parent[rx] > parent[ry]){
            swap(rx, ry);
            // w = -w;
        }
        parent[rx] += parent[ry];
        parent[ry] = rx;

        // ｘがｙの親になるので、重みの差分をdiff_weight[y]に記録
        diff_weight[ry] = w;

        maxi[rx] = std::max(maxi[rx],maxi[ry]);
        mini[rx] = std::min(mini[rx],mini[ry]);
    }

    inline int min(int x){
        return mini[root(x)];
    }

    inline int max(int x){
        return mini[root(x)];
    }

    inline ll size(ll x){
        return (-parent[root(x)]);
    }

    // 重みを取得
    T weight(int x) {
        root(x); // 経路圧縮
        return diff_weight[x];
    }

    // 重みの差を計算(weight(x)-weight(y))
    T diff(int x, int y) {
        return (weight(y) ^ weight(x));
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
    int t; cin >> t;
    while(t--){
        int h, w; cin >> h >> w;
        vector<string> s(h);
        rep(i, 0, h){
            cin >> s[i];
        }

        // 各行，各列で A の個数が偶数個でないとダメ
        bool ok = true;
        rep(i, 0, h){
            int cnt_a = 0;
            rep(j, 0, w){
                if(s[i][j] == 'A') cnt_a++;
            }
            if(cnt_a%2 == 1) ok = false;
        }
        rep(i, 0, w){
            int cnt_a = 0;
            rep(j, 0, h){
                if(s[j][i] == 'A') cnt_a++;
            }
            if(cnt_a%2 == 1) ok = false;
        }

        // B の決め方に矛盾がないかを確認
        vector<vector<int>> row_B(h);
        vector<vector<int>> col_B(w);
        rep(i, 0, h){
            rep(j, 0, w){
                if(s[i][j] == 'B'){
                    row_B[i].push_back(j);
                    col_B[j].push_back(i);
                }
            }
        }

        WeightedUnionFind<int> wuf(h*w);
        auto id = [&](int i, int j) -> int {
            return i*w+j;
        };
        rep(i, 0, h){
            rep(j, 0, w){
                if(s[i][j] == 'B'){
                    auto itr_l = upper_bound(row_B[i].begin(), row_B[i].end(), j);
                    if(itr_l != row_B[i].end()){
                        int k = *itr_l;
                        if(wuf.same(id(i, j), id(i, k))){
                            if((wuf.weight(id(i, j))^wuf.weight(id(i, k))) != (k-j+1)%2){
                                ok = false;
                            }
                        }else{
                            wuf.unite(id(i, j), id(i, k), (k-j+1)%2);
                        }
                    }

                    auto itr_d = upper_bound(col_B[j].begin(), col_B[j].end(), i);
                    if(itr_d != col_B[j].end()){
                        int k = *itr_d;
                        if(wuf.same(id(i, j), id(k, j))){
                            if((wuf.weight(id(i, j))^wuf.weight(id(k, j))) != (k-i+1)%2){
                                ok = false;
                            }
                        }else{
                            wuf.unite(id(i, j), id(k, j), (k-i+1)%2);
                        }
                    }
                }
            }
        }


        if(ok){
            // (i, j) に B があるとき i 行目と j 列目に対応する頂点をつなぐ
            UnionFind uf(h+w);
            rep(i, 0, h){
                rep(j, 0, w){
                    if(s[i][j] == 'B'){
                        uf.unite(i, j+h);
                    }
                }
            }
            set<int> root;
            rep(i, 0, h) root.insert(uf[i]);
            rep(i, 0, w) root.insert(uf[i+h]);
            cout << (mint(2).pow(root.size())).val() << endl;
        }else{
            cout << 0 << endl;
        }
    }
    
    return 0;
}