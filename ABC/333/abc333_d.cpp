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
// https://atcoder.jp/contests/abc333/tasks/abc333_d

void dfs(vector<vector<int>> &g, vector<int> &cnt, int pos, int pre){
    cnt[pos] = 1;
    for(auto npos: g[pos]){
        if(npos == pre) continue;
        dfs(g, cnt, npos, pos);
        cnt[pos] += cnt[npos];
    }
}

int main(){
    int n; cin >> n;
    vector<vector<int>> g(n);
    rep(i, 0, n-1){
        int u, v; cin >> u >> v;
        u--, v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    vector<int> cnt(n);
    dfs(g, cnt, 0, -1);
    int mx = 0;
    for(auto ng: g[0]){
        chmax(mx, cnt[ng]);
    }

    cout << n-mx << endl;


    
    return 0;
}
