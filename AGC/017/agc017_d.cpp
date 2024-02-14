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
// https://atcoder.jp/contests/agc017/tasks/agc017_d

int main(){
    int n; cin >> n;
    vector<vector<int>> g(n);
    rep(i, 0, n-1){
        int u, v; cin >> u >> v;
        u--, v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    vector<int> grandy(n);
    auto dfs = [&](auto sfs, int pos, int pre)->void {
        grandy[pos] = 0;
        for(auto nxt: g[pos]){
            if(nxt == pre) continue;
            sfs(sfs, nxt, pos);
            grandy[pos] ^= (grandy[nxt]+1);
        }
    };

    dfs(dfs, 0, -1);
    if(grandy[0]) cout << "Alice" << endl;
    else cout << "Bob" << endl;

    
    return 0;
}