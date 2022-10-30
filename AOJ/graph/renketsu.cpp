#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
const int MOD = 1000000007;
const int mod = 998244353;


/*
隣接リスト表現の長所
・辺の数に比例したメモリしか必要としない
隣接リスト表現の短所
・頂点同士の関係を調べるには、O(n)でリストを探索しなければならないが、
　DFSやBFSでは頂点を一度ずつ順番たどれば十分な場合が多いため、あまり問題にはならない
・辺の削除が難しい
*/
vector<vector<int>> g(100005);
vector<int> c(100005, 0);

// 連結であるかどうかは１回探索すればわかる
void dfs(int pos, int cnt){
    c[pos] = cnt;
    for(auto npos: g[pos]){
        if(c[npos] == 0) dfs(npos, cnt);
    }
}


int main(){
    int n, m; cin >> n >> m;
    rep(i, 0, m){
        int u, v; cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    int cnt = 1;
    rep(i, 0, n){
        if(c[i]) continue;
        else{
            dfs(i, cnt);
            cnt++;
        }
    }
    int q; cin >> q;
    vector<bool> ans;
    while(q--){
        int u, v; cin >> u >> v;
        ans.push_back(c[u] == c[v]);
    }
    for(auto aa: ans){
        if(aa) cout << "yes" << endl;
        else cout << "no" << endl;
    }

}