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
// https://atcoder.jp/contests/abc244/tasks/abc244_g

int main(){
    int n, m; cin >> n >> m;
    vector<vector<int>> g(n);
    rep(i, 0, m){
        int u, v; cin >> u >> v;
        u--, v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    string s; cin >> s;
    vector<int> t(n);
    rep(i, 0, n) t[i] = s[i]-'0';
    
    vector<bool> seen(n);
    vector<int> ans;
    auto dfs = [&](auto f, int pos, int pre) -> void {
        seen[pos] = true;
        ans.push_back(pos); t[pos] ^= 1;
        for(auto nxt: g[pos]){
            if(seen[nxt]) continue;
            f(f, nxt, pos);
            ans.push_back(pos); t[pos] ^= 1;
        }
        if(pre != -1 && t[pos]){
            ans.push_back(pre); t[pre] ^= 1;
            ans.push_back(pos); t[pos] ^= 1;
        }
    };
    dfs(dfs, 0, -1);
    if(t[0]){
        ans.push_back(g[0][0]);
        ans.push_back(0); t[0] ^= 1;
        ans.push_back(g[0][0]);
    }
    bool ok = true;
    rep(i, 0, n) ok &= (t[i] == 0);
    if(ok){
        cout << ans.size() << endl;
        for(auto aa: ans){
            cout << aa+1 << ' ';
        }
        cout << endl;
    }
    return 0;
}