#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
const int MOD = 1000000007;
const int mod = 998244353;

template<class t,class u> void chmax(t&a,u b){if(a<b)a=b;}
template<class t,class u> void chmin(t&a,u b){if(b<a)a=b;}

// 問題
// https://atcoder.jp/contests/abc220/tasks/abc220_f

vector<vector<int>> g(200005);
vector<ll> sub(200005), ans(200005);

void dfs(int pos, int pre){
    sub[pos] = 1;
    for(const auto &npos: g[pos]){
        if(npos == pre) continue;
        dfs(npos, pos);
        sub[pos] += sub[npos];
    }
}

vector<ll> dist(200005);
void dfs2(int pos, int pre){
    for(const auto &npos: g[pos]){
        if(npos == pre) continue;
        dist[npos] = dist[pos]+1;
        dfs2(npos, pos);
    }
}

void dfs3(int pos, int pre, int n){
    for(const auto &npos: g[pos]){
        if(npos == pre) continue;
        ans[npos] = ans[pos]+n-2*sub[npos];
        dfs3(npos, pos, n);
    }
}





int main(){
    int n; cin >> n;
    rep(i, 0, n-1){
        int u, v; cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    dfs(1, 0);
    dfs2(1, 0);
    rep(i, 1, n+1) ans[1] += dist[i];

    dfs3(1, 0, n);
    rep(i, 1, n+1){
        cout << ans[i] << endl;
    }



    
    return 0;
}