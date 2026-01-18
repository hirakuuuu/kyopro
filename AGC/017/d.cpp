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

int main(){
    int n; cin >> n;
    vector<vector<int>> g(n);
    rep(i, 0, n-1){
        int u, v; cin >> u >> v; u--, v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    vector<int> grundy(n);
    auto f = [&](auto self, int pos, int pre) -> void {
        for(auto nxt: g[pos]){
            if(nxt == pre || nxt == 0) continue;
            self(self, nxt, pos);
            grundy[pos] ^= grundy[nxt]+1;
        }
    };
    f(f, 0, -1);
    if(grundy[0]) cout << "Alice" << endl;
    else cout << "Bob" << endl;
    return 0;
}