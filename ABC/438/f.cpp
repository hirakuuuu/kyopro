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
        int u, v; cin >> u >> v; 
        g[u].push_back(v);
        g[v].push_back(u);
    }

    ll ans = 0;
    vector<ll> sz(n);
    vector<int> par(n, -1);
    {
        auto f = [&](auto self, int pos, int pre) -> void {
            sz[pos] = 1;
            par[pos] = pre;
            for(auto nxt: g[pos]){
                if(nxt == pre) continue;
                self(self, nxt, pos);
                sz[pos] += sz[nxt];
            }
        };
        f(f, 0, -1);
        ll tot = n;
        ans++; // 0 to 0
        for(auto c: g[0]){
            ans += sz[c]; // to 0;
            ans += sz[c]*(tot-(sz[c]+1)); // path 0;
            tot -= sz[c];
        }
    }

        // cout << ans << endl;


    set<int> path;
    int l = 0, r = 1;
    path.insert(l);
    path.insert(r);
    {
        // 0 - 1 のパスを見つける
        int pos = 1;
        while(par[pos] != 0){
            pos = par[pos];
            path.insert(pos);
        }
        sz[0] = n-sz[pos];
        ans += sz[1]*sz[0];
    }
        // cout << ans << endl;

    rep(i, 2, n){
        if(!path.count(i)){
            int pos = i;
            while(!path.count(pos)){
                path.insert(pos);
                pos = par[pos];
            }
            if(pos == l) l = i;
            else if(pos == r) r = i;
            else break;
        }
        ans += sz[l]*sz[r];
        // cout << l << ' ' << sz[l] << endl;;
        // cout << r << ' ' << sz[r] << endl;;
        // cout << ans << endl;
    }
    cout << ans << endl;


    
    return 0;
}