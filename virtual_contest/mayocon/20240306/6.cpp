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
    int n; cin >> n;
    vector<vector<int>> g(n);
    rep(i, 0, n-1){
        int u, v; cin >> u >> v;
        u--, v--;
        if(u > v) swap(u, v);
        g[u].push_back(v);
    }
    ll ans = 0;
    rep(i, 1, n+1) ans += (ll)i*(i+1)/2;
    rep(i, 0, n){
        rep(j, 0, g[i].size()){
            int u = i, v = g[i][j];
            ans -= (ll)(u+1)*(n-v);
        }
    }
    cout << ans << endl;
    
    return 0;
}