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
    int n, m; cin >> n >> m;
    vector<int> a(n);
    rep(i, 0, n) cin >> a[i];
    vector<vector<int>> g(n);
    rep(i, 0, m){
        int u, v; cin >> u >> v; u--, v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    rep(i, 0, 1<<n){
        bool ok = true;
        rep(j, 0, n){
            int cnt = 0;
            for(auto nj: g[j]){
                if((i>>nj)&1) cnt++;
            }
            if(cnt != a[j]) ok = false;
        }
        if(ok){
            cout << "Yes" << endl;
            rep(j, 0, n){
                if((i>>j)&1) cout << 1 << ' ';
                else cout << 0 << ' ';
            }
            cout << endl;
            return 0;
        }
    }

    cout << "No" << endl;
    
    return 0;
}