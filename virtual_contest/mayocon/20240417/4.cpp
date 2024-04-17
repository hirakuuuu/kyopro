#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define rrep(i, a, n) for(int i = a; i >= n; i--)
#define inr(l, x, r) (l <= x && x < r)
#define ll long long
#define ld long double

// using mint = modint1000000007;
using mint = modint998244353;
constexpr int IINF = 1001001001;
constexpr ll INF = 9e18;

template<class t,class u> void chmax(t&a,u b){if(a<b)a=b;}
template<class t,class u> void chmin(t&a,u b){if(b<a)a=b;}

int main(){
    int n, m; cin >> n >> m;
    vector<int> p(n);
    vector<vector<int>> g(n);
    rep(i, 1, n){
        cin >> p[i];
        p[i]--;
        g[p[i]].push_back(i);
    }
    vector<int> hoken(n, -1);
    rep(i, 0, m){
        int x, y; cin >> x >> y;
        x--;
        chmax(hoken[x], y);
    }
    vector<bool> ok(n);
    auto dfs = [&](auto self, int pos, int y) -> void {
        chmax(y, hoken[pos]);
        if(y >= 0) ok[pos] = true;
        for(auto nxt: g[pos]){
            self(self, nxt, y-1);
        }
    };
    dfs(dfs, 0, hoken[0]);
    int ans = 0;
    rep(i, 0, n) ans += ok[i];
    cout << ans << endl;


    
    return 0;
}