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
    int sm = (int)sqrt(m);
    vector<vector<int>> g(n);
    rep(i, 0, m){
        int u, v; cin >> u >> v;
        u--, v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    vector<vector<int>> g_s(n), g_b(n);
    rep(i, 0, n){
        for(auto v: g[i]){
            if(g[v].size() < sm) g_s[i].push_back(v);
            else g_b[i].push_back(v);
        }
    }

    vector<pair<int, int>> k(n, {-1, 0}), c(n);
    rep(i, 0, n) c[i] = {i, 0};
    rep(i, 1, q+1){
        int x; cin >> x;
        x--;
        for(auto v: g_b[x]){
            if(k[v].first == -1) continue;
            if(k[v].second > c[x].second) c[x] = k[v];
        }
        if(g[x].size() < sm){
            for(auto v: g[x]){
                c[v] = {c[x].first, i};
            }
        }else{
            k[x] = {c[x].first, i};
        }
    }
    rep(i, 0, n){
        for(auto v: g_b[i]){
            if(k[v].first == -1) continue;
            if(k[v].second > c[i].second) c[i] = k[v];
        }
    }
    rep(i, 0, n) cout << c[i].first+1 << ' ';
    cout << endl;
    return 0;
}