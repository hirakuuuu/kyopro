#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
const int MOD = 1000000007;
const int mod = 998244353;

// 問題
// https://atcoder.jp/contests/abc209/tasks/abc209_d

vector<vector<int>> g(100005);
vector<int> mark(100005);

void dfs(int pos, int pre=-1, int m=0){
    mark[pos] = m;
    for(auto npos: g[pos]){
        if(npos == pre) continue;
        dfs(npos, pos, 1-m);
    }

}

int main(){
    int n, q; cin >> n >> q;
    rep(i, 0, n-1){
        int a, b; cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    dfs(1);
    while(q--){
        int c, d; cin >> c >> d;
        if(mark[c] == mark[d]) cout << "Town" << endl;
        else cout << "Road" << endl;
    }

    
    return 0;
}