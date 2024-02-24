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
    int n;cin >> n;
    vector<vector<int>> g(n);
    rep(i, 0, n-1){
        int a, b; cin >> a >> b;
        a--, b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    rep(i, 0, n) sort(g[i].begin(), g[i].end());
    vector<int> ans;
    auto dfs = [&](auto sfs, int pos, int pre) -> void {
        ans.push_back(pos);
        for(auto nxt: g[pos]){
            if(nxt == pre) continue;
            sfs(sfs, nxt, pos);
            ans.push_back(pos);
        }
    };
    dfs(dfs, 0, -1);
    for(auto aa: ans){
        cout << aa+1 << ' ';
    }
    cout << endl;
    
    return 0;
}