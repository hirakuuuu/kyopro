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
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while(t--){
        int n, m; cin >> n >> m;
        vector<vector<int>> g(n);
        rep(i, 0, m){
            int u, v; cin >> u >> v; u--, v--;
            g[u].push_back(v);
            g[v].push_back(u);
        }
        vector<int> par(n, -1), seen(n);
        auto f = [&](auto self, int pos, int pre) -> void {
            seen[pos] = 1;
            for(auto nxt: g[pos]){
                if(nxt == pre) continue;
                if(seen[nxt]) continue;
                par[nxt] = pos;
                self(self, nxt, pos);
            }
            return;
        };
        f(f, 0, -1);

        vector<int> a(n, -1);
        auto f2 = [&](auto self, int pos, int d) -> void {
            a[pos] = d;
            for(auto nxt: g[pos]){
                if(par[nxt] == pos){
                    self(self, nxt, d+1);
                }
            }
            return;
        };

        f2(f2, 0, 0);

        rep(i, 0, n){
            cout << a[i] << ' ';
        }
        cout << endl;


    }
    
    return 0;
}