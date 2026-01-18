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

/*
気持ち的には橋がなければ作れそう．
橋がない場合にできそうな構成を考えると，DFS木を取るのが良さそうらしい？
*/

int main(){
    int n, m; cin >> n >> m;
    vector<vector<int>> g(n);
    rep(i, 0, m){
        int u, v; cin >> u >> v; u--, v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    vector<int> bpar(n, -1), ypar(n, -1);
    auto f1 = [&](auto self, int pos) -> void {
        for(auto nxt: g[pos]){
            if(nxt == 0 || bpar[nxt] != -1) continue;
            bpar[nxt] = pos;
            self(self, nxt);
        }
    };
    f1(f1, 0);

    auto f2 = [&](auto self, int pos) -> void {
        for(auto nxt: g[pos]){
            if(nxt == 1 || ypar[nxt] != -1 || bpar[nxt] == pos) continue;
            ypar[nxt] = pos;
            self(self, nxt);
        }
    };
    f2(f2, 1);

    rep(i, 0, n){
        if(i != 1 && ypar[i] == -1){
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;
    cout << ypar[0]+1 << endl;
    cout << bpar[1]+1 << endl;
    rep(i, 2, n){
        cout << bpar[i]+1 << ' ' << ypar[i]+1 << endl;
    }
    return 0;
}