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
次数に着目して、平方分割
- 次数が大きい頂点については、毎回愚直に更新する（そのような頂点は高々 √m 程度）
- 次数が小さい頂点については、自分と隣接頂点のうち、最も最近に更新されたクエリの色を出力（見る頂点は高々 √m 程度）

√2m で分けると倍くらい速くなった、極小値見るの大事かも知れない.
*/

int main(){
    int n, m; cin >> n >> m;
    vector<vector<int>> g(n);
    rep(i, 0, m){
        int a, b; cin >> a >> b;
        a--, b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    vector<int> mx;
    rep(i, 0, n){
        if((ll)g[i].size()*g[i].size() >= (ll)2*m) mx.push_back(i);
    }
    vector<vector<int>> edge(mx.size(), vector<int>(n));
    rep(i, 0, mx.size()){
        for(auto adj: g[mx[i]]) edge[i][adj] = 1;
    }
    vector<int> t(n, -1), c(n, 1), ans(n, 1);
    int q; cin >> q;
    rep(i, 0, q){
        int x, y; cin >> x >> y;
        x--;
        if((ll)g[x].size()*g[x].size() >= (ll)2*m){
            cout << ans[x] << '\n';
        }else{
            int tmp = c[x], time = t[x];
            for(auto nx: g[x]){
                if(time < t[nx]){
                    time = t[nx];
                    tmp = c[nx];
                }
            }
            cout << tmp << '\n';
        }
        t[x] = i;
        c[x] = y;
        ans[x] = y;
        rep(j, 0, mx.size()){
            if(edge[j][x]) ans[mx[j]] = y;
        }
    }


    return 0;
}