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
constexpr ll INF = 1e18;

template<class t,class u> void chmax(t&a,u b){if(a<b)a=b;}
template<class t,class u> void chmin(t&a,u b){if(b<a)a=b;}

template<class T>
class WeightedUnionFind {
    vector<int> parent;
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
    WeightedUnionFind(ll n_ = 1, int init_w = 0): parent(n_, -1), diff_weight(n_){
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
        }
        parent[rx] += parent[ry];
        parent[ry] = rx;

        // ｘがｙの親になるので、重みの差分をdiff_weight[y]に記録
        diff_weight[ry] = w;
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
    }
};


int main(){
    int n, m; cin >> n >> m;
    vector<int> x(m), y(m), z(m);
    rep(i, 0, m){
        cin >> x[i] >> y[i] >> z[i];
        x[i]--, y[i]--;
    }
    
    WeightedUnionFind<int> uf(n);
    vector<vector<pair<int, int>>> g(n);
    rep(i, 0, m){
        if(!uf.same(x[i], y[i])){
            uf.unite(x[i], y[i], z[i]);
            g[x[i]].push_back({y[i], z[i]});
            g[y[i]].push_back({x[i], z[i]});
        }else{
            if((uf.weight(x[i])^uf.weight(y[i])) != z[i]){
                cout << -1 << endl;
                return 0;
            }
        }
    }

    vector<int> ans(n);
    rep(j, 0, 30){
        vector<bool> seen(n);
        vector<int> c(n);
        rep(i, 0, n){
            if(seen[i]) continue;
            // cout << i << endl;
            auto f = [&](auto self, int pos, int pre) -> int {
                int res = c[pos];
                seen[pos] = true;
                for(auto [nxt, w]: g[pos]){
                    if(nxt  == pre) continue;
                    c[nxt] = (c[pos]^((w>>j)&1));
                    res += self(self, nxt, pos);
                }
                return res;
            };
            
            c[i] = 0;
            int mi = f(f, i, -1);
            c[i] = 1;
            if(mi < f(f, i, -1)){
                c[i] = 0;
                f(f, i, -1);
            }
        }

        rep(i, 0, n){
            ans[i] += c[i]<<j;
        }
    }
    rep(i, 0, n){
        cout << ans[i] << ' ';
    }
    cout << endl;
    return 0;
}