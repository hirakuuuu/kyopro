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


int main(){
    int n; cin >> n;
    vector<vector<int>> g(n);

    rep(i, 0, n-1){
        int a, b; cin >> a >> b;
        a--, b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    rep(p, 0, n){
        // 次数 1 の子が2個以上あれば先手必勝
        int cnt = 0;
        for(auto c: g[p]){
            if(g[c].size() == 1) cnt++;
        }
        if(cnt >= 2){
            cout << "First" << endl;
            return 0;
        }
    }

    // 頂点数が偶数だったら後手必勝
    if(n%2 == 0){
        cout << "Second" << endl;
        return 0;
    }

    // 根付き木としてみたときに, 子の部分木の頂点数がすべて偶数だったら先手必勝？
    vector<int> sz(n, 1), par(n, -1);
    auto dfs = [&](auto self, int pos, int pre) -> void {
        for(auto nxt: g[pos]){
            if(nxt == pre) continue;
            self(self, nxt, pos);
            par[nxt] = pos;
            sz[pos] += sz[nxt];
        }
    };
    dfs(dfs, 0, -1);

    rep(p, 0, n){
        bool odd = false;
        for(auto c: g[p]){
            if(par[c] == p) odd |= (sz[c]%2 == 1);
            else odd |= ((n-sz[c]+1)%2 == 1);
        }
        if(odd) continue;
        cout << "First" << endl;
        return 0;
    }
    cout << "Second" << endl;
    
    return 0;
}