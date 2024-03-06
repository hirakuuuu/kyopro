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
// 

int main(){
    int n, m, q; cin >> n >> m >> q;
    vector<vector<int>> g(n);
    rep(i, 0, m){
        int u, v; cin >> u >> v;
        u--, v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    vector<int> c(n);
    iota(c.begin(), c.end(), 0);
    vector<int> x(q);
    rep(i, 0, q){
        cin >> x[i];
        x[i]--;
    }
    vector<int> seen(n);
    vector<int> x_;
    rep(i, 0, q){
        if(seen[x[i]]) continue;
        seen[x[i]] = 1;
        x_.push_back(x[i]);
    }

    for(auto xx: x_){
        for(auto ch: g[xx]){
            c[ch] = c[xx];
        }
    }
    rep(i, 0, n){
        cout << c[i]+1 << ' ';
    }
    cout << endl;
    
    return 0;
}