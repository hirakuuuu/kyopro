#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define rrep(i, a, n) for(int i = a; i >= n; i--)
#define inr(l, x, r) (l <= x && x < r)
#define ll long long
#define ld long double
#define pii pair<int, int>
#define pll pair<ll, ll>
// constexpr ll MOD = 1000000007;
constexpr ll MOD = 998244353;
constexpr int IINF = 1001001001;
constexpr ll INF = 9e18;

template<class t,class u> void chmax(t&a,u b){if(a<b)a=b;}
template<class t,class u> void chmin(t&a,u b){if(b<a)a=b;}

ll power(ll a, ll b, ll m=MOD){
    ll res = 1;
    while(b > 0){
        if(b%2 == 1) res = res*a%m;
        a = a*a%m;
        b /= 2;
    }
    return res;
}

int main(){
    int n; cin >> n; 
    vector<vector<pair<int, int>>> g(n);
    rep(i, 0, n-1){
        int u, v, w; cin >> u >> v >> w;
        u--, v--;
        w &= 1;
        g[u].push_back({v, w});
        g[v].push_back({u, w});
    }
    vector<int> c(n);
    c[0] = 0;
    auto dfs = [&](auto self, int pos, int pre) -> void {
        for(auto [nxt, w]: g[pos]){
            if(nxt == pre) continue;
            if(w == 0) c[nxt] = c[pos];
            else c[nxt] = 1-c[pos];
            self(self, nxt, pos);
        }
    };
    dfs(dfs, 0, -1);
    rep(i, 0, n){
        cout << c[i] << endl;
    }

    return 0;
}