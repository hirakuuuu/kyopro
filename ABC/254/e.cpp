#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
const int MOD = 1000000007;
const int mod = 998244353;

// 問題
// https://atcoder.jp/contests/abc254/tasks/abc254_e3

vector<vector<int>> g(150005);
vector<int> tonari(150005, 0);


void dfs(int k, int pos, int pre, set<int> &kind){
    kind.insert(pos);
    if(k == 0) return;
    for(auto npos: g[pos]){
        if(npos == pre) continue;
        kind.insert(npos);
        dfs(k-1, npos, pos, kind);
    }
}

int main(){
    int n, m; cin >> n >> m;
    rep(i, 0, m){
        int a, b; cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    int q; cin >> q;
    while(q--){
        int x, k; cin >> x >> k;
        int sum = 0;
        set<int> kind;
        dfs(k, x, 0, kind);
        for(auto itr = kind.begin(); itr != kind.end(); ++itr){
            sum += *itr;
        }
        cout << sum << endl;
    }
    
    return 0;
}