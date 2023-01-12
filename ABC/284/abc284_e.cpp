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
// https://atcoder.jp/contests/abc284/tasks/abc284_e

vector<vector<int>> g(200005);
vector<int> seen(200005);
ll ans = 1;

void f(int pos, int pre, ll &ans){
    if(ans == 1000000){
        return;
    }
    seen[pos] = 1;
    for(const auto &npos: g[pos]){
        if(seen[npos]) continue;
        ans++;
        f(npos, pos, ans);
        if(ans == 1000000) return;
    }
    seen[pos] = 0;

}

int main(){
    int n, m; cin >> n >> m;
    rep(i, 0, m){
        int u, v; cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    f(1, 0, ans);
    cout << ans << endl;

    return 0;
}