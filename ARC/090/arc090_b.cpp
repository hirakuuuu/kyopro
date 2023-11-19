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
// https://atcoder.jp/contests/abc087/tasks/arc090_b

template<class T>
class WeightedUnionFind {
    vector<int> parent, maxi, mini;
    vector<T> diff_weight;

    inline int root(int n){
        if (parent[n] < 0) {
            return n;
        } else {
            int r = root(parent[n]);
            diff_weight[n] += diff_weight[parent[n]]; // 累積和をとる
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
        w += weight(x);
        w -= weight(y);

        // x, y がすでにつながっていたら何もしない
        int rx = root(x);
        int ry = root(y);
        if(rx == ry) return;

        // サイズが大きい方に小さい方をくっつけるようにする
        // それに合わせてｗの符号も判定する
        if(parent[rx] > parent[ry]){
            swap(rx, ry);
            w = -w;
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
        return weight(y) - weight(x);
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
    WeightedUnionFind<ll> wuf(n);
    bool f = true;
    rep(i, 0, m){
        int x, y;
        ll d; cin >> x >> y >> d;
        x--, y--;
        if(wuf.same(x, y)){
            if(wuf.diff(x, y) == d) continue;
            f = false;
        }else{
            wuf.unite(x, y, d);
        }
    }
    
    if(f) cout << "Yes" << endl;
    else cout << "No" << endl;

    
    return 0;
}