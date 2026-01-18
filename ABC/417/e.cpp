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
    int t; cin >> t;
    while(t--){
        int n, m; cin >> n >> m;
        int x, y; cin >> x >> y; x--, y--;
        vector<vector<int>> g(n);
        rep(i, 0, m){
            int u, v; cin >> u >> v; u--, v--;
            g[u].push_back(v);
            g[v].push_back(u);
        }
        rep(i, 0, n){
            sort(g[i].begin(), g[i].end());
        }

        vector<bool> seen(n);
        vector<int> par(n, -1);
        auto f = [&](auto self, int pos, int pre) -> void {
            for(auto nxt: g[pos]){
                if(nxt == pre) continue;
                if(seen[nxt]) continue;
                par[nxt] = pos;
                seen[nxt] = true;
                self(self, nxt, pos);
            }
        };
        seen[x] = true;
        f(f, x, -1);
        vector<int> ans;
        int pos = y;
        while(pos != -1){
            ans.push_back(pos);
            pos = par[pos];
        }
        reverse(ans.begin(), ans.end());
        for(auto aa: ans){
            cout << aa+1 << ' ';
        }
        cout << endl;
    }
    return 0;
}