#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
const int MOD = 1000000007;
const int mod = 998244353;

/*
https://atcoder.jp/contests/abc126/tasks/abc126_d
偶数コストの辺でつながっている場合は同じ色
そうでなければ違う色でつなぐようにｄｆｓすれば良い
*/

vector<vector<pii>> g(100005);
vector<int> color(100005);
void dfs(int pos, int pre, int c){
    color[pos] = c;
    for(auto npos: g[pos]){
        if(npos.first == pre) continue;
        if(npos.second%2) dfs(npos.first, pos, (c+1)%2);
        else dfs(npos.first, pos, c);
    }
}

int main(){
    int n; cin >> n;
    rep(i, 0, n-1){
        int u, v, w; cin >> u >> v >> w;
        g[u].push_back(make_pair(v, w));
        g[v].push_back(make_pair(u, w));
    }

    dfs(1, -1, 0);
    rep(i, 1, n+1){
        cout << color[i] << endl;
    }
}