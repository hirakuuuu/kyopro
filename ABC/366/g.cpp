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
- 次数がすべて偶数なら同じ数を書けばよい
- 次数が１の頂点があるとだめ
- 桁を独立させれば、ある頂点に 1 を書いて、残りの頂点に {0, 1} を割り当てる方法があるかを考えればよい

隣接行列を A とする. 
そうすると上の問題は, Ax = 0 の基底を求めて、それの or がすべてのけたを被覆するかどうかに帰着できる

*/

/* mod 2 で連立方程式を解く */
const int bs = 61;
struct LinearEquation_F2 {

    using BS = bitset<bs>;

    int h, w;
    vector<BS> d;
    LinearEquation_F2(vector<vector<int>> a, vector<int> b) {
        assert(a.size() == b.size());
        // 拡大係数行列なので +1 する
        h = (int)a.size(), w = (int)a[0].size()+1;
        d.resize(h);
        // d を構築（bitset）
        rep(i, 0, h){
            rep(j, 0, w-1){
                if(a[i][j]) d[i][j] = 1; 
            }
            if(b[i]) d[i][w-1] = 1;
        }
    };

    // 掃き出し法で解を1つ求める（解があるかどうかを boolean で返す）
    pair<bool, BS> solve(){
        int ni = 0;
        rep(j, 0, w-1){
            rep(i, ni, h){
                if(d[i][j]){ swap(d[i], d[ni]); break; }
            }
            if(!d[ni][j]) continue;
            rep(i, 0, h){
                if(ni != i && d[i][j]) d[i] ^= d[ni];
            }
            ni++;
            if(ni == h) break;
        }

        BS res;
        rep(i, 0, h){
            int j = 0;
            while(j < w-1 && !d[i][j]) j++;
            if(j == w-1){
                // {0, 0, ... , 0 | 1} の形があると解なし
                if(d[i][w-1]) return {false, BS(0)}; 
                continue;
            }
            // 最も左にあるやつを 1 にして、それ以外を 0 とすれば自明に成り立つ
            res[j] = d[i][w-1];
        }
        return {true, res};
    };

};

int main(){
    int n, m; cin >> n >> m;
    vector<vector<int>> a(n+1, vector<int>(n));
    rep(i, 0, m){
        int u, v; cin >> u >> v;
        u--, v--;
        a[u][v] = a[v][u] = 1;
    }

    vector<int> b(n+1);
    vector<ll> ans(n);
    b[n] = 1; // 最後に x_i = 1 を追加
    rep(i, 0, n){
        vector<vector<int>> d = a;
        vector<int> s = b;
        d[n][i] = 1;
        LinearEquation_F2 le(d, s);
        auto [ok, x] = le.solve();
        if(!ok){
            cout << "No" << endl;
            return 0;
        }
        rep(j, 0, n) if(x[j]) ans[j] |= (1LL<<i);
    }
    cout << "Yes" << endl;
    rep(i, 0, n){
        cout << ans[i] << ' ';
    }
    cout << endl;

    return 0;
}