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
constexpr ll INF = 9e18;

template<class t,class u> void chmax(t&a,u b){if(a<b)a=b;}
template<class t,class u> void chmin(t&a,u b){if(b<a)a=b;}

int main(){
    int n, k; cin >> n >> k;
    vector<vector<int>> g(n);
    rep(i, 0, n-1){
        int a, b; cin >> a >> b;
        a--, b--;
        g[a].push_back(b);
        g[b].push_back(a);
    } 
    vector<int> V(k);
    vector<int> v(n);
    rep(i, 0, k){
        cin >> V[i];
        V[i]--;
        v[V[i]]++;
    }
    vector<int> cnt(n);
    auto dfs1 = [&](auto self, int pos, int pre) -> void {
        cnt[pos] += v[pos];
        for(auto nxt: g[pos]){
            if(nxt == pre) continue;
            self(self, nxt, pos);
            cnt[pos] += cnt[nxt];
        }
    };
    dfs1(dfs1, V[0], -1);
    vector<int> need(n);
    auto dfs2 = [&](auto self, int pos, int pre) -> void {
        need[pos] = 1;
        for(auto nxt: g[pos]){
            if(nxt == pre) continue;
            if(cnt[nxt] == 0) continue;
            self(self, nxt, pos);
        }
    };
    dfs2(dfs2, V[0], -1);
    
    int ans = 0;
    rep(i, 0, n) ans += need[i];
    cout << ans << endl;
    return 0;
}