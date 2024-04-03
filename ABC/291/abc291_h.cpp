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
// https://atcoder.jp/contests/abc291/tasks/abc291_h

int main(){
    int n; cin >> n;
    vector<vector<int>> g(n);
    rep(i, 0, n-1){
        int a, b;cin >> a >> b;
        a--, b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    
    vector<int> sz(n);
    auto Centroid = [&](int r) -> int {
        int center = -1;
        auto dfs = [&](auto self, int u, int prev) -> void {
            sz[u] = 1;
            bool is_centroid = true;
            for (auto v : g[u]) if (v != prev) {
                self(self, v, u);
                sz[u] += sz[v];
                if (sz[v] > n / 2) is_centroid = false;
            }
            if (n - sz[u] > n / 2) is_centroid = false;
            if (is_centroid) center = u;
        };
        dfs(dfs, r, -1);
        return center;
    };
    cout << Centroid(0) << endl;

    vector<int> ans(n);

    return 0;
}