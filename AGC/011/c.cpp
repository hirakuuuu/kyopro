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


/*
考察はできてたけど，二部グラフのサイズを計算する部分でバグってた
探索を途中で打ち切るとサイズがうまく計算できない

*/

int main(){
    int n, m; cin >> n >> m;
    vector<vector<int>> g(n);
    rep(i, 0, m){
        int u, v; cin >> u >> v;
        u--, v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    vector<int> c(n, -1);
    vector<ll> cnt(3);
    int sz = 0;
    auto check_bipartite = [&](auto self, int pos, int pre, int cur=0) -> bool {
        sz++;
        c[pos] = cur;        
        bool res = true;
        for(auto nxt: g[pos]){
            if(nxt == pre) continue;
            if(c[nxt] != -1){
                if(c[nxt] == c[pos]){
                    res = false;
                }
            }else{
                c[nxt] = 1-c[pos];
                if(!self(self, nxt, pos, 1-cur)) res = false;
            }
        }
        return res;
    };
    rep(i, 0, n){
        if(c[i] != -1) continue; 
        sz = 0;
        bool b = check_bipartite(check_bipartite, i, -1);
        // cout << sz << endl;
        if(b){
            if(sz >= 2) cnt[0]++;
            else cnt[1]++;
        }else{
            cnt[2]++;
        }
    }

    ll ans = 0;
    ans += cnt[1]*n+(n-cnt[1])*cnt[1];
    ans += cnt[0]*cnt[0]*2;
    ans += cnt[0]*cnt[2]*2;
    ans += cnt[2]*cnt[2];
    cout << ans << endl;


    
    return 0;
}